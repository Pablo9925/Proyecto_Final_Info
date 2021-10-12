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
    bool get_ActAttack();
    int get_ammo();
    void set_ammo(int muni);
    void mov_izq();
    void mov_der();
    void slide();
    void jump();
    void shot();
    void melee();

public slots:
    void disparar();
    void apunalar();

private:
    bala *bullet;
    QTimer *timeshot;
    QTimer *timepunal;
    QString spriPers[35];
    QString spriPersL[35];
    bool derecha=true, meleeAct=false;
    int vidas=3, ammo=6, damage=1, puntaje=0, size, contp=30, conts=31, contb=16;
    float posx=60, posy;

};

#endif // PERSONAJE_H
