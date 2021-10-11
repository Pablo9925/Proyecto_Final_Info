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


private:
    QGraphicsEllipseItem *ellipse;
    QTimer *time;
    int sizex,sizey;
    float possx,possy;
    Ui::MainWindow *ui;
    QGraphicsScene *escena;
    personaje *advGirl;

};

#endif // MAINWINDOW_H
