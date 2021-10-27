#include "puntuaje.h"
#include "ui_puntuaje.h"

Puntuaje::Puntuaje(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Puntuaje)
{
    ui->setupUi(this);
}

void Puntuaje::actualizacion(QString nombre1, int puntaje1, QString nombre2, int puntaje2)
{
    ui->nom1->setText(nombre1);
    ui->nom2->setText(nombre2);
    ui->pun1->setNum(puntaje1);
    ui->pun2->setNum(puntaje2);
}

Puntuaje::~Puntuaje()
{
    delete ui;
}

void Puntuaje::on_salir_clicked()
{
    close();
}
