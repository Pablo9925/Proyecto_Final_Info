/********************************************************************************
** Form generated from reading UI file 'inicio.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INICIO_H
#define UI_INICIO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_inicio
{
public:
    QLineEdit *uss;
    QLineEdit *pass;
    QPushButton *cargar;
    QPushButton *multijugador;
    QPushButton *crear;
    QPushButton *inicio_2;
    QPushButton *cuentanueva;
    QPushButton *ingresar;
    QPushButton *nuevapartida;
    QGraphicsView *graphicsView;

    void setupUi(QDialog *inicio)
    {
        if (inicio->objectName().isEmpty())
            inicio->setObjectName(QStringLiteral("inicio"));
        inicio->resize(480, 356);
        uss = new QLineEdit(inicio);
        uss->setObjectName(QStringLiteral("uss"));
        uss->setGeometry(QRect(60, 180, 113, 20));
        pass = new QLineEdit(inicio);
        pass->setObjectName(QStringLiteral("pass"));
        pass->setGeometry(QRect(290, 180, 113, 20));
        cargar = new QPushButton(inicio);
        cargar->setObjectName(QStringLiteral("cargar"));
        cargar->setGeometry(QRect(160, 30, 131, 21));
        multijugador = new QPushButton(inicio);
        multijugador->setObjectName(QStringLiteral("multijugador"));
        multijugador->setGeometry(QRect(160, 110, 131, 23));
        crear = new QPushButton(inicio);
        crear->setObjectName(QStringLiteral("crear"));
        crear->setGeometry(QRect(150, 210, 141, 23));
        inicio_2 = new QPushButton(inicio);
        inicio_2->setObjectName(QStringLiteral("inicio_2"));
        inicio_2->setGeometry(QRect(74, 280, 91, 23));
        cuentanueva = new QPushButton(inicio);
        cuentanueva->setObjectName(QStringLiteral("cuentanueva"));
        cuentanueva->setGeometry(QRect(250, 280, 91, 23));
        ingresar = new QPushButton(inicio);
        ingresar->setObjectName(QStringLiteral("ingresar"));
        ingresar->setGeometry(QRect(180, 250, 75, 23));
        nuevapartida = new QPushButton(inicio);
        nuevapartida->setObjectName(QStringLiteral("nuevapartida"));
        nuevapartida->setGeometry(QRect(160, 70, 131, 23));
        graphicsView = new QGraphicsView(inicio);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 101, 121));

        retranslateUi(inicio);

        QMetaObject::connectSlotsByName(inicio);
    } // setupUi

    void retranslateUi(QDialog *inicio)
    {
        inicio->setWindowTitle(QApplication::translate("inicio", "Dialog", Q_NULLPTR));
        cargar->setText(QApplication::translate("inicio", "cargar", Q_NULLPTR));
        multijugador->setText(QApplication::translate("inicio", "multijugador", Q_NULLPTR));
        crear->setText(QApplication::translate("inicio", "crear", Q_NULLPTR));
        inicio_2->setText(QApplication::translate("inicio", "inicio de sesion", Q_NULLPTR));
        cuentanueva->setText(QApplication::translate("inicio", "nueva cuenta", Q_NULLPTR));
        ingresar->setText(QApplication::translate("inicio", "ingresar", Q_NULLPTR));
        nuevapartida->setText(QApplication::translate("inicio", "nueva partida", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class inicio: public Ui_inicio {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INICIO_H
