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
protected:
    QList <QMidiSequence> ListaVariaciones;
    unsigned long ByteArrayToULong (QByteArray data);

};

#endif // QMIDIESTILO_H
