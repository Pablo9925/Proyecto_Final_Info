#ifndef CAJA_H
#define CAJA_H

#include <QObject>
#include <QGraphicsPixmapItem>

class caja : public QObject, public QGraphicsPixmapItem
{
public:
    caja(int posx,int posy,int tam);
    bool ammo();
    int getVida() const;
    void setVida(int value);
    bool getTipo() const;
    void setTipo(bool value);
    bool getDestruc() const;
    void setDestruc(bool value);
    bool getItemdado() const;
    void setItemdado(bool value);
    bool getItemgen() const;
    void setItemgen(bool value);

private:
    float pa=0.7;
    bool tipo,destruc=false,itemdado=false,itemgen=false;
    int poscx=0,poscy=0,size=0,vida=2;
};

#endif // CAJA_H
