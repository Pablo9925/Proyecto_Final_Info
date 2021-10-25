#include "menupausa.h"
#include "ui_menupausa.h"

menupausa::menupausa(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::menupausa)
{
    ui->setupUi(this);
    chica=new personaje(15);
    ui->municion->setNum(chica->get_ammo());
    ui->vida->setNum(chica->getVidas());
}

menupausa::~menupausa()
{
    delete ui;
    delete chica;
}
