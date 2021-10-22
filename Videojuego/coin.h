#ifndef COIN_H
#define COIN_H

#include <QObject>
#include <QGraphicsPixmapItem>

class coin : public QObject, public QGraphicsPixmapItem
{
public:
    coin(int posx,int posy,int tam);
    int getPuntos() const;

private:
    int size=0,puntos=50;
};

#endif // COIN_H
