#include "bala.h"

bala::bala(float x, float y)
{
    posbalax=x;
    posbalay=y;
}

QRectF bala::boundingRect() const
{
    return QRectF(-5,-5,10,10);
}

void bala::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(QColor(0,0,0));
    painter->drawEllipse(boundingRect());
}

void bala::actualiza_posR()
{
    setX(posbalax);
    posbalax+=15;
}

void bala::actualiza_posL()
{
    setX(posbalax);
    posbalax-=15;
}

float bala::get_posx()
{
    return posbalax;
}
