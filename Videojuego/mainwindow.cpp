#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),

    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setup_mainwindow();
    advGirl=new personaje(sizey);
    generar_mapa();
    advGirl->setPos(60,sizey*7/10); //Esa posición en y por la acumulación de la posición del personaje y la posición de los bloques del mapa
    escena->addItem(advGirl);
    advGirl->setPosy(sizey*7/10);
    view->setScene(escena);
    view->resize(sizex,sizey);
    this->resize(sizex,sizey);
    view->centerOn(advGirl->x(),504);
    bsound= new QMediaPlayer();
    csound= new QMediaPlayer();
    coinsound= new QMediaPlayer();
    ammosound= new QMediaPlayer();
    zsound= new QMediaPlayer();
    psound= new QMediaPlayer();
    cajasound= new QMediaPlayer();
    timemaz = new QTimer(this);
    timemaz->start(10);
    connect(timemaz,SIGNAL(timeout()),this,SLOT(movimiento_maza()));
    timez=new QTimer(this);
    timez->start(100);
    connect(timez,SIGNAL(timeout()),this,SLOT(movimiento_zombie()));
    pausa=new menupausa();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete advGirl;
    delete timemaz;
    delete time;
    delete timec;
    delete times;
    delete timez;
    delete timemorir;
    delete bsound;
    delete csound;
    delete coinsound;
    delete ammosound;
    delete zsound;
    delete psound;
    delete cajasound;
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
    ui->graphicsView->setGeometry(0,0,sizex,sizey);
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
                if(generar_caja()){
                    cajas.append(new caja(x*(sizex/columnas)+53,y*(sizey/filas),sizey/5));
                }
                else if(generar_moneda()){
                    monedas.append(new coin(x*(sizex/columnas)+53,y*(sizey/filas),sizey/5));
                }
                if(generar_maza()){
                   mazas.append((new maza(x*(sizex/columnas),y*(sizey/filas),sizey/5)));
                }
            }
            if(m_mapa[x][y]==2 && x!=0 && x!=1 && x!=2 && x!=columnas*15){
                if(generar_zombie()){
                   zombies.append((new zombie(x*(sizex/columnas),504,sizey)));
                }
            }
            matriz[x][y]=m_mapa[x][y];
            mapa[x][y] = new map(sizex,sizey);
            mapa[x][y]->setup_tipo(m_mapa[x][y]);
            mapa[x][y]->setX((sizex/columnas)*x);
            if(m_mapa[x][y]==3 || m_mapa[x][y]==4) mapa[x][y]->setY(((sizey/filas)*y)+(sizey/filas));
            else mapa[x][y]->setY(((sizey/(filas))*y)+(sizey/filas)/2);
            escena->addItem(mapa[x][y]);
        }
    }
    for(int i=0;i<monedas.size();i++){
        escena->addItem(monedas.at(i));
    }
    for(int j=0;j<cajas.size();j++){
        escena->addItem(cajas.at(j));
    }
    for(int j=0;j<mazas.size();j++){
        escena->addItem(mazas.at(j));
    }
    for(int j=0;j<zombies.size();j++){
        escena->addItem(zombies.at(j));
    }
}

bool MainWindow::generar_caja()
{
    int n, x;
    n=rand();
    if(advGirl->getNivel()/100<0.1) x=(p-advGirl->getNivel()/100)*(RAND_MAX+1)-1;
    else x=(p-0.1)*(RAND_MAX+1)-1;
    return n<=x;

}

bool MainWindow::generar_moneda()
{
    int n, x;
    n=rand();
    if(advGirl->getNivel()/100<0.1) x=(p+0.1-advGirl->getNivel()/100)*(RAND_MAX+1)-1;
    else x=(p)*(RAND_MAX+1)-1;
    return n<=x;
}

bool MainWindow::generar_maza()
{
    int n, x;
    n=rand();
    if(advGirl->getNivel()/100<0.1) x=(pm+advGirl->getNivel()/100)*(RAND_MAX+1)-1;
    else x=(pm+0.1)*(RAND_MAX+1)-1;
    return n<=x;
}

bool MainWindow::generar_zombie()
{
    int n, x;
    n=rand();
    if(advGirl->getNivel()/100<0.1) x=(pz+advGirl->getNivel()/100)*(RAND_MAX+1)-1;
    else x=(pz+0.1)*(RAND_MAX+1)-1;
    return n<=x;
}

void MainWindow::keyPressEvent(QKeyEvent *i)
{
    if(i->key()==Qt::Key_D){
        if(advGirl->getParabolico()==false && cae==false && advGirl->getDeslizo()==true && advGirl->getMuerte()==false){
            advGirl->mov_der();
            advGirl->setX(advGirl->x()+20);
            if(advGirl->collidesWithItem(l2)){
                advGirl->mov_izq();
                advGirl->setX(advGirl->x()-20);
                advGirl->setNivel(advGirl->getNivel()+1);
                advGirl->setPersonaje1(nombre);
                advGirl->guardar(nombre);
                close();
            }
            view->centerOn(advGirl->x(),504);
            if(matriz[int(advGirl->get_posx()/160)][int(advGirl->get_posy()/144)+1]==0 && (int(advGirl->get_posy()/144)+1==4 || int(advGirl->get_posy()/144)+1==2) && matriz[int((advGirl->get_posx()+sizey/7)/160)][int(advGirl->get_posy()/144)+1]==0){
                cae=true;
                nc=0;
                posysalto=advGirl->get_posy();
                timec=new QTimer;
                timec->start(2);
                connect(timec,SIGNAL(timeout()),this,SLOT(caida()));
            }
            for (int j=0;j<monedas.size() ;j++ ) {
                if(advGirl->collidesWithItem(monedas.at(j)) && monedas.at(j)->getMonedada()==false){
                    monedas.at(j)->setMonedada(true);
                    coinsound->setMedia(QUrl("qrc:/sonidos/Coins_Collecting_01_Sound_Effect_Mp3_315.mp3"));
                    coinsound->play();
                    advGirl->setPuntaje(advGirl->getPuntaje()+monedas.at(j)->getPuntos());
                    escena->removeItem(monedas.at(j));
                    monedas.removeAt(j);
                }
            }
        }
    }
    else if(i->key()==Qt::Key_A){
        if(advGirl->getParabolico()==false && cae==false && advGirl->getDeslizo()==true && advGirl->getMuerte()==false){
            advGirl->mov_izq();
            advGirl->setX(advGirl->x()-20);
            if(advGirl->collidesWithItem(l1)){
                advGirl->mov_der();
                advGirl->setX(advGirl->x()+20);
            }
            view->centerOn(advGirl->x(),504);
            if(matriz[int(advGirl->get_posx()/160)+1][int(advGirl->get_posy()/144)+1]==0 && (int(advGirl->get_posy()/144)+1==4 || int(advGirl->get_posy()/144)+1==2) && matriz[int((advGirl->get_posx()-(sizey/10))/160)+1][int(advGirl->get_posy()/144)+1]==0){
                cae=true;
                nc=0;
                posysalto=advGirl->get_posy();
                timec=new QTimer;
                timec->start(2);
                connect(timec,SIGNAL(timeout()),this,SLOT(caida()));
            }
            for (int j=0;j<monedas.size() ;j++ ) {
                if(advGirl->collidesWithItem(monedas.at(j)) && monedas.at(j)->getMonedada()==false){
                    monedas.at(j)->setMonedada(true);
                    coinsound->setMedia(QUrl("qrc:/sonidos/Coins_Collecting_01_Sound_Effect_Mp3_315.mp3"));
                    coinsound->play();
                    advGirl->setPuntaje(advGirl->getPuntaje()+monedas.at(j)->getPuntos());
                    escena->removeItem(monedas.at(j));
                }
            }
        }
    }
    else if(i->key()==Qt::Key_P){
         if(advGirl->getAnimadisp()==false && advGirl->get_ActAttack()==false && bulletAct==false && advGirl->get_ammo()>0 && advGirl->getParabolico()==false && advGirl->getDeslizo()==true && cae==false && advGirl->getMuerte()==false){
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
        if(advGirl->get_ActAttack()==false && advGirl->getParabolico()==false && cae==false && advGirl->getDeslizo()==true && advGirl->getMuerte()==false){
            advGirl->melee();
            csound->setMedia(QUrl("qrc:/sonidos/007137308_prev.mp3"));
            csound->play();
            for (int j=0;j<cajas.size() ;j++ ) {
                if(advGirl->collidesWithItem(cajas.at(j))){
                    if(cajas.at(j)->getVida()>0){
                        cajasound->setMedia(QUrl("qrc:/sonidos/caja.mp3"));
                        cajasound->play();
                        if(cajas.at(j)->getVida()==2) cajas.at(j)->setPixmap(QPixmap(":/escena/cratedes1.png").scaled(sizey/10,sizey/10));
                        else cajas.at(j)->setPixmap(QPixmap(":/escena/cratedes2.png").scaled(sizey/10,sizey/10));
                        cajas.at(j)->setVida(cajas.at(j)->getVida()-advGirl->get_damage());
                    }
                    else if(cajas.at(j)->getVida()==0 && cajas.at(j)->getItemgen()==false){
                        cajas.at(j)->setDestruc(true);
                        if(cajas.at(j)->ammo()==true){
                            cajas.at(j)->setTipo(true);
                            cajas.at(j)->setPixmap(QPixmap(":/escena/ammo.png").scaled(sizey/10,sizey/10));
                            cajas.at(j)->setItemgen(true);
                        }
                        else{
                            cajas.at(j)->setTipo(false);
                            cajas.at(j)->setPixmap(QPixmap(":/escena/vida.png").scaled(sizey/10,sizey/10));
                            cajas.at(j)->setItemgen(true);
                        }
                    }
                }
            }
        }
    }
    else if(i->key()==Qt::Key_W){
        if(advGirl->getParabolico()==false && cae==false && advGirl->getDeslizo()==true && salto==false && advGirl->getMuerte()==false){
            if((advGirl->get_direc()==true && advGirl->get_posx()<19000) || (advGirl->get_direc()==false && advGirl->get_posx()>160)){
                n=1;
                salto=true;
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
       if(advGirl->getParabolico()==false && cae==false && advGirl->getDeslizo()==true && advGirl->getMuerte()==false){
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
        if(advGirl->get_ActAttack()==false && advGirl->getParabolico()==false && advGirl->getMuerte()==false){
            for (int j=0;j<cajas.size() ;j++ ) {
                if(advGirl->collidesWithItem(cajas.at(j)) && cajas.at(j)->getDestruc()==true && cajas.at(j)->getItemdado()==false){
                    cajas.at(j)->setItemdado(true);
                    if(cajas.at(j)->getTipo()==true){
                        ammosound->setMedia(QUrl("qrc:/sonidos/008842199_prev.mp3"));
                        ammosound->setVolume(50);
                        ammosound->play();
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
    else if (i->key()==Qt::Key_M){
        if(pausa->getPausa()==false){
            pausa->setActivo(true);
            pausa->setPausa(true);
            advGirl->setMuerte(true);
            timemaz->stop();
            timez->stop();
            if(advGirl->getParabolico()==true) times->stop();
            pausa->actualizacion(advGirl->getVidas(),advGirl->get_ammo(),advGirl->getPuntaje(),advGirl->getNivel());
            pausa->show();
        }
        else{
            if(pausa->getActivo()==true) pausa->close();
            pausa->setPausa(false);
            advGirl->setMuerte(false);
            timemaz->start(10);
            timez->start(100);
            if(advGirl->getParabolico()==true) times->start(1);
        }
    }
}

void MainWindow::setNombre(const QString &value)
{
    nombre = value;
}

void MainWindow::cargar()
{
    advGirl->setPersonaje1(nombre);
    advGirl->cargando();
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
    for (int j=0;j<monedas.size() ;j++ ) {
        if(advGirl->collidesWithItem(monedas.at(j)) && monedas.at(j)->getMonedada()==false){
            monedas.at(j)->setMonedada(true);
            coinsound->setMedia(QUrl("qrc:/sonidos/Coins_Collecting_01_Sound_Effect_Mp3_315.mp3"));
            coinsound->play();
            advGirl->setPuntaje(advGirl->getPuntaje()+monedas.at(j)->getPuntos());
            escena->removeItem(monedas.at(j));
            monedas.removeAt(j);
        }
    }
    if(posysalto>720){
       times->stop();
       advGirl->setVidas(0);
       advGirl->setMuerte(true);
       if(multiplayer==true){

           advGirl->setPersonaje1(nombre2);
           advGirl->setPersonaje2(nombre2);
           advGirl->guardar(nombre2);
           advGirl->setMultij(true);
       }
       else{
           advGirl->setPersonaje1(nombre);
           advGirl->setPersonaje2(nombre2);
           advGirl->guardar(nombre);
       }
       timemaz->stop();
       timez->stop();
       advGirl->guardar(nombre);
       advGirl->moristesmen();
       if(pausa->getActivo()==true) pausa->close();
       close();
    }
    if(n%7==0) view->centerOn(advGirl->x(),504);
    if(advGirl->get_direc()==true){
        if(posysalto>=216 && posysalto>posysaltoant && (matriz[int(posxsalto/160)][int(posysalto/144)+1]!=0 || matriz[int((posxsalto+(sizey/10))/160)][int(posysalto/144)+1]!=0) && int(posysalto/144)+1==2){
            advGirl->setX(posxsalto);
            advGirl->setY(216);
            advGirl->setPosx(posxsalto);
            advGirl->setPosy(216);
            advGirl->setParabolico(false);
            salto=false;
            view->centerOn(advGirl->x(),504);
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
            salto=false;
            view->centerOn(advGirl->x(),504);
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
            salto=false;
            view->centerOn(advGirl->x(),504);
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
            salto=false;
            view->centerOn(advGirl->x(),504);
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
    for (int j=0;j<monedas.size() ;j++ ) {
        if(advGirl->collidesWithItem(monedas.at(j)) && monedas.at(j)->getMonedada()==false){
            monedas.at(j)->setMonedada(true);
            coinsound->setMedia(QUrl("qrc:/sonidos/Coins_Collecting_01_Sound_Effect_Mp3_315.mp3"));
            coinsound->play();
            advGirl->setPuntaje(advGirl->getPuntaje()+monedas.at(j)->getPuntos());
            escena->removeItem(monedas.at(j));
            monedas.removeAt(j);
        }
    }
    if(advGirl->get_direc()==true){
        if((sizey-posysalto)>=504 && (matriz[int(advGirl->get_posx()/160)][int((sizey-posysalto)/144)+1]!=0  || matriz[int((advGirl->get_posx()+(sizey/10))/160)][int((sizey-posysalto)/144)+1]!=0) && int((sizey-posysalto)/144)+1==4){
            advGirl->setY(504);
            advGirl->setPosy(504);
            view->centerOn(advGirl->x(),504);
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
            view->centerOn(advGirl->x(),504);
            cae=false;
            timec->stop();
            if(advGirl->get_direc()==true) advGirl->setPixmap(QPixmap(":/sprites personaje/Idle (1).png").scaled(sizey/5,sizey/5));
            else advGirl->setPixmap(QPixmap(":/sprites personaje/IdleL (1).png").scaled(sizey/5,sizey/5));
        }
    }
    if(sizey-posysalto>720){
        timec->stop();
        advGirl->setVidas(0);
        advGirl->setMuerte(true);
        if(multiplayer==true){
            advGirl->setPersonaje1(nombre2);
            advGirl->setPersonaje2(nombre2);
            advGirl->guardar(nombre2);
            advGirl->setMultij(true);
        }
        else{
            advGirl->setPersonaje1(nombre);
            advGirl->setPersonaje2(nombre2);
            advGirl->guardar(nombre);
        }
        advGirl->moristesmen();
        if(pausa->getActivo()==true) pausa->close();
        close();
    }
}

void MainWindow::movimiento_maza()
{
    for(int j=0;j<mazas.length();j++){
        if(mazas.at(j)->getX()<advGirl->get_posx()+sizex && mazas.at(j)->getX()>advGirl->get_posx()-sizex) mazas.at(j)->movimiento();
          if(mazas.at(j)->collidesWithItem(advGirl) && mazas.at(j)->getImpacto()==false){
              escena->removeItem(mazas.at(j));
              mazas.at(j)->setImpacto(true);
              advGirl->setVidas(advGirl->getVidas()-1);
              if(advGirl->getVidas()<=0){
                  advGirl->setMuerte(true);
                  if(multiplayer==true){
                       advGirl->setPersonaje1(nombre2);
                       advGirl->setPersonaje2(nombre2);
                       advGirl->setMultij(true);
                   }
                   else{
                       advGirl->setPersonaje1(nombre);
                        advGirl->setPersonaje2(nombre2);
                   }

                   advGirl->morir();
                   timemorir=new QTimer;
                   timemorir->start(1500);
                   connect(timemorir,SIGNAL(timeout()),this,SLOT(cerrar()));

                    if(advGirl->getCerrarmain()==true){
                        advGirl->setCerrarmain(false);
                        if(pausa->getActivo()==true) pausa->close();
                        close();

                    }
              }
              else{
                  psound->setMedia(QUrl("qrc:/sonidos/herida.mp3"));
                  psound->play();
              }
          }
    }
}

void MainWindow::movimiento_zombie()
{
    for(int j=0;j<zombies.length();j++){
        if(zombies.at(j)->getVivo()==true && zombies.at(j)->getDirec()==true && zombies.at(j)->getX()<advGirl->get_posx()+sizex && zombies.at(j)->getMov()==true){
            if(!zombies.at(j)->collidesWithItem(l2) && matriz[int((zombies.at(j)->getX()+(sizey/5)*(4/5)+60)/160)][int(zombies.at(j)->getY()/144)+1]!=0){
                zombies.at(j)->movimientod();
            }
            else zombies.at(j)->setDirec(false);
        }
        else if(zombies.at(j)->getVivo()==true && zombies.at(j)->getDirec()==false && zombies.at(j)->getX()>advGirl->get_posx()-sizex && zombies.at(j)->getMov()==true){
            if(!zombies.at(j)->collidesWithItem(l1) && matriz[int((zombies.at(j)->getX()-10)/160)][int(zombies.at(j)->getY()/144)+1]!=0){
                zombies.at(j)->movimientoi();
            }
            else zombies.at(j)->setDirec(true);
        }
        if(zombies.at(j)->getVivo()==true && advGirl->getDeslizo()==true && zombies.at(j)->collidesWithItem(advGirl) && zombies.at(j)->getImpacto()==false){
            zombies.at(j)->setMov(false);
            zombies.at(j)->setImpacto(true);
            zombies.at(j)->setAtaque(true);
            if(advGirl->getVidas()<=0){
                advGirl->setMuerte(true);
                advGirl->setPersonaje1(nombre);
                if(multiplayer==true){
                    advGirl->setPersonaje1(nombre2);
                    advGirl->setPersonaje2(nombre2);
                    advGirl->setMultij(true);
                }
                else{
                    advGirl->setPersonaje1(nombre);
                    advGirl->setPersonaje2(nombre2);
                }
                advGirl->morir();
                if(advGirl->getCerrarmain()==true){
                    timez->stop();
                    advGirl->setCerrarmain(false);
                    if(pausa->getActivo()==true) pausa->close();
                    close();
                }
            }
        }
        if(zombies.at(j)->getAtaque()==true){
            if(zombies.at(j)->getDirec()==true){
                zombies.at(j)->setPixmap(QPixmap(zombies.at(j)->spriZombie[contatt]).scaled((sizey/5)*4/5,sizey/5));
                contatt++;
            }
            else{
                zombies.at(j)->setPixmap(QPixmap(zombies.at(j)->spriZombie[contatt+7]).scaled((sizey/5)*4/5,sizey/5));
                contatt++;
            }
            contatt++;
            if(contatt>6){
                contatt=0;
                zombies.at(j)->setImpacto(false);
                zombies.at(j)->setMov(true);
                zombies.at(j)->setAtaque(false);
                if(zombies.at(j)->collidesWithItem(advGirl)){
                    if(advGirl->getVidas()>0){
                        psound->setMedia(QUrl("qrc:/sonidos/herida.mp3"));
                        psound->play();
                    }
                    advGirl->setVidas(advGirl->getVidas()-1);
                }
            }
        }
        if(zombies.at(j)->getVivo()==false){
            if(zombies.at(j)->getDirec()==true){
                zombies.at(j)->setPixmap(QPixmap(zombies.at(j)->spriZombie[contmue]).scaled((sizey/5)*4/5,sizey/5));
                contmue++;
            }
            else{
                zombies.at(j)->setPixmap(QPixmap(zombies.at(j)->spriZombie[contmue+10]).scaled((sizey/5)*4/5,sizey/5));
                contmue++;
            }
            contatt++;
            if(contmue>23){
                contmue=14;
                escena->removeItem(zombies.at(j));
                zombies.removeAt(j);
            }
        }
    }
}

void MainWindow::setMultiplayer(bool value)
{
    multiplayer = value;
}

void MainWindow::cerrar()
{
    close();
}

void MainWindow::setNombre2(const QString &value)
{
    nombre2 = value;
}

void MainWindow::deslizando()
{
    if(advGirl->get_direc()==true){
        advGirl->deslizar();
        advGirl->setPosx(posfric+vxo*nf*T+0.5*nf*T*T*(F-K)); //F->Fuerza, K->Fricción
        nf++;
        advGirl->setX(advGirl->get_posx());
        if(nf%2==0) view->centerOn(advGirl->x(),504);
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
        if(nf==120){
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
        if(nf%2==0) view->centerOn(advGirl->x(),504);
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
        if(nf==120){
            times->stop();
            nf=0;
            advGirl->setDeslizo(true);
            advGirl->deslizar();
        }
    }
    for (int j=0;j<monedas.size() ;j++ ) {
        if(advGirl->collidesWithItem(monedas.at(j)) && monedas.at(j)->getMonedada()==false){
            monedas.at(j)->setMonedada(true);
            coinsound->setMedia(QUrl("qrc:/sonidos/Coins_Collecting_01_Sound_Effect_Mp3_315.mp3"));
            coinsound->play();
            advGirl->setPuntaje(advGirl->getPuntaje()+monedas.at(j)->getPuntos());
            escena->removeItem(monedas.at(j));
            monedas.removeAt(j);
        }
    }
}

void MainWindow::movimientobala()
{
    if(direc==true) advGirl->getBullet()->actualiza_posR();
    else advGirl->getBullet()->actualiza_posL();
    for (int j=0;j<cajas.size() ;j++ ) {
        if(advGirl->getBullet()->collidesWithItem(cajas.at(j))){
            cajasound->setMedia(QUrl("qrc:/sonidos/caja.mp3"));
            cajasound->play();
            cajas.at(j)->setVida(0);
            cajas.at(j)->setDestruc(true);
            if(cajas.at(j)->ammo()==true){
                cajas.at(j)->setTipo(true);
                cajas.at(j)->setPixmap(QPixmap(":/escena/ammo.png").scaled(sizey/10,sizey/10));
            }
            else{
                cajas.at(j)->setTipo(false);
                cajas.at(j)->setPixmap(QPixmap(":/escena/vida.png").scaled(sizey/10,sizey/10));
            }
            time->stop();
            escena->removeItem(advGirl->getBullet());
            bulletAct=false;
            cajas.at(j)->setItemgen(true);
        }
    }
    for (int i=0;i<zombies.size() ;i++ ) {
        if(advGirl->getBullet()->collidesWithItem(zombies.at(i))){
            zsound->setMedia(QUrl("qrc:/sonidos/zombie-moan-moan.mp3"));
            zsound->play();
            zombies.at(i)->setVivo(false);
            time->stop();
            escena->removeItem(advGirl->getBullet());
            bulletAct=false;
            advGirl->setPuntaje(advGirl->getPuntaje()+2);
        }

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
}


