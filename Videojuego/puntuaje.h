#ifndef PUNTUAJE_H
#define PUNTUAJE_H

#include <QWidget>

namespace Ui {
class Puntuaje;
}

class Puntuaje : public QWidget
{
    Q_OBJECT

public:
    explicit Puntuaje(QWidget *parent = nullptr);
    void actualizacion(QString nombre1,int puntaje1,QString nombre2,int puntaje2);
    ~Puntuaje();
private slots:
    void on_salir_clicked();
private:
    Ui::Puntuaje *ui;
};

#endif // PUNTUAJE_H
