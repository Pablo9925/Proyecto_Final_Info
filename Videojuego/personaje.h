#ifndef PERSONAJE_H
#define PERSONAJE_H
#include <QTimer>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QString>
#include <QGraphicsEllipseItem>
#include <QList>
class personaje : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    personaje(int tamv);
    void mov_izq();
    void mov_der();
    void slide();
    void jump();

    void melee();
    float getPosx() const;

public slots:
    void shot();
private:
    QTimer *time2;
    QString spriPers[35];
    QString spriPersL[35];

    int vidas=3, ammo=0, damage=1, puntaje=0, size, contp,contp2=31;
    float posx=60, posy=180;

};

#endif // PERSONAJE_H
