#include "qmidisequence.h"

QMidiSequence::QMidiSequence()
{

}

QMidiSequence::~QMidiSequence()
{
    ListaTrack.clear();
}

void QMidiSequence::AddTrack(QMidiTrack &MiTrack)
{
    ListaTrack.append(MiTrack);
}

void QMidiSequence::SetNombre(QString name)
{
    Nombre=name;
}

QString QMidiSequence::GetNombre()
{
    return Nombre;
}
