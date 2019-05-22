#ifndef QMIDITRACK_H
#define QMIDITRACK_H

#include <QList>
#include "qmidievent.h"

class QMidiTrack
{
public:
    QMidiTrack();
    void OrdenarEventos (void);
private:
    QString Nombre;
    QList <QMidiMessage> ListaEventos;
};

#endif // QMIDITRACK_H
