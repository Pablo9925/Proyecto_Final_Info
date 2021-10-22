#include "maza.h"

maza::maza(float posmx, float posmy,int tam)
{
    size=tam/2;
    x=posmx;
    y=288;
    auxx=x;
    auxy=y;
    ay=y;
    auxy3=y;
    setPixmap(QPixmap(":/escena/maza.png").scaled(size,size));
    setPos(x,y);
}

void maza::movimiento()
{
    /*dist = sqrt((pow((xc-x),2)+pow((yc-y),2)));
    ax+=G*(500000*(xc-x)/pow(dist,3));
    ay+=G*(500000*(yc-y)/pow(dist,3));
    vx=vx+(ax*dt);
    vy=vy+(ay*dt);
    x=x+(vx*dt);
    y=y+(vy*dt);*/
    if (y<=ay){
        cont2=0;
        x =auxx+vx*N*(t); //salto a la derecha
        y = auxy-(vy*N*(t)-0.5*acc*N*(t)*N*(t));
        N++;
        setPos(x,y);
        x2=x;
        y2=y;
        auxy3=y;


    }
    else{
        N=0;
        x2 =x-vx*cont2*(t); //salto a la derecha
        y2 = auxy3+(vy*cont2*(t)-0.5*acc*cont2*(t)*cont2*(t));
        cont2++;
        auxx=x2;
        y=y2;

        setPos(x2,y2);
    }


}
