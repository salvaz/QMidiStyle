#ifndef QMIDIESTILO_H
#define QMIDIESTILO_H

#include "qmidisequence.h"

class QMidiEstilo
{
public:
    QMidiEstilo();
    ~QMidiEstilo();
    void AddMidiSequence (QMidiSequence MiSecuencia);
    bool ImportarEstiloPSR (QString filename);
    QString getNombre(void);
    void setNombre(QString name);
    QList <QMidiSequence> ListaVariaciones;
protected:
    QString Nombre;
    QMidiTrack LeerTrackFromData (uchar *data,ulong longitud);
    uint LeerTrackEvent(ulong TiempoTotal,uchar *data,QMidiTrack &miTrack);
    uint LeerTrackMetaEvent (ulong TiempoTotal, uchar *data, QMidiTrack &miTrack);
    uint LeerTrackSysExEvent (ulong TiempoTotal,uchar *data,QMidiTrack &miTrack);
    ulong ByteArrayToULong (QByteArray data);
    ulong ConvertVarLenToLong (uchar *bufer);
    ulong ConvertVarLenToLong2 (uchar *bufer,uint &bytesLeidos);

};

#endif // QMIDIESTILO_H
