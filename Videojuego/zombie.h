#ifndef ZOMBIE_H
#define ZOMBIE_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QString>

class zombie : public QObject, public QGraphicsPixmapItem
{
public:
    zombie(float posmx, float posmy,int tam);
    void movimientod();
    void movimientoi();
    void ataque();
    void morir();
    bool getImpacto() const;
    void setImpacto(bool value);
    float getX() const;
    void setX(float value);
    bool getVivo() const;
    void setVivo(bool value);
    bool getDirec() const;
    void setDirec(bool value);
    bool getMov() const;
    void setMov(bool value);
    float getY() const;
    void setY(float value);

private:
    QString spriZombie[54];
    int size=0, contmov=34, contmue=0,contatt=14;
    bool impacto=false,direc=false,vivo=true,mov=true;
    float x=0,y=0;
};

#endif // ZOMBIE_H
