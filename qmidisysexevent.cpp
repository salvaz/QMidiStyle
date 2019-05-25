#include "qmidisysexevent.h"

/*************************************************************
 * METAEVENTOS MIDI
 * ***********************************************************/

QMidiSysExEvent::QMidiSysExEvent()
{

}

QMidiSysExEvent::QMidiSysExEvent(ulong deltatime,uchar *eventData,uint dataLongitud):
    QMidiMessage (deltatime,eventData,dataLongitud)
{

}

const QMidiSysExEvent& QMidiSysExEvent::operator=(const QMidiSysExEvent&noev)
{
    if (this == &noev)
    {
        return *this;
    }
    QMidiMessage::operator=(noev);
    return *this;
   }

QMidiSysExEvent::~QMidiSysExEvent()
{

}
