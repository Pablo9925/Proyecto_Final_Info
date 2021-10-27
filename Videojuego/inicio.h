#ifndef INICIO_H
#define INICIO_H

#include <QDialog>
#include <string>
#include <fstream>
#include <QFile>
#include<QTextStream>
#include <QMessageBox>
#include <mainwindow.h>

namespace Ui {
class inicio;
}

class inicio : public QDialog
{
    Q_OBJECT

public:
    explicit inicio(QWidget *parent = nullptr);
    ~inicio();

private slots:
    void on_inicio_2_clicked();

    void on_cuentanueva_clicked();

    void on_crear_clicked();

    void on_nuevapartida_clicked();

    void on_ingresar_clicked();

    void on_multijugador_clicked();

    void on_ingresar2_clicked();

    void on_cargar_clicked();

    void on_partidamulti_clicked();

private:
    Ui::inicio *ui;
    QString usuario;
    QString password;
    QString usuario2;
    QString password2;
};

#endif // INICIO_H
