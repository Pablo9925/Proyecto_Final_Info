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
    void keyPressEvent(QKeyEvent *i);


public slots:
    void movimientobala();
    void saltoparabolico();
    void caida();

private:
    int sizex=0,sizey=0,n=1,nc=0,contsalto=0;
    int matriz[columnas*15][filas];
    bool bulletAct=false, direc;
    Ui::MainWindow *ui;
    QGraphicsScene *escena;
    QGraphicsView *view;
    personaje *advGirl;
    QTimer *time;
    QTimer *timec;
    QTimer *times;
    QMediaPlayer * bsound;
    QGraphicsLineItem *l1, *l2;
    map *mapa[columnas*15][filas];
    logicamap *l_mapa;
    float  posxsalto=0,posysalto=0,vxo=5,vyo=25,T=0.05,posyinicial=0;
    double a=1;
};

#endif // MAINWINDOW_H
