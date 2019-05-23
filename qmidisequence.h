#ifndef QMIDISEQUENCE_H
#define QMIDISEQUENCE_H

#include "qmiditrack.h"

class QMidiSequence
{
public:
    QMidiSequence();
    ~QMidiSequence();
    void AddTrack(QMidiTrack MiTrack);
    void SetNombre(QString name);
    QString GetNombre (void);
protected:
    QList <QMidiTrack> ListaTrack;
    QString Nombre;
};

#endif // QMIDISEQUENCE_H
