#ifndef MENUPAUSA_H
#define MENUPAUSA_H

#include <QWidget>

namespace Ui {
class menupausa;
}

class menupausa : public QWidget
{
    Q_OBJECT

public:
    explicit menupausa(QWidget *parent = nullptr);
    void actualizacion(int vid,int muni,int puntaje,int nivel);
    ~menupausa();
    bool getPausa() const;
    void setPausa(bool value);
    bool getActivo() const;
    void setActivo(bool value);

private slots:
    void on_reanudar_clicked();
private:
    Ui::menupausa *ui;
    int vida,municion,puntos,level;
    bool pausa=false,activo=false;
};

#endif // MENUPAUSA_H
