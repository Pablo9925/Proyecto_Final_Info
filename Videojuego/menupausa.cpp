#include "menupausa.h"
#include "ui_menupausa.h"

menupausa::menupausa(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::menupausa)
{
    ui->setupUi(this);
}

void menupausa::actualizacion(int vid, int muni, int puntaje, int nivel)
{
    vida=vid;
    municion=muni;
    puntos=puntaje;
    level=nivel;
    ui->municion->setNum(municion);
    ui->vida->setNum(vida);
}

menupausa::~menupausa()
{
    delete ui;
}
