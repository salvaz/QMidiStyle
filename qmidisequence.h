#ifndef QMIDISEQUENCE_H
#define QMIDISEQUENCE_H

#include "qmiditrack.h"

class QMidiSequence
{
public:
    QMidiSequence();
protected:
    QList <QMidiTrack> ListaTrack;
};

#endif // QMIDISEQUENCE_H
