#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QAbstractButton>
#include <fstream>
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();


private slots:
  //  void on_pushButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::Dialog *ui;
    QString usuarioo;
    QString contrasenaa;
};

#endif // DIALOG_H
