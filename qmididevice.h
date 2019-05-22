#ifndef QMIDIDEVICE_H
#define QMIDIDEVICE_H

#include <Windows.h>
#include <mmsystem.h>
#include <QList>


class QMidiDevice
{
public:
    QMidiDevice();
    unsigned long EscanearDispositivos (void);
    void SetDispositivoOut (unsigned long numDispositivo);
    void SetDispositivoIn (unsigned long numDispositivo);
    unsigned long GetDispositivoOutSel (void);
    unsigned long GetDispositivoInSel (void);
    QString GetDispositivoOutName (unsigned long nDisp);
    QString GetDispositivoInName (unsigned long nDisp);
    unsigned long GetNumDispositivosOut (void);
    unsigned long GetNumDispositivosIn (void);
private:
    unsigned long DispositivoOutSel;
    unsigned long DispositivoInSel;
    QList <MIDIOUTCAPS> DispositivosOut;
    unsigned long NumeroDispositivosOut;
    QList <MIDIINCAPS> DispositivosIn;
    unsigned long NumeroDispositivosIn;
};

#endif // QMIDIDEVICE_H
