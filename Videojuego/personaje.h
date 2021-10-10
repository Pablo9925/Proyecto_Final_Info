#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QString>

class personaje : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    personaje(int tamv);
    void mov_izq();
    void mov_der();
    void slide();
    void jump();
    void shot();
    void melee();

private:
    QString spriPers[35];
    QString spriPersL[35];
    int vidas=3, ammo=0, damage=1, puntaje=0, size, contp;
    float posx=60, posy=180;

};

#endif // PERSONAJE_H
