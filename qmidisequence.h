#ifndef QMIDISEQUENCE_H
#define QMIDISEQUENCE_H

#include "qmiditrack.h"

class QMidiSequence
{
public:
    QMidiSequence();
    ~QMidiSequence();
    void AddTrack(QMidiTrack &MiTrack);
    void SetNombre(QString name);
    QString GetNombre (void);
    QList <QMidiTrack> ListaTrack;
protected:
    QString Nombre;
};

#endif // QMIDISEQUENCE_H
