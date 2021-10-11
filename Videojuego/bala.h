#ifndef BALA_H
#define BALA_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QString>
#include<personaje.h>
class bala
{
public:
    bala();
private:
    QString spritbala[1];
    float posbalax=60, posbalay=180;
};

#endif // BALA_H
