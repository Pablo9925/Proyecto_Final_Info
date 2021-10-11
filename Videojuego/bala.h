#ifndef BALA_H
#define BALA_H

#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>

class bala: public QGraphicsItem
{
public:
    bala(float x, float y);
    QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option, QWidget *widget);
    void actualiza_posR();
    void actualiza_posL();
    float get_posx();
private:
    float posbalax, posbalay;
};

#endif // BALA_H
