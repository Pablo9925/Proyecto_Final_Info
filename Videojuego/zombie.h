#ifndef ZOMBIE_H
#define ZOMBIE_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QString>
#include <QTimer>

class zombie : public QObject, public QGraphicsPixmapItem
{
public:
    zombie(float posmx, float posmy,int tam);
    ~zombie();
    void movimientod();
    void movimientoi();
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
    bool getAtaque() const;
    void setAtaque(bool value);

    QString spriZombie[54];

private:
    QTimer *timeatt;
    int size=0, contmov=34;
    bool impacto=false,direc=false,vivo=true,mov=true,ataque=false;
    float x=0,y=0;
};

#endif // ZOMBIE_H
