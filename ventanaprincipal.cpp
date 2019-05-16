#include "ventanaprincipal.h"

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
    TabOpciones=new QWidget();
    TabLayOpciones=new QBoxLayout(QBoxLayout::LeftToRight);
    TabOpciones->setLayout(TabLayOpciones);
    MiTab->addTab(TabOpciones,QIcon(":/new/Iconos/IconTabOpciones"),"Opciones");
}

void VentanaPrincipal::CerrarPrograma(void)
{
    qApp->quit();
}
