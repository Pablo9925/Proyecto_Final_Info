#ifndef MAZA_H
#define MAZA_H
#include "math.h"
#include <QObject>
#include <QGraphicsPixmapItem>
# define PI 3.14159265

class maza :public QObject, public QGraphicsPixmapItem
{
public:
    maza(float posmx, float posmy,int tam);
    void movimiento();
    bool getImpacto() const;
    void setImpacto(bool value);
    float getX() const;

private:
    int size=0;
    bool impacto=false;
    float x=0,y=0,auxx=0,auxy=0,r=240,the=0;
};

#endif // MAZA_H
