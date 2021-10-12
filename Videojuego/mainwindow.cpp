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
    bsound= new QMediaPlayer();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete advGirl;
    delete time;
    delete bsound;
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
    else if(i->key()==Qt::Key_P){
        if(bulletAct==false){
            bsound->setMedia(QUrl("qrc:/sonidos/bala.mp3"));
            bsound->play();
            bulletAct=true;
            direc=advGirl->get_direc();
            advGirl->shot();
            escena->addItem(advGirl->getBullet());
            if(advGirl->get_direc()==true) advGirl->getBullet()->setPos(advGirl->get_posx()+sizey/5,sizey-advGirl->get_posy()/2-(sizey/48));
            else advGirl->getBullet()->setPos(advGirl->get_posx(),sizey-advGirl->get_posy()/2-(sizey/48));
            time= new QTimer;
            time->start(25);
            connect(time,SIGNAL(timeout()),this,SLOT(movimientobala()));
        }
    }
    else if(i->key()==Qt::Key_O){
        advGirl->melee();

    }
}

void MainWindow::movimientobala()
{
    if(direc==true) advGirl->getBullet()->actualiza_posR();
    else advGirl->getBullet()->actualiza_posL();
    if(advGirl->getBullet()->get_posx()>advGirl->get_posx()+sizex && direc==true){
        time->stop();
        escena->removeItem(advGirl->getBullet());
        bulletAct=false;
    }
    else if (advGirl->getBullet()->get_posx()<advGirl->get_posx()-sizex && direc==false){
        time->stop();
        escena->removeItem(advGirl->getBullet());
        bulletAct=false;
    }
}


