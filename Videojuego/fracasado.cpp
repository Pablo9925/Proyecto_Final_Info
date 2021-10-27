#include "fracasado.h"
#include "ui_fracasado.h"
#include "mainwindow.h"
#include "QDebug"

Fracasado::Fracasado(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Fracasado)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/escena/TombStone (2).png"));
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
    ventana->setNombre2(auxpersonaje2);
    if(auxpersonaje1.length()>0 && auxpersonaje2.length()>0 && auxpersonaje1!=auxpersonaje2) ventana->setMultiplayer(true);
    else ventana->setMultiplayer(false);
    //ventana->close();
    ventana->show();

    close();
}

void Fracasado::on_salir_clicked()
{
    close();
}

QString Fracasado::getAuxpersonaje2() const
{
    return auxpersonaje2;
}

void Fracasado::setAuxpersonaje2(const QString &value)
{
    auxpersonaje2 = value;
}

QString Fracasado::getAuxpersonaje1() const
{
    return auxpersonaje1;
}

void Fracasado::setAuxpersonaje1(const QString &value)
{
    auxpersonaje1 = value;
}
