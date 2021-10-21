#include "maza.h"

maza::maza(float posmx, float posmy,int tam)

{
    size=tam/2;
    x=posmx;
    y=posmy;

    setPixmap(QPixmap(":/escena/maza.png").scaled(size,size));
    setPos(x,y);
    r=x;

}

void maza::movimiento()
{
    tiempomov=new QTimer;
    tiempomov->start(50);

    connect(tiempomov,SIGNAL(timeout()),this,SLOT(mov()));
}

void maza::mov()
{
    x=y*n;
    y=x*n;
    n++;
    setPixmap(QPixmap(":/escena/maza.png").scaled(size,size));
    setPos(x,y);
}
