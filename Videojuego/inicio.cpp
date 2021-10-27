#include "inicio.h"
#include "ui_inicio.h"

inicio::inicio(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::inicio)
{
    ui->setupUi(this);
    ui->crear->setVisible(false);
    ui->cargar->setVisible(false);
    ui->multijugador->setVisible(false);
    ui->uss->setVisible(false);
    ui->pass->setVisible(false);
    ui->ingresar->setVisible(false);
    ui->nuevapartida->setVisible(false);
    ui->ingresar2->setVisible(false);
    ui->partidamulti->setVisible(false);
    setWindowIcon(QIcon(":/escena/TombStone (2).png"));
}

inicio::~inicio()
{
    delete ui;
}

void inicio::on_inicio_2_clicked()
{
    ui->uss->setVisible(true);
    ui->pass->setVisible(true);
    ui->inicio_2->setVisible(false);
    ui->cuentanueva->setVisible(false);
    ui->ingresar->setVisible(true);
}

void inicio::on_cuentanueva_clicked()
{
    ui->uss->setVisible(true);
    ui->pass->setVisible(true);
    ui->inicio_2->setVisible(false);
    ui->cuentanueva->setVisible(false);
    ui->crear->setVisible(true);
}

void inicio::on_crear_clicked()
{
    usuario=ui->uss->text();
    password=ui->pass->text();
    QString puntinicio="0";
    QFile cuenta(usuario);
    if ( cuenta.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::information(this,"Menú","Cuenta Creada Con Éxito.");
        QTextStream out(&cuenta);
        out << usuario<<endl;
        out << password << endl;
        out << puntinicio << endl;
        out<<"1"<<endl;
        out <<"3"<<endl;
        out<<"4"<<endl;
        cuenta.close();
        ui->uss->setVisible(false);
        ui->pass->setVisible(false);
        ui->multijugador->setVisible(true);
        ui->cargar->setVisible(true);
        ui->nuevapartida->setVisible(true);
        ui->crear->setVisible(false);
    }
    else
    {
        QMessageBox::information(this,"Menú","Error, por favor vuelva a intentarlo.");
    }

}

void inicio::on_nuevapartida_clicked()
{
    QString puntinicio="0";
    QFile cuenta(usuario);
    if ( cuenta.open(QFile::WriteOnly | QFile::Text))
    {
        QTextStream out(&cuenta);
        out << usuario<<endl;
        out << password << endl;
        out << puntinicio << endl;
        cuenta.close();
    }
    MainWindow *juego;
    juego=new MainWindow();
    juego->setNombre(usuario);
    juego->setNombre2(usuario);
    juego->show();
}

void inicio::on_ingresar_clicked()
{
    usuario=ui->uss->text();
    password=ui->pass->text();


    QFile archivo(usuario);
    if(archivo.open(QFile::ReadOnly | QFile::Text))
    {
        QTextStream read(&archivo);
        QString clave;
        read.readLine();
        clave = read.readLine();
        if( clave == ui->pass->text())
        {
            read.readLine();
            read.readLine();
            read.readLine();
            read.readLine();
            read.readLine();
            ui->uss->setVisible(false);
            ui->pass->setVisible(false);
            ui->multijugador->setVisible(true);
            ui->cargar->setVisible(true);
            ui->nuevapartida->setVisible(true);
            ui->ingresar->setVisible(false);
            archivo.close();
        }
        else
        {
            QMessageBox::information(this,"Menú","Error, revise bien los campos.");
        }
    }
}

void inicio::on_multijugador_clicked()
{
    ui->uss->setVisible(true);
    ui->pass->setVisible(true);
    ui->multijugador->setVisible(false);
    ui->nuevapartida->setVisible(false);
    ui->cargar->setVisible(false);
    ui->ingresar2->setVisible(true);

}

void inicio::on_ingresar2_clicked()
{

    usuario2=ui->uss->text();
    password2=ui->pass->text();
    QFile archivo(usuario2);
    if(archivo.open(QFile::ReadOnly | QFile::Text))
    {
        QTextStream read(&archivo);
        QString clave;
        read.readLine();
        clave = read.readLine();
        if( clave == ui->pass->text())
        {
            read.readLine();
            read.readLine();
            read.readLine();
            read.readLine();
            read.readLine();
            ui->uss->setVisible(false);
            ui->pass->setVisible(false);
            ui->multijugador->setVisible(false);
            ui->nuevapartida->setVisible(false);
            ui->ingresar->setVisible(false);
            ui->ingresar2->setVisible(false);
            ui->partidamulti->setVisible(true);
            archivo.close();
        }
        else
        {
            QMessageBox::information(this,"Menú","Error, revise bien los campos.");
        }
    }
}



void inicio::on_cargar_clicked()
{
    MainWindow *juego;
    juego=new MainWindow();
    juego->setNombre(usuario);
    juego->cargar();
    juego->show();
}

void inicio::on_partidamulti_clicked()
{
    QString puntinicio="0";
    QFile cuenta(usuario);
    if ( cuenta.open(QFile::WriteOnly | QFile::Text))
    {
        QTextStream out(&cuenta);
        out << usuario<<endl;
        out << password << endl;
        out << puntinicio << endl;
        out << "1" << endl;
        out <<"3" << endl;
        out << "6" << endl;
        cuenta.close();
    }

    QFile cuenta2(usuario2);
    if ( cuenta2.open(QFile::WriteOnly | QFile::Text))
    {
        QTextStream out(&cuenta2);
        out << usuario2<<endl;
        out << password2 << endl;
        out << puntinicio << endl;
        out << "1" << endl;
        out <<"3" << endl;
        out << "6" << endl;
        cuenta.close();
    }
    MainWindow *juego;
    juego=new MainWindow();
    juego->setNombre(usuario);
    juego->setNombre2(usuario2);
    juego->show();

}
