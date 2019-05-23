#ifndef QMIDITRACK_H
#define QMIDITRACK_H

#include <QList>
#include "qmidievent.h"

class QMidiTrack
{
public:
    QMidiTrack();
    ~QMidiTrack();
    void AddEvento(QMidiMessage MiEvento);
    void SetNombre(QString name);
    QString GetNombre(void);
    void OrdenarEventos (void);
private:
    QString Nombre;
    QList <QMidiMessage> ListaEventos;
};

#endif // QMIDITRACK_H
