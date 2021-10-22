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
    float x=0,y=0,auxy3=0,ay=0,vx=10,vy=20,t=1,N=0,auxx=0,auxy=0,acc=1,cont2=0,x2=0,y2=0;
};

#endif // MAZA_H
