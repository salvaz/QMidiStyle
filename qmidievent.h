#ifndef QMIDIEVENT_H
#define QMIDIEVENT_H

#include "qmidimessage.h"

class NoteOffEvent : public QMidiMessage
{
    // attributes
public:
    NoteOffEvent();	// Default Constructor
    NoteOffEvent(int resulting_time,unsigned char* event_data,int event_data_length);
    const NoteOffEvent& operator= (const NoteOffEvent& noev); // Assignment Operator
    virtual ~NoteOffEvent();
    int Nota();	// note value
    void setNota(int new_note);
    void setCanal(int new_chan);

    QMidiMessage* AsociadaNoteOn;
};

class NoteOnEvent : public QMidiMessage
{
    // attributes
public:
    NoteOnEvent();	// Default Constructor
    NoteOnEvent(int resulting_time,unsigned char* event_data,int event_data_length);
    const NoteOnEvent& operator= (const NoteOnEvent& noev); // Assignment Operator
    virtual ~NoteOnEvent();
    int Nota();	// note value
    void setNota(int new_note);
    void setCanal(int new_chan);
    int Velocidad();
    void setVelocidad(int vel);

    QMidiMessage* AsociadaNotaOff;
};

#endif // QMIDIEVENT_H
