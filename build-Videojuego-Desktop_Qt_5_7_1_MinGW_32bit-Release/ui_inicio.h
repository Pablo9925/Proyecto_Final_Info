/********************************************************************************
** Form generated from reading UI file 'inicio.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
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
    QPushButton *ingresar2;
    QPushButton *partidamulti;

    void setupUi(QDialog *inicio)
    {
        if (inicio->objectName().isEmpty())
            inicio->setObjectName(QStringLiteral("inicio"));
        inicio->resize(504, 289);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush1(QColor(189, 187, 191, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        QBrush brush2(QColor(120, 120, 120, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        inicio->setPalette(palette);
        QFont font;
        font.setBold(false);
        font.setWeight(50);
        inicio->setFont(font);
        inicio->setContextMenuPolicy(Qt::DefaultContextMenu);
        inicio->setStyleSheet(QStringLiteral("Background-image: url(:/escena/menu2.png)"));
        uss = new QLineEdit(inicio);
        uss->setObjectName(QStringLiteral("uss"));
        uss->setGeometry(QRect(40, 160, 113, 20));
        uss->setStyleSheet(QStringLiteral("Background-image:url(:/sprites personaje/Dead (5).png)"));
        pass = new QLineEdit(inicio);
        pass->setObjectName(QStringLiteral("pass"));
        pass->setGeometry(QRect(340, 160, 113, 20));
        pass->setAutoFillBackground(false);
        pass->setStyleSheet(QStringLiteral("Background-image:url(:/sprites personaje/Dead (5).png)"));
        cargar = new QPushButton(inicio);
        cargar->setObjectName(QStringLiteral("cargar"));
        cargar->setGeometry(QRect(30, 200, 131, 21));
        cargar->setStyleSheet(QStringLiteral("Background-image:url(:/sprites personaje/Dead (5).png)"));
        multijugador = new QPushButton(inicio);
        multijugador->setObjectName(QStringLiteral("multijugador"));
        multijugador->setGeometry(QRect(330, 200, 131, 23));
        multijugador->setStyleSheet(QStringLiteral("Background-image:url(:/sprites personaje/Dead (5).png)"));
        crear = new QPushButton(inicio);
        crear->setObjectName(QStringLiteral("crear"));
        crear->setGeometry(QRect(170, 180, 151, 23));
        crear->setStyleSheet(QStringLiteral("Background-image:url(:/sprites personaje/Dead (5).png)"));
        inicio_2 = new QPushButton(inicio);
        inicio_2->setObjectName(QStringLiteral("inicio_2"));
        inicio_2->setGeometry(QRect(50, 230, 91, 31));
        inicio_2->setStyleSheet(QStringLiteral("Background-image:url(:/sprites personaje/Dead (5).png)"));
        cuentanueva = new QPushButton(inicio);
        cuentanueva->setObjectName(QStringLiteral("cuentanueva"));
        cuentanueva->setGeometry(QRect(350, 230, 91, 31));
        cuentanueva->setStyleSheet(QStringLiteral("Background-image:url(:/sprites personaje/Dead (5).png)"));
        ingresar = new QPushButton(inicio);
        ingresar->setObjectName(QStringLiteral("ingresar"));
        ingresar->setGeometry(QRect(210, 230, 75, 23));
        ingresar->setStyleSheet(QStringLiteral("Background-image:url(:/sprites personaje/Dead (5).png)"));
        nuevapartida = new QPushButton(inicio);
        nuevapartida->setObjectName(QStringLiteral("nuevapartida"));
        nuevapartida->setGeometry(QRect(170, 150, 151, 23));
        nuevapartida->setStyleSheet(QStringLiteral("Background-image:url(:/sprites personaje/Dead (5).png)"));
        ingresar2 = new QPushButton(inicio);
        ingresar2->setObjectName(QStringLiteral("ingresar2"));
        ingresar2->setGeometry(QRect(210, 210, 75, 23));
        ingresar2->setStyleSheet(QStringLiteral("Background-image:url(:/sprites personaje/Dead (5).png)"));
        partidamulti = new QPushButton(inicio);
        partidamulti->setObjectName(QStringLiteral("partidamulti"));
        partidamulti->setGeometry(QRect(170, 260, 151, 28));
        partidamulti->setStyleSheet(QStringLiteral("background-image: url(:/sprites personaje/Dead (1).png);"));

        retranslateUi(inicio);

        QMetaObject::connectSlotsByName(inicio);
    } // setupUi

    void retranslateUi(QDialog *inicio)
    {
        inicio->setWindowTitle(QApplication::translate("inicio", "Rise Of The Tomb Explorer", Q_NULLPTR));
        pass->setText(QString());
        cargar->setText(QApplication::translate("inicio", "Cargar", Q_NULLPTR));
        multijugador->setText(QApplication::translate("inicio", "Multijugador", Q_NULLPTR));
        crear->setText(QApplication::translate("inicio", "Crear", Q_NULLPTR));
        inicio_2->setText(QApplication::translate("inicio", "Iniciar sesi\303\263n", Q_NULLPTR));
        cuentanueva->setText(QApplication::translate("inicio", "Nueva cuenta", Q_NULLPTR));
        ingresar->setText(QApplication::translate("inicio", "Ingresar", Q_NULLPTR));
        nuevapartida->setText(QApplication::translate("inicio", "Nueva Partida", Q_NULLPTR));
        ingresar2->setText(QApplication::translate("inicio", "Ingresar", Q_NULLPTR));
        partidamulti->setText(QApplication::translate("inicio", "Iniciar multijugador", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class inicio: public Ui_inicio {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INICIO_H
