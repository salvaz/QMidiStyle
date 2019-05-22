#ifndef QMIDIMESSAGE_H
#define QMIDIMESSAGE_H

#include "Windows.h"

#define HP_NOTE						0x000200
#define HP_AFTERTOUCH				0x000300
    // Control Change Events
    #define HP_CONTROLLER_TYPE	    0x000400
    #define HP_BANK_SELECT_MSB		0x010400
    #define HP_MODULATION			0x020400
    #define HP_BREATH				0x030400
    #define HP_PORTAMENTO_TIME		0x040400
    #define HP_MAIN_VOLUME			0x050400
    #define HP_PANPOT				0x060400
    #define HP_EXPRESSION			0x070400
    #define HP_BANK_SELECT_LSB		0x080400
    #define HP_SUSTAIN				0x090400
    #define HP_PORTAMENTO			0x0a0400
    #define HP_SOSTENUTO			0x0b0400
    #define HP_SOFT_PEDAL			0x0c0400
    #define HP_HARMONIC_CONTENT		0x0d0400
    #define HP_RELEASE_TIME			0x0e0400
    #define HP_ATTACK_TIME			0x0f0400
    #define HP_BRIGHTNESS			0x100400
    #define HP_DECAY_TIME			0x110400
    #define HP_VIBRATO_RATE			0x120400
    #define HP_VIBRATO_DEPTH		0x130400
    #define HP_VIBRATO_DELAY		0x140400
    #define HP_PORTAMENTO_CONTROL	0x150400
    #define HP_REVERB_SEND_LEVEL	0x160400
    #define HP_CHORUS_SEND_LEVEL	0x170400
    #define HP_VARIATION_SEND_LEVEL	0x180400
    #define HP_NRPN					0x190400
    #define HP_RPN					0x1a0400
    #define HP_ALL_SOUND_OFF		0x1b0400
    #define HP_RESET_ALL_CONTROLLERS	0x1c0400
    #define HP_ALL_NOTES_OFF		0x1d0400
    #define HP_OMNI_OFF				0x1e0400
    #define HP_OMNI_ON				0x1f0400
    #define HP_MONO					0x200400
    #define HP_POLY					0x210400
#define HP_PROGRAM_CHANGE			0x000500
#define HP_CHANNEL_PRESSURE			0x000600
#define HP_PITCH_WHEEL				0x000700
#define HP_SYSEX					0x000800

// Meta-Events

#define HP_SEQUENCE_NUMBER			0x000101
#define HP_TEXT						0x000201
#define HP_COPYRIGHT				0x000301
#define HP_SONG_TRACK_NAME			0x000401
#define HP_INSTRUMENT				0x000501
#define HP_LYRIC					0x000601
#define HP_MARKER					0x000701
#define HP_CUE_POINT				0x000801
#define HP_CHANNEL_PREFIX			0x000901
#define HP_MIDI_PORT				0x000a01
#define HP_END_OF_TRACK				0x000b01
#define HP_TEMPO					0x000c01
#define HP_SMPTE_OFFSET				0x000d01
#define HP_TIME_SIGNATURE			0x000e01
#define HP_KEY_SIGNATURE			0x000f01
#define HP_OTHER_META				0x00fe01

// YAMAHA Meta Events

#define HP_SCORE_START_BAR			0x01ff01
#define HP_QUICK_START				0x02ff01
#define HP_SCORE_LAYOUT				0x03ff01
#define HP_KEYBOARD_VOICE			0x04ff01
#define HP_XF_VERSION_ID			0x41ff01
#define HP_CHORD_NAME				0x42ff01
#define HP_REHEARSAL_MARK			0x43ff01
#define HP_PHRASE_MARK				0x44ff01
#define HP_MAX_PHRASE_MARK			0x45ff01
#define HP_FINGERING_NUMBER			0x46ff01
#define HP_GUIDE_TRACK_FLAG			0x47ff01
#define HP_GUITAR_INFORMATION_FLAG  0x48ff01
#define HP_CHORD_VOICING_FOR_GUITAR 0x49ff01
#define HP_LYRICS_BITMAP			0x4aff01
#define HP_OTHER_YAMAHA_META		0x00ff01

// User Defined Event

#define HP_RAW_EVENT				0x000002

#define HP_TYPE_MASK				0x00ffff

#define HP_TYPE_NONE				0xfefefe

#define HP_NOTE_OFF					0x000100
#define HP_NOTE_ON					HP_NOTE

#define HP_DATA_ENTRY_MSB			0x220400
#define HP_DATA_ENTRY_LSB			0x230400
#define HP_NRPN_LSB					0x240400
#define HP_NRPN_MSB					HP_NRPN
#define HP_RPN_LSB					0x250400
#define HP_RPN_MSB					HP_RPN
#define HP_DATA_INCREMENT			0x260400
#define HP_DATA_DECREMENT			0x270400

// MIDI-Events

#define HP_MIDI_EVENT				0x00	// type
#define HP_META_EVENT				0x01	// sub1type
#define HP_CONTROL_CHANGE			0x04	// sub1type
#define HP_XF_META					0xff	// sub1type

// Switches for Functions

#define HP_FIRST				true
#define HP_LAST					false
#define HP_DELETE				true
#define HP_NO_DELETE			false
#define HP_ALL_CHAN				-1
#define HP_NO_CHAN				-1
#define HP_NO_TRACK				-1
#define HP_ALL_EVENTS			-2
#define HP_PERCENT				true
#define HP_NO_PERCENT			false
#define HP_NO_NOTE				-1
#define HP_ALL_NOTES			-2
#define HP_ABSOLUTE				true
#define HP_RELATIVE				false
#define HP_NO_TIME_LIMIT        -1
#define HP_ASSEMBLE				true
#define HP_NO_ASSEMBLE			false
#define HP_NO_CONTROLLER_NUMBER -1
#define HP_SEND_EFFECT_EVENTS_BEFORE	true
#define HP_NO_SEND_BEFORE				false
#define HP_GO_PLAY				0
#define HP_STOP_PLAY			1
#define HP_WAIT_PLAY            2
#define HP_ALL					1
#define HP_SELECTED				2
#define HP_GM_VOICE_BANK        -128
#define HP_GM_PERC_BANK         -256

class QMidiMessage
{
public:
    QMidiMessage();
    QMidiMessage(int MiTiempoAbsoluto,unsigned char* Mi_event_data,int Mi_event_data_length);
    const QMidiMessage& operator= (const QMidiMessage& mev);
    virtual ~QMidiMessage();
    void CambiarCanal (int canal);
    unsigned int Sub1Type(void);
    unsigned int Sub2Type(void);
    unsigned int Sub3Type(void);

    unsigned int Tipo;
    int Tempo;
    int TiempoAbsoluto;
    unsigned char *event_data;
    int event_data_length;
    int Canal;
    int Elegido;
private:
};

#endif // QMIDIMESSAGE_H
