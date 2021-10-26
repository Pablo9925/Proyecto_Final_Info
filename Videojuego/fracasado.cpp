#include "fracasado.h"
#include "ui_fracasado.h"
#include "mainwindow.h"

Fracasado::Fracasado(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Fracasado)
{
    ui->setupUi(this);

}

Fracasado::~Fracasado()
{
    delete ui;
}

void Fracasado::on_Siguiente_clicked()
{
    MainWindow *ventana;
    ventana=new MainWindow();
    ventana->setNombre(auxpersonaje1);
    //ventana->close();
    ventana->show();

    close();
}

QString Fracasado::getAuxpersonaje1() const
{
    return auxpersonaje1;
}

void Fracasado::setAuxpersonaje1(const QString &value)
{
    auxpersonaje1 = value;
}
