#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <QTimer>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QString>
#include <QGraphicsEllipseItem>
#include <QList>
#include "bala.h"

class personaje : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    personaje(int tamv);
    ~personaje();
    bala* getBullet();
    float get_posx();
    float get_posy();
    bool get_direc();
    void mov_izq();
    void mov_der();
    void slide();
    void jump();
    void shot();
    void melee();

public slots:
    void disparar();

private:
    bala *bullet;
    QTimer *timeshot;
    QString spriPers[35];
    QString spriPersL[35];
    bool derecha=true;
    int vidas=3, ammo=0, damage=1, puntaje=0, size, contp=30, conts=31;
    float posx=60, posy=180;

};

#endif // PERSONAJE_H
