#ifndef QMIDIEVENT_H
#define QMIDIEVENT_H

#include "qmidimessage.h"

class QMidiNormalEvent:public QMidiMessage
{
public:
    QMidiNormalEvent();
    QMidiNormalEvent(ulong deltatime, uchar *eventData, uint dataLongitud);
    const QMidiNormalEvent& operator=(const QMidiNormalEvent&noev);
    virtual ~QMidiNormalEvent();
};

#endif // QMIDIEVENT_H
