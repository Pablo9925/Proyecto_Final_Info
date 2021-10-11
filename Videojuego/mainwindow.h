#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QIcon>
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
    QGraphicsEllipseItem *ellipse;
    QTimer *time;
    int sizex,sizey,contbala=20;
    personaje *possx;
    Ui::MainWindow *ui;
    QGraphicsScene *escena;
    personaje *advGirl;

};

#endif // MAINWINDOW_H
