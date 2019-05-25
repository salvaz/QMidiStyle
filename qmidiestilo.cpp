#include "qmidiestilo.h"
#include "qmidievent.h"
#include "qmidimetaevent.h"
#include "qmidisysexevent.h"

QMidiEstilo::QMidiEstilo()
{
}

QMidiEstilo::~QMidiEstilo()
{
    ListaVariaciones.clear();
}

void QMidiEstilo::AddMidiSequence(QMidiSequence MiSecuencia)
{
    ListaVariaciones.append(MiSecuencia);
}

ulong QMidiEstilo::ByteArrayToULong(QByteArray data)
{
    ulong valor;

    valor=static_cast<unsigned long>(data[0] << 24) + static_cast<unsigned long>(data[1] << 16) +
                      static_cast<unsigned long>(data[2] << 8) + static_cast<unsigned long>(data[3]);

    return valor;
}

bool QMidiEstilo::ImportarEstiloPSR(QString filename)
{
    QString MiString;
    QFile *MiFile;
    QByteArray MiBufer;
    quint16 FileFormat,NTrack,TicksQuarter;
    quint32 largo,largoTrack;
    uchar *MisDatos;
    QMidiSequence miSecuencia;
    QMidiTrack miTrack;


    MiFile=new QFile(filename);
    if (!MiFile->exists())
    {
        return false;
    }
    MiFile->open(QIODevice::ReadOnly);
    QDataStream MiData(MiFile);
    MiData.setByteOrder(QDataStream::BigEndian);
// MThd
    MiBufer=MiFile->read(4);
    MiString=QString::fromUtf8(MiBufer);
    if (MiString!="MThd")
    {
        MiFile->close();
        return  false;
    }
// Longitud de cabecera debe ser 6
    MiData >> largo;
// File format, nº track y ticks/Quarter
    MiData >> FileFormat;
    MiData >> NTrack;
    MiData >> TicksQuarter;
    for (int kk=0;kk<NTrack;kk++)
    {
// MTrk
        MiBufer=MiFile->read(4);
        MiString=QString::fromUtf8(MiBufer);
        if (MiString!="MTrk")
        {
            MiFile->close();
            return  false;
        }
// longitud del track
        MiData >> largoTrack;

        MiBufer=MiFile->read(largoTrack);
        if (!(MiFile->error()==QFileDevice::NoError))
        {
            MiFile->close();
            return  false;
        }
        MisDatos=reinterpret_cast<uchar *>(MiBufer.data());
        miTrack=LeerTrackFromData(MisDatos,largoTrack);
        miSecuencia.AddTrack(miTrack);
    }
    ListaVariaciones.append(miSecuencia);
    MiFile->close();
    return true;
}

ulong QMidiEstilo::ConvertVarLenToLong(uchar *bufer)
{
        int i = 0;
        ulong value;
        uchar c;

        value =static_cast<ulong>(bufer[i]);
        if ((value & 0x80) != 0)
        {
            value &= 0x7f;
            do
            {
                i++;
                c = static_cast<uchar>(bufer[i]);
                value = (value<<7) + (c & 0x7f);
            } while ((c & 0x80) != 0);
        }
        return value;
}

ulong QMidiEstilo::ConvertVarLenToLong2 (uchar *bufer,uint &bytesLeidos)
{
    ulong var = 0;
    uchar c;

    bytesLeidos = 0;

    do
    {
        c = bufer[(bytesLeidos)++];
        var = (var << 7) + (c & 0x7f);
    }
    while(c & 0x80);

    return var;
}

uint QMidiEstilo::LeerTrackEvent (ulong TiempoTotal, uchar *data, QMidiTrack &miTrack)
{
    uint LongitudTotal;
    uchar Tipo;

    Tipo=data[0] & 0xF0;
    if (Tipo==0xC0 || Tipo==0xD0)
    {
        LongitudTotal=2;
    }
    else {
        LongitudTotal=3;
    }
    QMidiNormalEvent miEvent(TiempoTotal,data,LongitudTotal);
    miTrack.AddEvento(miEvent);
    return LongitudTotal;
}

uint QMidiEstilo::LeerTrackMetaEvent (ulong TiempoTotal,uchar *data,QMidiTrack &miTrack)
{
    uchar Tipo;
    uint Longitud,LongitudTotal;
    ulong bytesdata;

    Tipo=data[1];
    bytesdata=ConvertVarLenToLong2(data+2,Longitud);
    LongitudTotal=2+Longitud+bytesdata;
    QMidiMetaEvent miMeta(TiempoTotal,data,LongitudTotal);
    miTrack.AddEvento(miMeta);
    return LongitudTotal;
}

uint QMidiEstilo::LeerTrackSysExEvent (ulong TiempoTotal,uchar *data,QMidiTrack &miTrack)
{
    uchar Tipo;
    uint Longitud,LongitudTotal;
    ulong bytesdata;

    Tipo=data[0];
    bytesdata=ConvertVarLenToLong2(data+1,Longitud);
    LongitudTotal=1+Longitud+bytesdata;
    QMidiSysExEvent miSysEx(TiempoTotal,data,LongitudTotal);
    miTrack.AddEvento(miSysEx);
    return LongitudTotal;
}

QMidiTrack QMidiEstilo::LeerTrackFromData (uchar *data,ulong longitud)
{
    QMidiTrack miTrack;
    ulong DeltaTime;
    uint bytesleidos,TotalBytesEvent,TotalBytes;
    ulong TiempoTotal=0;

    TotalBytes=0;
    while (TotalBytes<longitud) {
        TotalBytesEvent=0;
// DeltaTime
        DeltaTime=ConvertVarLenToLong2(data,bytesleidos);
        TiempoTotal+=DeltaTime;
        data+=bytesleidos;
        TotalBytesEvent+=bytesleidos;
// Event ID
        if (data[0]==0xff)
        {
            bytesleidos=LeerTrackMetaEvent(TiempoTotal,data,miTrack);
        }
        else if (data[0]==0xf0) {
            bytesleidos=LeerTrackSysExEvent(TiempoTotal,data,miTrack);
        }
        else {
            bytesleidos=LeerTrackEvent(TiempoTotal,data,miTrack);
        }
        data+=bytesleidos;
        TotalBytesEvent+=bytesleidos;
        TotalBytes+=TotalBytesEvent;
        }
        return miTrack;
    }

void QMidiEstilo::setNombre(QString name)
{
    Nombre=name;
}

QString QMidiEstilo::getNombre()
{
    return Nombre;
}
