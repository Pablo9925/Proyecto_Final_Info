/********************************************************************************
** Form generated from reading UI file 'fracasado.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRACASADO_H
#define UI_FRACASADO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Fracasado
{
public:
    QPushButton *Siguiente;
    QPushButton *salir;
    QLabel *label;

    void setupUi(QWidget *Fracasado)
    {
        if (Fracasado->objectName().isEmpty())
            Fracasado->setObjectName(QStringLiteral("Fracasado"));
        Fracasado->resize(369, 235);
        Fracasado->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        Siguiente = new QPushButton(Fracasado);
        Siguiente->setObjectName(QStringLiteral("Siguiente"));
        Siguiente->setGeometry(QRect(30, 150, 131, 61));
        salir = new QPushButton(Fracasado);
        salir->setObjectName(QStringLiteral("salir"));
        salir->setGeometry(QRect(200, 150, 131, 61));
        label = new QLabel(Fracasado);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 0, 311, 131));
        label->setStyleSheet(QStringLiteral("image: url(:/escena/derrota.png);"));

        retranslateUi(Fracasado);

        QMetaObject::connectSlotsByName(Fracasado);
    } // setupUi

    void retranslateUi(QWidget *Fracasado)
    {
        Fracasado->setWindowTitle(QApplication::translate("Fracasado", "Form", Q_NULLPTR));
        Siguiente->setText(QApplication::translate("Fracasado", "Siguiente", Q_NULLPTR));
        salir->setText(QApplication::translate("Fracasado", "Salir", Q_NULLPTR));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Fracasado: public Ui_Fracasado {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRACASADO_H
