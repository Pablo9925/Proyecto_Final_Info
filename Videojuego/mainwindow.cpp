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
    movimientomaza();


}

MainWindow::~MainWindow()
{
    delete ui;
    delete advGirl;
    delete time;
    delete timec;
    delete times;
    delete bsound;
    delete l1;
    delete l2;
    for(int x=0; x<columnas; x++) for(int y=0; y<filas; y++) delete mapa[x][y];
    for (int i=0;i<cajas.length();i++) delete cajas.at(i);
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
            if((m_mapa[x][y]==1 || m_mapa[x][y]==2) && x!=0 && x!=columnas*15){
                if(generar_maza()){
                    mazas.append(new maza(x*(sizex/columnas)+53,y*(sizey/filas)-120,sizey/5));
                }
                else if(generar_caja()){
                    cajas.append(new caja(x*(sizex/columnas)+53,y*(sizey/filas),sizey/5));
                }

            }
            matriz[x][y]=m_mapa[x][y];
            mapa[x][y] = new map(sizex,sizey);
            mapa[x][y]->setup_tipo(m_mapa[x][y]);
            mapa[x][y]->setX((sizex/columnas)*x);
            if(m_mapa[x][y]==3) mapa[x][y]->setY(((sizey/filas)*y)+(sizey/filas));
            else mapa[x][y]->setY(((sizey/(filas))*y)+(sizey/filas)/2);
            escena->addItem(mapa[x][y]);
        }

    }
    for(int j=0;j<cajas.size();j++){
        escena->addItem(cajas.at(j));
    }
    for(int j=0;j<mazas.size();j++){
        escena->addItem(mazas.at(j));
    }
}
bool MainWindow::generar_caja()
{
    int n, x;
    n=rand();
    x=p*(RAND_MAX+1)-1;
    return n<=x;
}

void MainWindow::movimientomaza()
{
  for(int j=0;j<mazas.length();j++){
      mazas.at(j)->movimiento();

  }
}

void MainWindow::keyPressEvent(QKeyEvent *i)
{
    if(i->key()==Qt::Key_D){
        if(advGirl->getParabolico()==false && cae==false){
            advGirl->mov_der();
            advGirl->setX(advGirl->x()+20);
            if(advGirl->collidesWithItem(l2)){
                advGirl->mov_izq();
                advGirl->setX(advGirl->x()-20);
            }
            view->centerOn(advGirl->x(),advGirl->y());
            if(matriz[int(advGirl->get_posx()/160)][int(advGirl->get_posy()/144)+1]==0 && (int(advGirl->get_posy()/144)+1==4 || int(advGirl->get_posy()/144)+1==2) && matriz[int((advGirl->get_posx()+sizey/5)/160)][int(advGirl->get_posy()/144)+1]==0){
                cae=true;
                nc=0;
                posysalto=advGirl->get_posy();
                timec=new QTimer;
                timec->start(2);
                connect(timec,SIGNAL(timeout()),this,SLOT(caida()));
            }
        }
    }
    else if(i->key()==Qt::Key_A){
        if(advGirl->getParabolico()==false && cae==false){
            advGirl->mov_izq();
            advGirl->setX(advGirl->x()-20);
            if(advGirl->collidesWithItem(l1)){
                advGirl->mov_der();
                advGirl->setX(advGirl->x()+20);
            }
            view->centerOn(advGirl->x(),advGirl->y());
            if(matriz[int(advGirl->get_posx()/160)+1][int(advGirl->get_posy()/144)+1]==0 && (int(advGirl->get_posy()/144)+1==4 || int(advGirl->get_posy()/144)+1==2) && matriz[int((advGirl->get_posx()-(sizey/10))/160)+1][int(advGirl->get_posy()/144)+1]==0){
                cae=true;
                nc=0;
                posysalto=advGirl->get_posy();
                timec=new QTimer;
                timec->start(2);
                connect(timec,SIGNAL(timeout()),this,SLOT(caida()));
            }
        }
    }
    else if(i->key()==Qt::Key_P){
        if(bulletAct==false && advGirl->get_ammo()>0 && advGirl->getParabolico()==false){
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
        if(advGirl->get_ActAttack()==false && advGirl->getParabolico()==false){
            advGirl->melee();
            for (int j=0;j<cajas.size() ;j++ ) {
                if(advGirl->collidesWithItem(cajas.at(j))){
                    if(cajas.at(j)->getVida()!=0){
                        cajas.at(j)->setVida(cajas.at(j)->getVida()-advGirl->get_damage());
                    }
                    else{
                        if(cajas.at(j)->ammo()==true){
                            cajas.at(j)->setTipo(true);
                            cajas.at(j)->setPixmap(QPixmap(":/escena/ammo.png").scaled(sizey/10,sizey/10));
                        }
                        else{
                            cajas.at(j)->setTipo(false);
                            cajas.at(j)->setPixmap(QPixmap(":/escena/vida.png").scaled(sizey/10,sizey/10));
                        }
                    }
                }
            }
        }
    }
    else if(i->key()==Qt::Key_W){
        if(advGirl->getParabolico()==false && cae==false && advGirl->getDeslizo()==true){
            if((advGirl->get_direc()==true && advGirl->get_posx()<19000) || (advGirl->get_direc()==false && advGirl->get_posx()>160)){
                n=1;
                vxo=5;
                advGirl->setParabolico(true);
                posxsalto=advGirl->get_posx();
                posysalto=advGirl->get_posy();
                times=new QTimer;
                times->start(1);
                connect(times,SIGNAL(timeout()),this,SLOT(saltoparabolico()));
                advGirl->jump();
            }
        }
    }
    else if(i->key()==Qt::Key_S){
       if(advGirl->getParabolico()==false && cae==false && advGirl->getDeslizo()==true){
           if((advGirl->get_direc()==true && advGirl->get_posx()<19000) || (advGirl->get_direc()==false && advGirl->get_posx()>160)){
               posfric=advGirl->get_posx();
               vxo=20;
               advGirl->setDeslizo(false);
               times=new QTimer;
               times->start(7);
               connect(times,SIGNAL(timeout()),this,SLOT(deslizando()));
            }
       }
    }
    else if(i->key()==Qt::Key_I){
        if(advGirl->get_ActAttack()==false && advGirl->getParabolico()==false){
            for (int j=0;j<cajas.size() ;j++ ) {
                if(advGirl->collidesWithItem(cajas.at(j))){
                    if(cajas.at(j)->getTipo()==true){
                        advGirl->set_ammo(advGirl->get_ammo()+2);
                    }
                    else{
                        advGirl->setVidas(advGirl->getVidas()+1);
                    }
                    escena->removeItem(cajas.at(j));
                }
            }
        }
    }
}

bool MainWindow::generar_maza()
{

        int n, x;
        n=rand();
        x=0.1*(RAND_MAX+1)-1;
        return n<=x;

}

void MainWindow::saltoparabolico()
{
    posysaltoant=posysalto;
    if(advGirl->get_direc()==true){
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
    if(n%7==0) view->centerOn(advGirl->x(),advGirl->y());
    if(advGirl->get_direc()==true){
        if(posysalto>=216 && posysalto>posysaltoant && (matriz[int(posxsalto/160)][int(posysalto/144)+1]!=0 || matriz[int((posxsalto+(sizey/10))/160)][int(posysalto/144)+1]!=0) && int(posysalto/144)+1==2){
            advGirl->setX(posxsalto);
            advGirl->setY(216);
            advGirl->setPosx(posxsalto);
            advGirl->setPosy(216);
            advGirl->setParabolico(false);
            view->centerOn(advGirl->x(),advGirl->y());
            times->stop();
            if(advGirl->get_direc()==true) advGirl->setPixmap(QPixmap(":/sprites personaje/Idle (1).png").scaled(sizey/5,sizey/5));
            else advGirl->setPixmap(QPixmap(":/sprites personaje/IdleL (1).png").scaled(sizey/5,sizey/5));
        }
        if(posysalto>=504 && (matriz[int(posxsalto/160)][int(posysalto/144)+1]!=0  || matriz[int((posxsalto+(sizey/10))/160)][int(posysalto/144)+1]!=0) && int(posysalto/144)+1==4){
            advGirl->setX(posxsalto);
            advGirl->setY(504);
            advGirl->setPosx(posxsalto);
            advGirl->setPosy(504);
            advGirl->setParabolico(false);
            view->centerOn(advGirl->x(),advGirl->y());
            times->stop();
            if(advGirl->get_direc()==true) advGirl->setPixmap(QPixmap(":/sprites personaje/Idle (1).png").scaled(sizey/5,sizey/5));
            else advGirl->setPixmap(QPixmap(":/sprites personaje/IdleL (1).png").scaled(sizey/5,sizey/5));
        }
    }
    else{
        if(posysalto>=216 && posysalto>posysaltoant && (matriz[int(posxsalto/160)+1][int(posysalto/144)+1]!=0 || matriz[int((posxsalto-(sizey/10))/160)+1][int(posysalto/144)+1]!=0) && int(posysalto/144)+1==2){
            advGirl->setX(posxsalto);
            advGirl->setY(216);
            advGirl->setPosx(posxsalto);
            advGirl->setPosy(216);
            advGirl->setParabolico(false);
            view->centerOn(advGirl->x(),advGirl->y());
            times->stop();
            if(advGirl->get_direc()==true) advGirl->setPixmap(QPixmap(":/sprites personaje/Idle (1).png").scaled(sizey/5,sizey/5));
            else advGirl->setPixmap(QPixmap(":/sprites personaje/IdleL (1).png").scaled(sizey/5,sizey/5));
        }
        if(posysalto>=504 && (matriz[int(posxsalto/160)+1][int(posysalto/144)+1]!=0 || matriz[int((posxsalto-(sizey/10))/160)+1][int(posysalto/144)+1]!=0) && int(posysalto/144)+1==4){
            advGirl->setX(posxsalto);
            advGirl->setY(504);
            advGirl->setPosx(posxsalto);
            advGirl->setPosy(504);
            advGirl->setParabolico(false);
            view->centerOn(advGirl->x(),advGirl->y());
            times->stop();
            if(advGirl->get_direc()==true) advGirl->setPixmap(QPixmap(":/sprites personaje/Idle (1).png").scaled(sizey/5,sizey/5));
            else advGirl->setPixmap(QPixmap(":/sprites personaje/IdleL (1).png").scaled(sizey/5,sizey/5));
        }
    }
}

void MainWindow::caida()
{
    posysalto = (sizey-advGirl->get_posy())-0.5*a*nc*(T)*nc*(T);
    nc++;
    advGirl->setY(sizey-posysalto);
    if(advGirl->get_direc()==true){
        if((sizey-posysalto)>=504 && (matriz[int(advGirl->get_posx()/160)][int((sizey-posysalto)/144)+1]!=0  || matriz[int((advGirl->get_posx()+(sizey/10))/160)][int((sizey-posysalto)/144)+1]!=0) && int((sizey-posysalto)/144)+1==4){
            advGirl->setY(504);
            advGirl->setPosy(504);
            view->centerOn(advGirl->x(),advGirl->y());
            cae=false;
            timec->stop();
            if(advGirl->get_direc()==true) advGirl->setPixmap(QPixmap(":/sprites personaje/Idle (1).png").scaled(sizey/5,sizey/5));
            else advGirl->setPixmap(QPixmap(":/sprites personaje/IdleL (1).png").scaled(sizey/5,sizey/5));
        }
    }
    else{
        if((sizey-posysalto)>=504 && (matriz[int(advGirl->get_posx()/160)+1][int((sizey-posysalto)/144)+1]!=0 || matriz[int((advGirl->get_posx()-(sizey/10))/160)+1][int((sizey-posysalto)/144)+1]!=0) && int((sizey-posysalto)/144)+1==4){
            advGirl->setY(504);
            advGirl->setPosy(504);
            view->centerOn(advGirl->x(),advGirl->y());
            cae=false;
            timec->stop();
            if(advGirl->get_direc()==true) advGirl->setPixmap(QPixmap(":/sprites personaje/Idle (1).png").scaled(sizey/5,sizey/5));
            else advGirl->setPixmap(QPixmap(":/sprites personaje/IdleL (1).png").scaled(sizey/5,sizey/5));
        }
    }
}

void MainWindow::deslizando()
{
    if(advGirl->get_direc()==true){
        advGirl->deslizar();
        advGirl->setPosx(posfric+vxo*nf*T+0.5*nf*T*T*(F-K)); //F->Fuerza, K->Fricción
        nf++;
        advGirl->setX(advGirl->get_posx());
        if(nf%2==0) view->centerOn(advGirl->x(),advGirl->y());
        if(matriz[int(advGirl->get_posx()/160)][int(advGirl->get_posy()/144)+1]==0 && (int(advGirl->get_posy()/144)+1==4 || int(advGirl->get_posy()/144)+1==2) && matriz[int((advGirl->get_posx()+sizey/5)/160)][int(advGirl->get_posy()/144)+1]==0){
            cae=true;
            times->stop();
            nf=0;
            advGirl->setDeslizo(true);
            advGirl->deslizar();
            nc=0;
            posysalto=advGirl->get_posy();
            timec=new QTimer;
            timec->start(2);
            connect(timec,SIGNAL(timeout()),this,SLOT(caida()));
        }
        if(nf==85){
            times->stop();
            nf=0;
            advGirl->setDeslizo(true);
            advGirl->deslizar();
        }
   }
    else{
        advGirl->deslizar();
        advGirl->setPosx(posfric-vxo*nf*T-0.5*nf*T*T*(F-K)); //F->Fuerza, K->Fricción
        nf++;
        advGirl->setX(advGirl->get_posx());
        if(nf%2==0) view->centerOn(advGirl->x(),advGirl->y());
        if(matriz[int(advGirl->get_posx()/160)+1][int(advGirl->get_posy()/144)+1]==0 && (int(advGirl->get_posy()/144)+1==4 || int(advGirl->get_posy()/144)+1==2) && matriz[int((advGirl->get_posx()-(sizey/10))/160)+1][int(advGirl->get_posy()/144)+1]==0){
            cae=true;
            times->stop();
            nf=0;
            advGirl->setDeslizo(true);
            advGirl->deslizar();
            nc=0;
            posysalto=advGirl->get_posy();
            timec=new QTimer;
            timec->start(2);
            connect(timec,SIGNAL(timeout()),this,SLOT(caida()));
        }
        if(nf==70){
            times->stop();
            nf=0;
            advGirl->setDeslizo(true);
            advGirl->deslizar();
        }
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
