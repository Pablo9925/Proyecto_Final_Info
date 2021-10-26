#ifndef FRACASADO_H
#define FRACASADO_H

#include <QWidget>

namespace Ui {
class Fracasado;
}

class Fracasado : public QWidget
{
    Q_OBJECT

public:
    explicit Fracasado(QWidget *parent = nullptr);
    ~Fracasado();

    QString getAuxpersonaje1() const;
    void setAuxpersonaje1(const QString &value);

private slots:
    void on_Siguiente_clicked();

private:
    Ui::Fracasado *ui;
    QString auxpersonaje1,auxpersonaje2;
};

#endif // FRACASADO_H
