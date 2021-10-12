#ifndef LOGICAMAP_H
#define LOGICAMAP_H

#include <cstdlib>
#include <time.h>

class logicamap
{
public:
    logicamap(int col, int fil);
    int **generar_mapa();
    ~logicamap();
    float p1=0.3;
    float p2=0.8;
    float pi=0.3;
private:
    bool aleatorio1(); //Para bloques áereos
    bool aleatorio2(); //Para suelo
    bool aleatorioItem();
    int ** matriz;
    int x,y;
};

#endif // LOGICAMAP_H
