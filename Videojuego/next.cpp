#include "next.h"
#include "ui_next.h"
#include "mainwindow.h"

next::next(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::next)
{
    ui->setupUi(this);
}

next::~next()
{
    delete ui;
}

QString next::getAuxpersonajee() const
{
    return auxpersonajee;
}

void next::setAuxpersonajee(const QString &value)
{
    auxpersonajee = value;
}

QString next::getAuxpersonajee2() const
{
    return auxpersonajee2;
}

void next::setAuxpersonajee2(const QString &value)
{
    auxpersonajee2 = value;
}

void next::on_pushButton_clicked()
{
    MainWindow *ventana;
    ventana=new MainWindow();
    ventana->setNombre(auxpersonajee);
    ventana->setNombre2(auxpersonajee2);

    ventana->cargar();
    ventana->show();

    close();
}

void next::on_salir_clicked()
{
    close();
}

bool next::getMultiplayer() const
{
    return multiplayer;
}

void next::setMultiplayer(bool value)
{
    multiplayer = value;
}
