#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setup_mainwindow();
    advGirl=new personaje(sizey);
    advGirl->setPos(60,sizey-180);
    escena->addItem(advGirl);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete advGirl;
}

void MainWindow::setup_mainwindow()
{
    sizex=1280;
    sizey=720;
    escena = new QGraphicsScene;
    setGeometry(0,0,sizex,sizey);
    setWindowTitle("Rise of the tomb explorer");
    setWindowIcon(QIcon(":/escena/TombStone (2).png"));
    ui->graphicsView->setGeometry(0,0,sizex+2,sizey+2);
    escena->setSceneRect(0,0,sizex,sizey);
    ui->graphicsView->setScene(escena);
}

void MainWindow::keyPressEvent(QKeyEvent *i)
{
    if(i->key()==Qt::Key_D){
        advGirl->mov_der();
        advGirl->setX(advGirl->x()+20);
    }
    else if(i->key()==Qt::Key_A){
        advGirl->mov_izq();
        advGirl->setX(advGirl->x()-20);
    }
}
