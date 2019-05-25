#include "qmidievent.h"

/*************************************************************
 * EVENTOS MIDI NORMALES
 * ***********************************************************/

QMidiNormalEvent::QMidiNormalEvent()
{

}

QMidiNormalEvent::QMidiNormalEvent(ulong deltatime, uchar *eventData, uint dataLongitud):
    QMidiMessage (deltatime,eventData,dataLongitud)
{
    Tipo=static_cast<ulong>(0x01 + ((eventData[0] & 0xF0) << 8));
}

const QMidiNormalEvent& QMidiNormalEvent::operator=(const QMidiNormalEvent&noev)
{
    if (this == &noev)
    {
        return *this;
    }
    QMidiMessage::operator=(noev);
    return *this;
   }

QMidiNormalEvent::~QMidiNormalEvent()
{

}
