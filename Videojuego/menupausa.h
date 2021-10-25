#ifndef MENUPAUSA_H
#define MENUPAUSA_H

#include <QWidget>
#include "personaje.h"

namespace Ui {
class menupausa;
}

class menupausa : public QWidget
{
    Q_OBJECT

public:
    explicit menupausa(QWidget *parent = nullptr);
    ~menupausa();

private:
    Ui::menupausa *ui;
    personaje *chica;
};

#endif // MENUPAUSA_H
