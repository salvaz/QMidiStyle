#include "qmidievent.h"

/**************************************************************
 * NOTE OFF Evento
 * ***********************************************************/

NoteOffEvent::NoteOffEvent():QMidiMessage ()
{
    Tipo = HP_NOTE_OFF;
    Canal = HP_NO_CHAN;
}

NoteOffEvent::NoteOffEvent(int resulting_time,unsigned char* event_data, int event_data_length)
    :QMidiMessage(resulting_time,event_data,event_data_length)
{
    Tipo = HP_NOTE_OFF;
    Canal = event_data[0] & 0x0f;

    // convert to note on with velocity 0
    event_data[0] = 0x90 | static_cast<unsigned char>(Canal);
    event_data[2] = 0x00;
}

const NoteOffEvent& NoteOffEvent::operator= (const NoteOffEvent& noev)
{
    if (this == &noev)
    {
        return *this;
    }

    QMidiMessage::operator=(noev);

    AsociadaNoteOn=nullptr; // filled later

    return *this;
}

NoteOffEvent::~NoteOffEvent()
{

}

int NoteOffEvent::Nota()
{
    return event_data[1] &0x7f;
}

void NoteOffEvent::setNota(int new_note)
{
    event_data[1] = new_note &0x7f;
}

void NoteOffEvent::setCanal(int new_chan)
{
    event_data[0] = (event_data[0]&0xf0)|(new_chan&0x0f);
}

/**************************************************************
 * NOTE ON Evento
 * ***********************************************************/

NoteOnEvent::NoteOnEvent():QMidiMessage()
{
    Tipo = HP_NOTE_ON;
    Canal = HP_NO_CHAN;
}

NoteOnEvent::NoteOnEvent(int resulting_time,unsigned char* event_data, int event_data_length)
    :QMidiMessage (resulting_time,event_data,event_data_length)
{
    Tipo = HP_NOTE_ON;
    Canal = event_data[0] & 0x0f;
}

const NoteOnEvent& NoteOnEvent::operator= (const NoteOnEvent& noev)
{
    if (this == &noev)
    {
        return *this;
    }
    QMidiMessage::operator=(noev);
    AsociadaNotaOff=nullptr; // filled later

    return *this;
}

NoteOnEvent::~NoteOnEvent()
{

}

int NoteOnEvent::Nota()
{
    return event_data[1] &0x7f;
}

void NoteOnEvent::setNota(int new_note)
{
    event_data[1] = new_note &0x7f;
}

void NoteOnEvent::setCanal(int new_chan)
{
    event_data[0] = (event_data[0]&0xf0)|(new_chan&0x0f);
}

int NoteOnEvent::Velocidad()
{
    return event_data[2];
}

void NoteOnEvent::setVelocidad(int vel)
{
    event_data[2] = vel&0x7f;
}
