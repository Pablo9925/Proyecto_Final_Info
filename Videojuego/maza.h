#ifndef MAZA_H
#define MAZA_H
#include "math.h"
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
# define PI 3.14159265359

class maza :public QObject, public QGraphicsPixmapItem
{
public:
    maza(float posmx, float posmy,int tam);
    void movimiento();
private:
    int size=0;
    float x=0,y=0,auxx=0,auxy=0,r=240,the=0;
};

#endif // MAZA_H
