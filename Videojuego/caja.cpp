#include "caja.h"

caja::caja(int posx, int posy, int tam)
{
    poscx=posx;
    poscy=posy;
    size=tam/2;
    setPixmap(QPixmap(":/escena/Crate.png").scaled(size,size));
    setPos(poscx,poscy);
}

bool caja::ammo()
{
    int n, x;
    n=rand();
    x=pa*(RAND_MAX+1)-1;
    return n<=x;
}

int caja::getVida() const
{
    return vida;
}

void caja::setVida(int value)
{
    vida = value;
}

bool caja::getTipo() const
{
    return tipo;
}

void caja::setTipo(bool value)
{
    tipo = value;
}

bool caja::getDestruc() const
{
    return destruc;
}

void caja::setDestruc(bool value)
{
    destruc = value;
}

bool caja::getItemdado() const
{
    return itemdado;
}

void caja::setItemdado(bool value)
{
    itemdado = value;
}
