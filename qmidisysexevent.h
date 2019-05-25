#ifndef QMIDISYSEXEVENT_H
#define QMIDISYSEXEVENT_H

#include "qmidimessage.h"

class QMidiSysExEvent:public QMidiMessage
{
public:
    QMidiSysExEvent();
    QMidiSysExEvent(ulong deltatime, uchar *eventData, uint dataLongitud);
    const QMidiSysExEvent& operator=(const QMidiSysExEvent&noev);
    virtual ~QMidiSysExEvent();
};

#endif // QMIDISYSEXEVENT_H
