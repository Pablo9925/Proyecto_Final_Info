#ifndef MENUPAUSA_H
#define MENUPAUSA_H

#include <QWidget>
#include "personaje.h"

namespace Ui {
class menupausa;
}

class menupausa : public QWidget
{
    Q_OBJECT

public:
    explicit menupausa(QWidget *parent = nullptr);
    void actualizacion(int vid,int muni,int puntaje,int nivel);
    ~menupausa();

private:
    Ui::menupausa *ui;
    int vida,municion,puntos,level;
};

#endif // MENUPAUSA_H
