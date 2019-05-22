#include "qmidimessage.h"

QMidiMessage::QMidiMessage()
{
    Tipo=HP_TYPE_NONE;
    TiempoAbsoluto=0;
    event_data=nullptr;
    event_data_length=-1;
    Canal=HP_NO_CHAN;
    Elegido=0;
}

QMidiMessage::QMidiMessage(int MiTiempoAbsoluto,unsigned char* Mi_event_data,int Mi_event_data_length)
{
    TiempoAbsoluto=MiTiempoAbsoluto;
    event_data_length=Mi_event_data_length;
    event_data=new unsigned char[static_cast<unsigned int>(event_data_length)];
    for (int kk=0;kk<event_data_length;kk++)
    {
        event_data[kk]=Mi_event_data[kk];
    }
    Canal=HP_NO_CHAN;
    Elegido=0;
}

const QMidiMessage& QMidiMessage::operator= (const QMidiMessage& mev)
{
    if (this == &mev)
    {
        return *this;
    }

    Tipo = mev.Tipo;
    TiempoAbsoluto=mev.TiempoAbsoluto;
    event_data_length=mev.event_data_length;
    event_data=new unsigned char[static_cast<unsigned int>(event_data_length)];
    for (int kk=0;kk<event_data_length;kk++)
    {
        event_data[kk]=mev.event_data[kk];
    }
    Canal=mev.Canal;
    Elegido=mev.Elegido;
    return *this;
}

QMidiMessage::~QMidiMessage()
{
    delete[] event_data;
}

void QMidiMessage::CambiarCanal(int canal)
{
    if (Canal == HP_NO_CHAN) return;
    Canal = canal;
    event_data[0] &= 0xf0;
    event_data[0] |= (Canal & 0x0f);
}

unsigned int QMidiMessage::Sub1Type()
{
    return(Tipo & 0xff);
}

unsigned int QMidiMessage::Sub2Type()
{
    return((Tipo>>8) & 0xff);
}

unsigned int QMidiMessage::Sub3Type()
{
    return((Tipo>>16) & 0xff);
}
