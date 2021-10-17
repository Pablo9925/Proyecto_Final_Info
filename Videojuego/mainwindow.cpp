#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),

    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setup_mainwindow();
    generar_mapa();
    advGirl=new personaje(sizey);
    advGirl->setPos(60,sizey*7/10); //Esa posición en y por la acumulación de la posición del personaje y la posición de los bloques del mapa
    escena->addItem(advGirl);
    advGirl->setPosy(sizey*7/10);
    view->setScene(escena);
    view->resize(sizex,sizey);
    this->resize(sizex,sizey);
    view->centerOn(advGirl->x(),advGirl->y());
    bsound= new QMediaPlayer();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete advGirl;
    delete time;
    delete bsound;
    delete l1;
    delete l2;
    for(int x=0; x<columnas; x++) for(int y=0; y<filas; y++) delete mapa[x][y];
    delete l_mapa;
}

void MainWindow::setup_mainwindow()
{
    sizex=1280;
    sizey=720;
    escena = new QGraphicsScene(this);
    view = new QGraphicsView(this);
    setGeometry(0,0,sizex,sizey);
    setWindowTitle("Rise of the tomb explorer");
    setWindowIcon(QIcon(":/escena/TombStone (2).png"));
    ui->graphicsView->setGeometry(0,0,sizex*5+2,sizey+2);
    escena->setSceneRect(0,0,sizex*15,sizey);
    escena->setBackgroundBrush(QBrush(QImage(":/escena/BG2.png")));
    ui->graphicsView->setScene(escena);
    //Líneas para evitar que se salgan de los rangos de la escena
    l1 = new QGraphicsLineItem(0,0,0,sizey); // <-- Línea izquierda
    l2 = new QGraphicsLineItem(sizex*15,0,sizex*15,sizey); // <-- Línea derecha
    escena->addItem(l1);
    escena->addItem(l2);
}

void MainWindow::generar_mapa()
{
    int ** m_mapa;
    l_mapa = new logicamap(columnas*15,filas);
    m_mapa=l_mapa->generar_mapa();

    for(int x=0;x<columnas*15;x++){
        for(int y=0;y<filas;y++) {
            matriz[x][y]=m_mapa[x][y];
            mapa[x][y] = new map(sizex,sizey);
            mapa[x][y]->setup_tipo(m_mapa[x][y]);
            mapa[x][y]->setX((sizex/columnas)*x);
            if(m_mapa[x][y]==3) mapa[x][y]->setY(((sizey/filas)*y)+(sizey/filas));
            else mapa[x][y]->setY(((sizey/(filas))*y)+(sizey/filas)/2);
            escena->addItem(mapa[x][y]);
        }
    }
}

void MainWindow::keyPressEvent(QKeyEvent *i)
{
    if(i->key()==Qt::Key_D){
        if(advGirl->getParabolico()==false){
            advGirl->mov_der();
            advGirl->setX(advGirl->x()+20);
        }
        if(advGirl->collidesWithItem(l2)){
            advGirl->mov_izq();
            advGirl->setX(advGirl->x()-20);
        }
        view->centerOn(advGirl->x(),advGirl->y());
        //if(matriz[int(advGirl->get_posx()/160)][int(advGirl->get_posy()/144)+1]==1 || matriz[int(advGirl->get_posx()/160)][int(advGirl->get_posy()/144)+1]==2){
            if(matriz[int(advGirl->get_posx()/160)][int(advGirl->get_posy()/144)+1]==0 && int(advGirl->get_posy()/144)+1==4){
                timec=new QTimer;
                timec->start(1);
                connect(timec,SIGNAL(timeout()),this,SLOT(caida()));
            }
        //}
    }
    else if(i->key()==Qt::Key_A){
        if(advGirl->getParabolico()==false){
            advGirl->mov_izq();
            advGirl->setX(advGirl->x()-20);
        }
        if(advGirl->collidesWithItem(l1)){
            advGirl->mov_der();
            advGirl->setX(advGirl->x()+20);
        }
        view->centerOn(advGirl->x(),advGirl->y());
    }
    else if(i->key()==Qt::Key_P){
        if(bulletAct==false && advGirl->get_ammo()>0){
            if(advGirl->get_direc()==true) advGirl->setPixmap((QPixmap(":/sprites personaje/Shoot (1).png").scaled(sizey/5,sizey/5)));
            else advGirl->setPixmap((QPixmap(":/sprites personaje/ShootL (1).png").scaled(sizey/5,sizey/5)));
            advGirl->set_ammo(advGirl->get_ammo()-1);
            bsound->setMedia(QUrl("qrc:/sonidos/bala.mp3"));
            bsound->play();
            bulletAct=true;
            direc=advGirl->get_direc();
            advGirl->shot();
            escena->addItem(advGirl->getBullet());
            if(advGirl->get_direc()==true) advGirl->getBullet()->setPos(advGirl->get_posx()+sizey/5,advGirl->get_posy()+75);
            else advGirl->getBullet()->setPos(advGirl->get_posx(),advGirl->get_posy()+75);
            time= new QTimer;
            time->start(25);
            connect(time,SIGNAL(timeout()),this,SLOT(movimientobala()));
        }
    }
    else if(i->key()==Qt::Key_O){
        if(advGirl->get_ActAttack()==false){
            advGirl->melee();
        }
    }
    else if(i->key()==Qt::Key_W){
        if(advGirl->getParabolico()==false){
            time=new QTimer;
            time->start(1);
            connect(time,SIGNAL(timeout()),this,SLOT(saltoparabolico()));
            advGirl->jump();
        }
    }
}

void MainWindow::saltoparabolico()
{
    advGirl->setParabolico(true);
    if(advGirl->getDerecha()==true){
        posxsalto = advGirl->get_posx()+vxo*n*(T); //salto a la derecha
        posysalto = advGirl->get_posy()-(vyo*n*(T)-0.5*a*n*(T)*n*(T));
        n++;
    }
    else{
        posxsalto = advGirl->get_posx()-vxo*n*(T); //salto a la izquierda
        posysalto = advGirl->get_posy()-(vyo*n*(T)-0.5*a*n*(T)*n*(T));
        n++;
    }
    advGirl->setX(posxsalto);
    advGirl->setY(posysalto);



}

void MainWindow::caida()
{
    posysalto = (sizey-advGirl->get_posy())-0.5*a*n*(T)*n*(T);
    n++;
    advGirl->setY(sizey-posysalto);
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

