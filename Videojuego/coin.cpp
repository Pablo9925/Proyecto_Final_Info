#include "coin.h"

coin::coin(int posx, int posy, int tam)
{
    size=tam/2;
    setPixmap(QPixmap(":/escena/coin.png").scaled(size,size));
    setPos(posx,posy);
}

int coin::getPuntos() const
{
    return puntos;
}

bool coin::getMonedada() const
{
    return monedada;
}

void coin::setMonedada(bool value)
{
    monedada = value;
}
