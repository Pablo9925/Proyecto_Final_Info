#ifndef MAP_H
#define MAP_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QString>

#define columnas 8
#define filas 5

class map : public QObject, public QGraphicsPixmapItem
{
public:
    map(int tamx,int tamy);
    void setup_tipo(int tipo);
    void resize(int x,int y);
    float p=0.5;
private:
    bool aleatorio();
    QString mapa[4];
    int sizex,sizey,contm=1;
};

#endif // MAP_H
