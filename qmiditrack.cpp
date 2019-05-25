#include "qmiditrack.h"

QMidiTrack::QMidiTrack()
{

}

QMidiTrack::~QMidiTrack()
{
    ListaEventos.clear();
}

void QMidiTrack::AddEvento(QMidiMessage &MiEvento)
{
    ListaEventos.append(MiEvento);
}

void QMidiTrack::OrdenarEventos(void)
{
    std::sort(ListaEventos.begin(),ListaEventos.end(),
              [](const QMidiMessage& a, const QMidiMessage& b)->bool{return a.TiempoAbsoluto < b.TiempoAbsoluto;});
}

void QMidiTrack::SetNombre(QString name)
{
    Nombre=name;
}

QString QMidiTrack::GetNombre()
{
    return Nombre;
}
