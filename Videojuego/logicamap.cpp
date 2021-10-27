#include "logicamap.h"

logicamap::logicamap(int col, int fil)
{
    srand(time(NULL));
    x=col;
    y=fil;
}

int **logicamap::generar_mapa()
{
    matriz = new int * [x];
    for(int col=0;col<x;col++){
        matriz[col] = new int [y];
        for(int fil=0;fil<y;fil++){
            if(fil==2 && aleatorio1() && col!=0 && col!=1 && col!=2){
                matriz[col][fil]=1;
            }
            else if(fil==0 || fil==1 || fil==3) matriz[col][fil]=0;
            else if ((fil==4 && aleatorio2()) || (fil==4 && col%2==0) || (fil==4 && col==1) || col+1==x){
                matriz[col][fil]=2;
                if (aleatorioItem()) matriz[col][3]=3;
            }
            else matriz[col][fil]=0;

            if(fil==4 && col==x-1) matriz[col][3]=4;
        }
    }
    return matriz;
}

logicamap::~logicamap()
{
    delete [] matriz;
}

bool logicamap::aleatorio1()
{
    int n, x;
    n=rand();
    x=p1*(RAND_MAX+1)-1;
    return n<=x;
}

bool logicamap::aleatorio2()
{
    int n, x;
    n=rand();
    x=p2*(RAND_MAX+1)-1;
    return n<=x;
}

bool logicamap::aleatorioItem()
{
    int n, x;
    n=rand();
    x=pi*(RAND_MAX+1)-1;
    return n<=x;
}
