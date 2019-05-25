#include "qmidimetaevent.h"

/*************************************************************
 * METAEVENTOS MIDI
 * ***********************************************************/

QMidiMetaEvent::QMidiMetaEvent()
{

}

QMidiMetaEvent::QMidiMetaEvent(ulong deltatime,uchar *eventData,uint dataLongitud):
    QMidiMessage (deltatime,eventData,dataLongitud)
{

}

const QMidiMetaEvent& QMidiMetaEvent::operator=(const QMidiMetaEvent&noev)
{
    if (this == &noev)
    {
        return *this;
    }
    QMidiMessage::operator=(noev);
    return *this;
   }

QMidiMetaEvent::~QMidiMetaEvent()
{

}
