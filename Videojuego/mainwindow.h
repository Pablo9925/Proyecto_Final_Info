#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QKeyEvent>
#include <QIcon>
#include <QMediaPlayer>
#include "personaje.h"

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
    void keyPressEvent(QKeyEvent *i);

public slots:
    void movimientobala();

private:
    int sizex,sizey;
    bool bulletAct=false, direc;
    Ui::MainWindow *ui;
    QGraphicsScene *escena;
    QGraphicsView *view;
    personaje *advGirl;
    QTimer *time;
    QMediaPlayer * bsound;
    QGraphicsLineItem *l1, *l2;

};

#endif // MAINWINDOW_H
