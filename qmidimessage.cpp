#include "qmidimessage.h"

QMidiMessage::QMidiMessage()
{
    Tipo=QMIDI_TIPO_NOEVENT;
    TiempoAbsoluto=0;
    event_data=nullptr;
    event_data_length=0;
    Canal=QMIDI_NO_CANAL;
    Elegido=0;
}

QMidiMessage::QMidiMessage(ulong MiTiempoAbsoluto,uchar *Mi_event_data, uint Mi_event_data_length)
{
    Tipo=QMIDI_TIPO_NORMALEVENT;
    TiempoAbsoluto=MiTiempoAbsoluto;
    event_data_length=Mi_event_data_length;
    for (uint kk=0;kk<event_data_length;kk++)
    {
        event_data[kk]=static_cast<char>(Mi_event_data[kk]);
    }
    Canal=QMIDI_NO_CANAL;
    Elegido=0;
}

const QMidiMessage& QMidiMessage::operator= (const QMidiMessage& mev)
{
    if (this == &mev)
    {
        return *this;
    }

    Tipo=mev.Tipo;
    TiempoAbsoluto=mev.TiempoAbsoluto;
    event_data_length=mev.event_data_length;
    for (uint kk=0;kk<event_data_length;kk++)
    {
        event_data[kk]=mev.event_data[kk];
    }
    Canal=mev.Canal;
    Elegido=mev.Elegido;
    return *this;
}

QMidiMessage::~QMidiMessage()
{
}

void QMidiMessage::CambiarCanal(uint canal)
{
    Canal = canal;
    event_data[0] = event_data[0] & char(0xf0);
    event_data[0] = event_data[0] | char(Canal & 0x0f);
}

uint QMidiMessage::Sub1Type()
{
    return(Tipo & 0xff);
}

uint QMidiMessage::Sub2Type()
{
    return((Tipo>>8) & 0xff);
}

uint QMidiMessage::Sub3Type()
{
    return((Tipo>>16) & 0xff);
}

QString QMidiMessage::getNombre()
{
    QString nombre;

    return nombre;
}
