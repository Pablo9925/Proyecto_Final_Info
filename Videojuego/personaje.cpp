#include "personaje.h"

personaje::personaje(int tamv)
{
    spriPers[0]=":/sprites personaje/Dead (1).png";
    spriPers[1]=":/sprites personaje/Dead (2).png";
    spriPers[2]=":/sprites personaje/Dead (3).png";
    spriPers[3]=":/sprites personaje/Dead (4).png";
    spriPers[4]=":/sprites personaje/Dead (5).png";
    spriPers[5]=":/sprites personaje/Dead (6).png";
    spriPers[6]=":/sprites personaje/Dead (7).png";
    spriPers[7]=":/sprites personaje/Idle (1).png";
    spriPers[8]=":/sprites personaje/Jump (1).png";
    spriPers[9]=":/sprites personaje/Jump (2).png";
    spriPers[10]=":/sprites personaje/Jump (3).png";
    spriPers[11]=":/sprites personaje/Jump (4).png";
    spriPers[12]=":/sprites personaje/Jump (5).png";
    spriPers[13]=":/sprites personaje/Jump (6).png";
    spriPers[14]=":/sprites personaje/Jump (7).png";
    spriPers[15]=":/sprites personaje/Jump (8).png";
    spriPers[16]=":/sprites personaje/Melee (1).png";
    spriPers[17]=":/sprites personaje/Melee (2).png";
    spriPers[18]=":/sprites personaje/Melee (3).png";
    spriPers[19]=":/sprites personaje/Melee (4).png";
    spriPers[20]=":/sprites personaje/Melee (5).png";
    spriPers[21]=":/sprites personaje/Melee (6).png";
    spriPers[22]=":/sprites personaje/Melee (7).png";
    spriPers[23]=":/sprites personaje/Run (1).png";
    spriPers[24]=":/sprites personaje/Run (2).png";
    spriPers[25]=":/sprites personaje/Run (3).png";
    spriPers[26]=":/sprites personaje/Run (4).png";
    spriPers[27]=":/sprites personaje/Run (5).png";
    spriPers[28]=":/sprites personaje/Run (6).png";
    spriPers[29]=":/sprites personaje/Run (7).png";
    spriPers[30]=":/sprites personaje/Run (8).png";
    spriPers[31]=":/sprites personaje/Shoot (1).png";
    spriPers[32]=":/sprites personaje/Shoot (2).png";
    spriPers[33]=":/sprites personaje/Shoot (3).png";
    spriPers[34]=":/sprites personaje/Slide (1).png";

    spriPersL[0]=":/sprites personaje/DeadL (1).png";
    spriPersL[1]=":/sprites personaje/DeadL (2).png";
    spriPersL[2]=":/sprites personaje/DeadL (3).png";
    spriPersL[3]=":/sprites personaje/DeadL (4).png";
    spriPersL[4]=":/sprites personaje/DeadL (5).png";
    spriPersL[5]=":/sprites personaje/DeadL (6).png";
    spriPersL[6]=":/sprites personaje/DeadL (7).png";
    spriPersL[7]=":/sprites personaje/IdleL (1).png";
    spriPersL[8]=":/sprites personaje/JumpL (1).png";
    spriPersL[9]=":/sprites personaje/JumpL (2).png";
    spriPersL[10]=":/sprites personaje/JumpL (3).png";
    spriPersL[11]=":/sprites personaje/JumpL (4).png";
    spriPersL[12]=":/sprites personaje/JumpL (5).png";
    spriPersL[13]=":/sprites personaje/JumpL (6).png";
    spriPersL[14]=":/sprites personaje/JumpL (7).png";
    spriPersL[15]=":/sprites personaje/JumpL (8).png";
    spriPersL[16]=":/sprites personaje/MeleeL (1).png";
    spriPersL[17]=":/sprites personaje/MeleeL (2).png";
    spriPersL[18]=":/sprites personaje/MeleeL (3).png";
    spriPersL[19]=":/sprites personaje/MeleeL (4).png";
    spriPersL[20]=":/sprites personaje/MeleeL (5).png";
    spriPersL[21]=":/sprites personaje/MeleeL (6).png";
    spriPersL[22]=":/sprites personaje/MeleeL (7).png";
    spriPersL[23]=":/sprites personaje/RunL (1).png";
    spriPersL[24]=":/sprites personaje/RunL (2).png";
    spriPersL[25]=":/sprites personaje/RunL (3).png";
    spriPersL[26]=":/sprites personaje/RunL (4).png";
    spriPersL[27]=":/sprites personaje/RunL (5).png";
    spriPersL[28]=":/sprites personaje/RunL (6).png";
    spriPersL[29]=":/sprites personaje/RunL (7).png";
    spriPersL[30]=":/sprites personaje/RunL (8).png";
    spriPersL[31]=":/sprites personaje/ShootL (1).png";
    spriPersL[32]=":/sprites personaje/ShootL (2).png";
    spriPersL[33]=":/sprites personaje/ShootL (3).png";
    spriPersL[34]=":/sprites personaje/SlideL (1).png";

    size=tamv;
    posy=size*3/10;
    setPixmap(QPixmap(spriPers[7]).scaled(size/5,size/5));
}

personaje::~personaje()
{
    delete timeshot;
    delete timepunal;
    delete bullet;
}

bala *personaje::getBullet()
{
    return bullet;
}

float personaje::get_posx()
{
    return posx;
}

float personaje::get_posy()
{
    return posy;
}

bool personaje::get_direc()
{
    return derecha;
}

bool personaje::get_ActAttack()
{
    return meleeAct;
}

int personaje::get_ammo()
{
    return ammo;
}

void personaje::set_ammo(int muni)
{
    ammo=muni;
}

void personaje::mov_izq()
{
    if(contp>30 || contp<23) contp=30;
    setPixmap(QPixmap(spriPersL[contp]).scaled(size/5,size/5));
    derecha=false;
    contp--;
    posx-=20;
}

void personaje::mov_der()
{
    if(contp>30 || contp<23) contp=30;
    setPixmap(QPixmap(spriPers[contp]).scaled(size/5,size/5));
    derecha=true;
    contp--;
    posx+=20;
}
void personaje::shot()
{
    if(derecha==true) bullet=new bala(posx+size/5,posy);
    else bullet=new bala(posx-size/5,posy);
    timeshot = new QTimer;
    timeshot->start(100);
    connect(timeshot,SIGNAL(timeout()),this,SLOT(disparar()));
}

void personaje::melee()
{
    meleeAct=true;
    timepunal= new QTimer;
    timepunal->start(50);
    connect(timepunal,SIGNAL(timeout()),this,SLOT(apunalar()));
}

void personaje::disparar()
{
    if(derecha==true) setPixmap(QPixmap(spriPers[conts]).scaled(size/5,size/5));
    else setPixmap(QPixmap(spriPersL[conts]).scaled(size/5,size/5));
    conts++;
    if(conts==34){
        timeshot->stop();
        conts=31;
    }
}

void personaje::apunalar()
{
   if(derecha==true){
       setPixmap(QPixmap(spriPers[contb]).scaled(size/5,size/5));
   }
   else{
       setPixmap(QPixmap(spriPersL[contb]).scaled(size/5,size/5));
   }
   contb++;
   if(contb>=23){
       timepunal->stop();
       contb=16;
       meleeAct=false;
   }
}
