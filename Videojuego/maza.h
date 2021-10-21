#ifndef MAZA_H
#define MAZA_H
#include "math.h"
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QString>
#include <QTimer>

class maza :public QObject, public QGraphicsPixmapItem
{
public:
    maza(float posmx, float posmy,int tam);
    void movimiento();
public slots:
    void simular();
private:
    int n=0;
    float t=0.5,x,y,w=20,r=25;
    int size;
    QTimer *tiempomov;
};

#endif // MAZA_H
