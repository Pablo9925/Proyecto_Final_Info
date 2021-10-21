#include "maza.h"

maza::maza(float posmx, float posmy,int tam)
{
    size=tam/2;
    xc=posmx;
    yc=posmy;
    x=r+xc;
    y=288;
    setPixmap(QPixmap(":/escena/maza.png").scaled(size,size));
    setPos(x,y);
}

void maza::movimiento()
{
    dist = sqrt((pow((xc-x),2)+pow((yc-y),2)));
    ax+=G*(500000*(xc-x)/pow(dist,3));
    ay+=G*(500000*(yc-y)/pow(dist,3));
    vx=vx+(ax*dt);
    vy=vy+(ay*dt);
    x=x+(vx*dt);
    y=y+(vy*dt);
    setPos(x,y);
}
