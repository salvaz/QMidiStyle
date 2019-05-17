#include "ventanaprincipal.h"
#include <QMessageBox>
#include <QFileDialog>
#include <iostream>
#include <windows.h>
#include "mmsystem.h"

VentanaPrincipal::VentanaPrincipal(QWidget *parent)
    : QMainWindow(parent)
{
    CrearAcciones();
    CrearBarraHerramientas();
    CrearMenu();
    CrearGui();
}

VentanaPrincipal::~VentanaPrincipal()
{

}

void VentanaPrincipal::CrearAcciones(void)
{
    openAction=new QAction(tr("&Abrir"), this);
    openAction->setIcon(QIcon(":/new/Iconos/IconAbrir"));
    openAction->setShortcut(QKeySequence::Open);
    openAction->setStatusTip(tr("Abrir un nuevo documento"));
//    connect(openAction, &QAction::triggered, this, &VentanaPrincipal::AbrirDocumento);

    importAction=new QAction(tr("&Importar estilo"), this);
    importAction->setIcon(QIcon(":/new/Iconos/IconImportar"));
    importAction->setShortcut(QKeySequence::Open);
    importAction->setStatusTip(tr("Importar un estilo"));
//    connect(importAction, &QAction::triggered, this, &VentanaPrincipal::ImportarDocumento);

    saveAction = new QAction(tr("&Guardar"), this);
    saveAction->setIcon(QIcon(":/new/Iconos/IconSave"));
    saveAction->setShortcut(QKeySequence::Save);
    saveAction->setStatusTip(tr("Guardar el documento"));
//    connect(saveAction, &QAction::triggered, this, &VentanaPrincipal::GuardarDocumento);

    saveasAction = new QAction(tr("Guardar como"), this);
    saveasAction->setIcon(QIcon(":/new/Iconos/IconSaveAs"));
    saveasAction->setShortcut(QKeySequence::SaveAs);
    saveasAction->setStatusTip(tr("Guardar un nuevo documento"));
//    connect(saveasAction, &QAction::triggered, this, &VentanaPrincipal::GuardarComoDocumento);
    exitAction = new QAction(tr("&Salir"), this);
    exitAction->setIcon(QIcon(":/new/Iconos/IconCerrar"));
    exitAction->setShortcut(QKeySequence::Close);
    exitAction->setStatusTip(tr("Cerrar el programa"));
    connect(exitAction, &QAction::triggered, this, &VentanaPrincipal::CerrarPrograma);
}

void VentanaPrincipal::CrearMenu(void)
{
    fileMenu = menuBar()->addMenu(tr("&Archivo"));
    fileMenu->addAction(openAction);
    fileMenu->addAction(importAction);
    fileMenu->addAction(saveAction);
    fileMenu->addAction(saveasAction);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAction);
}

void VentanaPrincipal::CrearBarraHerramientas(void)
    {
    BarraHerramientas = addToolBar("Barra Principal");
    BarraHerramientas->addAction(openAction);
    BarraHerramientas->addAction(importAction);
    BarraHerramientas->addAction(saveAction);
    BarraHerramientas->addSeparator();
    BarraHerramientas->addAction(exitAction);
    addToolBar(Qt::LeftToolBarArea,BarraHerramientas);

    BarraEstado = statusBar();
    BarraEstado->setVisible(true);

}

void VentanaPrincipal::CrearGui(void)
{
    MiTab=new QTabWidget(this);
    CrearTabVisor();

    CrearTabOpciones();
    MiTab->addTab(TabVisor,QIcon(":/Iconos/TabVisor"),"Visor");
    MiTab->addTab(TabOpciones,QIcon(":/Iconos/TabOpciones"),"Opciones");

    QString TituloApp="Estilos Midi";
    this->setWindowTitle(NombreFichero+" - "+TituloApp);

    this->setWindowIcon(QIcon(":/new/Iconos/IconApp"));
    this->setCentralWidget(MiTab);
    this->setWindowState(Qt::WindowMaximized);
}

void VentanaPrincipal::CrearTabVisor()
{
    TabVisor=new QWidget();
    TabLayVisor=new QBoxLayout(QBoxLayout::LeftToRight);
    TabVisor->setLayout(TabLayVisor);
    MiTab->addTab(TabVisor,QIcon(":/new/Iconos/IconTabVisor"),"Visor");
}

void VentanaPrincipal::CrearTabOpciones()
{
    QLabel *label;
    TabOpciones=new QWidget();

    GrupoDevices=new QGroupBox(tr("Seleccionar devices"),this);
    GridOpcionesDevices=new QGridLayout();
    label=new QLabel(tr("Dispositivo entrada :"),GrupoDevices);
    GridOpcionesDevices->addWidget(label,0,0,Qt::AlignLeft);
    MidiDeviceIn=new QComboBox(this);
    GridOpcionesDevices->addWidget(MidiDeviceIn,0,1,Qt::AlignLeft);
    label=new QLabel(tr("Dispositivo salida :"),GrupoDevices);
    GridOpcionesDevices->addWidget(label,1,0,Qt::AlignLeft);
    MidiDeviceOut=new QComboBox(this);
    GridOpcionesDevices->addWidget(MidiDeviceOut,1,1,Qt::AlignLeft);
    GrupoDevices->setLayout(GridOpcionesDevices);

    TabLayOpciones=new QBoxLayout(QBoxLayout::LeftToRight);
    TabLayOpciones->addWidget(GrupoDevices);
    TabOpciones->setLayout(TabLayOpciones);
    MiTab->addTab(TabOpciones,QIcon(":/new/Iconos/IconTabOpciones"),"Opciones");

    RellenarDispositivos();
}

void VentanaPrincipal::CerrarPrograma(void)
{
    qApp->quit();
}

void VentanaPrincipal::ImportarEstilo()
{
    QMessageBox msgBox;

    NombreFichero=QFileDialog::getOpenFileName(this,tr("Importar estilo yamaha psr"), ".", "all (*.*);;Estilo (*.sty)");
    if(NombreFichero.isEmpty())
    {
        msgBox.setText(tr("No se ha seleccionado ningún fichero."));
        msgBox.exec();
    }
    else {
        QFile fichero(NombreFichero);


    }
}

void VentanaPrincipal::RellenarDispositivos()
{
    HP_DEVICE *devices;
    int no_devices;
    UINT result;
    QMessageBox msgBox;
    QString name;

    result = HP_GetMIDIDevices(&devices,&no_devices);
    if (result != HP_ERR_NONE)
    {
       msgBox.setText(HP_ErrText(int(result)));
       return;
    }

    for (int kk=0; kk<no_devices; kk++)
    {
       name = devices[kk].device_name;
        MidiDeviceOut->addItem(name,devices[kk].device_id);
    }
    HP_Delete(devices);

    unsigned int devCount = midiInGetNumDevs();
    MIDIINCAPS inputCapabilities;
    for (unsigned int i = 0; i < devCount; i++) {
        midiInGetDevCaps(i, &inputCapabilities, sizeof(inputCapabilities));
        name=QString::fromWCharArray(inputCapabilities.szPname);
        MidiDeviceIn->addItem(name,inputCapabilities.wPid);
    }
    MidiDeviceOut->clear();
    unsigned int devoutCount = midiOutGetNumDevs();
    MIDIOUTCAPS outputCapabilities;
    for (unsigned int i = 0; i < devoutCount; i++) {
        midiOutGetDevCaps(i, &outputCapabilities, sizeof(outputCapabilities));
        name=QString::fromWCharArray(outputCapabilities.szPname);
        MidiDeviceOut->addItem(name,outputCapabilities.wPid);
    }

}
