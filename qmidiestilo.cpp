#include "qmidiestilo.h"

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

unsigned long QMidiEstilo::ByteArrayToULong (QByteArray data)
{
    unsigned long valor;

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

    MiFile->close();
    return true;

}
