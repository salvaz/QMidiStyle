#include "qmididevice.h"

QMidiDevice::QMidiDevice()
{
    NumeroDispositivosIn=0;
    NumeroDispositivosOut=0;

}

unsigned long QMidiDevice::EscanearDispositivos()
{
    MIDIOUTCAPS     moc;
    MIDIINCAPS     mic;
    unsigned long totalDisp;

    totalDisp=midiOutGetNumDevs();
    DispositivosIn.clear();
    DispositivosOut.clear();
    for (unsigned long kk = 0; kk < totalDisp; kk++)
    {
        if (!midiOutGetDevCaps(kk, &moc, sizeof(MIDIOUTCAPS)))
        {
            DispositivosOut.append(moc);
        }
    }
    NumeroDispositivosOut=static_cast<unsigned long>(DispositivosOut.size());

    for (unsigned long kk = 0; kk < totalDisp; kk++)
    {
        if (!midiInGetDevCaps(kk, &mic, sizeof(MIDIINCAPS)))
        {
            DispositivosIn.append(mic);
        }
    }
    NumeroDispositivosIn=static_cast<unsigned long>(DispositivosIn.size());
    return totalDisp;
}

unsigned long QMidiDevice::GetNumDispositivosOut (void)
{
    return static_cast<unsigned long>(DispositivosOut.size());
}

unsigned long QMidiDevice::GetNumDispositivosIn (void)
{
    return static_cast<unsigned long>(DispositivosIn.size());
}

void QMidiDevice::SetDispositivoOut (unsigned long numDispositivo)
{
    if (numDispositivo<=NumeroDispositivosOut)
    {
        DispositivoOutSel=numDispositivo;
    }
}

void QMidiDevice::SetDispositivoIn (unsigned long numDispositivo)
{
    if (numDispositivo<=NumeroDispositivosIn)
    {
        DispositivoInSel=numDispositivo;
    }
}

unsigned long QMidiDevice::GetDispositivoOutSel (void)
{
    return DispositivoOutSel;
}

unsigned long QMidiDevice::GetDispositivoInSel (void)
{
    return DispositivoInSel;
}

QString QMidiDevice::GetDispositivoOutName (unsigned long nDisp)
{
    QString name;

    if (nDisp<=NumeroDispositivosOut)
    {
        name=QString::fromWCharArray(DispositivosOut.at(static_cast<int>(nDisp)).szPname);
    }
    return name;
}

QString QMidiDevice::GetDispositivoInName (unsigned long nDisp)
{
    QString name;

    if (nDisp<=NumeroDispositivosIn)
    {
        name=QString::fromWCharArray(DispositivosIn.at(static_cast<int>(nDisp)).szPname);
    }
    return name;
}
