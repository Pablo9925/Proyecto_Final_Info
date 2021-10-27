#include "menupausa.h"
#include "ui_menupausa.h"

menupausa::menupausa(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::menupausa)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/escena/TombStone (2).png"));
}

void menupausa::actualizacion(QString nombre,int vid, int muni, int puntaje, int nivel)
{
    vida=vid;
    municion=muni;
    puntos=puntaje;
    level=nivel;
    ui->municion->setNum(municion);
    ui->vida->setNum(vida);
    ui->puntaje->setNum(puntaje);
    ui->nivel->setNum(nivel);
    ui->nombre->setText(nombre);
}

menupausa::~menupausa()
{
    delete ui;
}

void menupausa::on_reanudar_clicked()
{
    activo=false;
    close();
}

bool menupausa::getActivo() const
{
    return activo;
}

void menupausa::setActivo(bool value)
{
    activo = value;
}

bool menupausa::getPausa() const
{
    return pausa;
}

void menupausa::setPausa(bool value)
{
    pausa = value;
}
