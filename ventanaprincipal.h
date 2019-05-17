#ifndef VENTANAPRINCIPAL_H
#define VENTANAPRINCIPAL_H

#include <QMainWindow>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>
#include <QStatusBar>
#include <QTabWidget>
#include <QBoxLayout>
#include <QGridLayout>
#include <QApplication>
#include <QGroupBox>
#include <QComboBox>
#include <QLabel>
#include "HPMidiFile/HP_midifile.h"

class VentanaPrincipal : public QMainWindow
{
    Q_OBJECT

public:
    VentanaPrincipal(QWidget *parent = nullptr);
    ~VentanaPrincipal();
private:
// Variables globales
    QString NombreFichero;
    HP_MIDIFILE_MODULE *MidiFile;

// Acciones
    QAction *openAction;
    QAction *importAction;
    QAction *saveAction;
    QAction *saveasAction;
    QAction *exitAction;
// Menus
    QMenu *fileMenu;
// Barras de herramientas
    QToolBar *BarraHerramientas;
    QStatusBar *BarraEstado;
// Tabs de la ventana principal
    QTabWidget *MiTab;
    QWidget *TabVisor;
    QWidget *TabOpciones;
    QBoxLayout *TabLayVisor;
    QBoxLayout *TabLayOpciones;
// Controles de configuracion
    QGridLayout *GridOpcionesDevices;
    QGroupBox *GrupoDevices;
    QComboBox *MidiDeviceIn;
    QComboBox *MidiDeviceOut;

// Funciones para crear el GUI
    void CrearAcciones (void);
    void CrearMenu (void);
    void CrearBarraHerramientas (void);
    void CrearGui (void);
    void CrearTabVisor (void);
    void CrearTabOpciones (void);
    void RellenarDispositivos (void);
private slots:
//    void AbrirDocumento (void);
//    void GuardarDocumento (void);
//    void GuardarComoDocumento (void);
    void ImportarEstilo (void);
    void CerrarPrograma (void);

};

#endif // VENTANAPRINCIPAL_H
