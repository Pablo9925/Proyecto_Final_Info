#ifndef NEXT_H
#define NEXT_H

#include <QWidget>

namespace Ui {
class next;
}

class next : public QWidget
{
    Q_OBJECT

public:
    explicit next(QWidget *parent = nullptr);
    ~next();

    QString getAuxpersonajee() const;
    void setAuxpersonajee(const QString &value);

    QString getAuxpersonajee2() const;
    void setAuxpersonajee2(const QString &value);
    bool getMultiplayer() const;
    void setMultiplayer(bool value);

private slots:
    void on_pushButton_clicked();
    void on_salir_clicked();

private:
    Ui::next *ui;
    QString auxpersonajee,auxpersonajee2;
    bool multiplayer=false;
};

#endif // NEXT_H
