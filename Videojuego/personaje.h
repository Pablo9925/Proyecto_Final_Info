#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <QTimer>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QString>
#include <QGraphicsEllipseItem>
#include <QList>
#include "bala.h"
#include <math.h>
#include <QGraphicsScene>
#include <QFile>
#include <QTextStream>
#include "fracasado.h"
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
    int get_damage();
    bool getParabolico() const;
    bool getDeslizo() const;
    void setDeslizo(bool value);
    void set_ammo(int muni);
    void setParabolico(bool value);
    void setPosy(float value);
    void setPosx(float value);
    void mov_izq();
    void mov_der();
    void slide();
    void jump();
    void shot();
    void melee();
    void deslizar();
    void morir();
    void guardar(QString persona);
    int getVidas() const;
    void setVidas(int value);
    int getPuntaje() const;
    void setPuntaje(int value);
    bool getMuerte() const;
    void setMuerte(bool value);
    void cargando();
    void setPersonaje1(const QString &value);
    void setPersonaje2(const QString &value);
    QString recogerunalinea(int linea, QString a);
    bool getAnimadisp() const;
    int getNivel() const;
    void setNivel(int value);
    void setMultij(bool value);
    bool getCerrarmain() const;
    void moristesmen();
    void setCerrarmain(bool value);

public slots:
    void disparar();
    void apunalar();
    void animacionsalto();
    void muerte_anima();

private:
    bala *bullet;
    QTimer *timeshot;
    QTimer *timesalt;
    QTimer *timepunal;
    QTimer *timemuer;
    QString spriPers[35];
    QString spriPersL[35];
    QString personaje1;
    QString personaje2;
    bool derecha=true, meleeAct=false,parabolico=false, deslizo=true,muerte=false,animadisp=false,multij=false,cerrarmain=false,cerrarfracasado=true;
    int vidas=3, ammo=6, damage=1, puntaje=0, size, contp=30, conts=31, contb=16 ,contjump=8,contmuer=0,nivel=1;
    float posx=60, posy;
};

#endif // PERSONAJE_H
