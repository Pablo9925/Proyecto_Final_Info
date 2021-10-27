#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QKeyEvent>
#include <QIcon>
#include <QMediaPlayer>
#include "personaje.h"
#include "logicamap.h"
#include "map.h"
#include "caja.h"
#include "coin.h"
#include "maza.h"
#include "zombie.h"
#include <string>
#include <menupausa.h>
#include "puntuaje.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setup_mainwindow();
    void generar_mapa();
    bool generar_caja();
    bool generar_moneda();
    bool generar_maza();
    bool generar_zombie();
    void keyPressEvent(QKeyEvent *i);
    void setNombre(const QString &value);
    void cargar();
    void setNombre2(const QString &value);
    void setMultiplayer(bool value);
public slots:
    void cerrar();
    void deslizando();
    void movimientobala();
    void saltoparabolico();
    void caida();
    void movimiento_maza();
    void movimiento_zombie();
private:
    int sizex=0,sizey=0,n=1,nc=0,nf=0,contatt=0,contmue=14,puntos1=0,puntos2=0;
    int matriz[columnas*15][filas];
    bool bulletAct=false, direc, cae=false,salto=false,multiplayer=false;
    Ui::MainWindow *ui;
    QGraphicsScene *escena;
    QGraphicsView *view;
    personaje *advGirl;
    QTimer *timemaz;
    QTimer *time;
    QTimer *timec;
    QTimer *times;
    QTimer *timez;
    QTimer *timemorir;
    QMediaPlayer * bsound;
    QMediaPlayer * csound;
    QMediaPlayer * coinsound;
    QMediaPlayer * ammosound;
    QMediaPlayer * zsound;
    QMediaPlayer * psound;
    QMediaPlayer * cajasound;
    QGraphicsLineItem *l1, *l2;
    map *mapa[columnas*15][filas];
    menupausa *pausa;
    Puntuaje *puntos;
    logicamap *l_mapa;
    QList <caja*> cajas;
    QList <coin*> monedas;
    QList <maza*> mazas;
    QList <zombie*> zombies;
    QString nombre,nombre2;
    float  posxsalto=0,posysalto=0,posysaltoant=0,vxo=5,vyo=25,T=0.1,posyinicial=0,posfric=0,F=10.0,K=0.45,p=0.15,pm=0.1,pz=0.15;
    double a=1;
};

#endif // MAINWINDOW_H
