#ifndef QMIDIMETAEVENT_H
#define QMIDIMETAEVENT_H


#include "qmidimessage.h"

class QMidiMetaEvent:public QMidiMessage
{
public:
    QMidiMetaEvent();
    QMidiMetaEvent(ulong deltatime, uchar *eventData, uint dataLongitud);
    const QMidiMetaEvent& operator=(const QMidiMetaEvent&noev);
    virtual ~QMidiMetaEvent();
};

#endif // QMIDIMETAEVENT_H
