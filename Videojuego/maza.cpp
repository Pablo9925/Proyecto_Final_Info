#include "maza.h"

maza::maza(float posmx, float posmy,int tam)
{
    size=tam/2;
    auxx=posmx;
    auxy=posmy;
    setPixmap(QPixmap(":/escena/maza.png").scaled(size,size));
    setPos(auxx,auxy);
}

void maza::movimiento()
{
    if (the>=360) the=0;
    x=auxx+r*cosf(-1*the*PI/180);
    y=auxy+r*sinf(-1*the*PI/180);
    the+=1;
    setPos(x,y);
}

bool maza::getImpacto() const
{
    return impacto;
}

void maza::setImpacto(bool value)
{
    impacto = value;
}

float maza::getX() const
{
    return x;
}
