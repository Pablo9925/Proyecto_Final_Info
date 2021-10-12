#include "map.h"

map::map(int tamx, int tamy)
{
    sizex=tamx/columnas;
    sizey=tamy/filas;

    mapa[0]=":/escena/Tile (2).png";
    mapa[1]=":/escena/Tile (15).png";
    mapa[2]=":/escena/DeadBush.png";
    mapa[3]=":/escena/TombStone (2).png";
}

void map::setup_tipo(int tipo)
{
    if(tipo==3){
        if(aleatorio()) setPixmap(QPixmap(mapa[2]).scaled(sizey/2,sizey/2));
        else setPixmap(QPixmap(mapa[3]).scaled(sizey/2,sizey/2));
    }
    else if(tipo==2) setPixmap(QPixmap(mapa[0]).scaled(sizex,sizey/2));
    else if(tipo==1) setPixmap(QPixmap(mapa[1]).scaled(sizex,sizey/2));
}

bool map::aleatorio()
{
    int n, x;
    n=rand();
    x=p*(RAND_MAX+1)-1;
    return n<=x;
}

