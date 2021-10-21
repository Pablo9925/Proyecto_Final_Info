#ifndef MAZA_H
#define MAZA_H
#include "math.h"
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>

class maza :public QObject, public QGraphicsPixmapItem
{
public:
    maza(float posmx, float posmy,int tam);
    void movimiento();
private:
    int size=0;
    float dt=0.1,x=0,y=0,xc=0,yc=0,r=2,ax=0,ay=0,vx=0,vy=0,G=1,dist=0;
};

#endif // MAZA_H
