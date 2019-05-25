#ifndef QMIDIMESSAGE_H
#define QMIDIMESSAGE_H

#include "Windows.h"
#include <QtCore>

#define QMIDI_TIPO_NOEVENT 0X000000
#define QMIDI_TIPO_NORMALEVENT 0X000001
#define QMIDI_TIPO_METAEVENT 0X000002
#define QMIDI_TIPO_SYSEXEVENT 0X000003

// Eventos normales
#define QMIDI_EVENT_NOTAON  0X009001
#define QMIDI_EVENT_NOTAOFF 0X008001
#define QMIDI_EVENT_POLYPRESION 0X00A001
#define QMIDI_EVENT_CONTROLER 0X00B001
#define QMIDI_EVENT_PROG_CHANGE 0X00C001
#define QMIDI_EVENT_CANALPRESION 0X00D001
#define QMIDI_EVENT_PICHBEND    0X00E001

// MetaEventos
#define QMIDI_METAEVENT_TEXT 0X000102
#define QMIDI_METAEVENT_COPYRIGHT 0X000202
#define QMIDI_METAEVENT_TRACKNAME 0X000302
#define QMIDI_METAEVENT_INSTRUMENTNAME 0X000402
// SysEx eventos

// Definiciones globales
#define QMIDI_NO_CANAL  16

class QMidiMessage
{
public:
    QMidiMessage();
    QMidiMessage(ulong MiTiempoAbsoluto,uchar* Mi_event_data,uint Mi_event_data_length);
    const QMidiMessage& operator= (const QMidiMessage& mev);
    virtual ~QMidiMessage();
    void CambiarCanal (uint canal);
    uint Sub1Type(void);
    uint Sub2Type(void);
    uint Sub3Type(void);
    virtual QString getNombre (void);

    ulong Tipo;
    uint Tempo;
    ulong TiempoAbsoluto;
    QByteArray event_data;
    uint event_data_length;
    uint Canal;
    int Elegido;
private:
};

#endif // QMIDIMESSAGE_H
