#include "qmiditrack.h"

QMidiTrack::QMidiTrack()
{

}

void QMidiTrack::OrdenarEventos(void)
{
    std::sort(ListaEventos.begin(),ListaEventos.end(),
              [](const QMidiMessage& a, const QMidiMessage& b)->bool{return a.TiempoAbsoluto < b.TiempoAbsoluto;});
}
