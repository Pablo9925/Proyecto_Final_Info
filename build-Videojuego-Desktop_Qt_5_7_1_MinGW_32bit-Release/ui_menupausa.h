/********************************************************************************
** Form generated from reading UI file 'menupausa.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENUPAUSA_H
#define UI_MENUPAUSA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_menupausa
{
public:
    QLabel *label;
    QLabel *vida;
    QLabel *label_3;
    QLabel *municion;
    QLabel *label_2;
    QLabel *puntaje;
    QPushButton *reanudar;
    QLabel *label_4;
    QLabel *nivel;
    QLabel *label_5;
    QLabel *nombre;

    void setupUi(QWidget *menupausa)
    {
        if (menupausa->objectName().isEmpty())
            menupausa->setObjectName(QStringLiteral("menupausa"));
        menupausa->resize(371, 425);
        menupausa->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"border-color: rgb(0, 0, 0);"));
        label = new QLabel(menupausa);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 110, 61, 61));
        label->setStyleSheet(QLatin1String("\n"
"image: url(:/escena/vida.png);"));
        vida = new QLabel(menupausa);
        vida->setObjectName(QStringLiteral("vida"));
        vida->setGeometry(QRect(100, 120, 161, 61));
        QFont font;
        font.setPointSize(16);
        vida->setFont(font);
        vida->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_3 = new QLabel(menupausa);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 190, 61, 61));
        label_3->setStyleSheet(QStringLiteral("image: url(:/escena/ammo.png);"));
        municion = new QLabel(menupausa);
        municion->setObjectName(QStringLiteral("municion"));
        municion->setGeometry(QRect(100, 190, 161, 61));
        municion->setFont(font);
        municion->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_2 = new QLabel(menupausa);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 270, 61, 61));
        label_2->setStyleSheet(QLatin1String("\n"
"image: url(:/escena/coin.png);"));
        puntaje = new QLabel(menupausa);
        puntaje->setObjectName(QStringLiteral("puntaje"));
        puntaje->setGeometry(QRect(100, 270, 161, 61));
        puntaje->setFont(font);
        reanudar = new QPushButton(menupausa);
        reanudar->setObjectName(QStringLiteral("reanudar"));
        reanudar->setGeometry(QRect(270, 390, 93, 28));
        reanudar->setStyleSheet(QStringLiteral(""));
        label_4 = new QLabel(menupausa);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 350, 61, 61));
        QFont font1;
        font1.setPointSize(20);
        label_4->setFont(font1);
        label_4->setLayoutDirection(Qt::RightToLeft);
        label_4->setStyleSheet(QStringLiteral("background-image: url(:/sprites personaje/Dead (1).png);"));
        nivel = new QLabel(menupausa);
        nivel->setObjectName(QStringLiteral("nivel"));
        nivel->setGeometry(QRect(100, 350, 161, 61));
        nivel->setFont(font);
        label_5 = new QLabel(menupausa);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(70, 0, 221, 61));
        label_5->setStyleSheet(QStringLiteral("image: url(:/escena/pausa.png);"));
        nombre = new QLabel(menupausa);
        nombre->setObjectName(QStringLiteral("nombre"));
        nombre->setGeometry(QRect(10, 70, 341, 41));
        nombre->setFont(font);

        retranslateUi(menupausa);

        QMetaObject::connectSlotsByName(menupausa);
    } // setupUi

    void retranslateUi(QWidget *menupausa)
    {
        menupausa->setWindowTitle(QApplication::translate("menupausa", "Pausa", Q_NULLPTR));
        label->setText(QString());
        vida->setText(QString());
        label_3->setText(QString());
        municion->setText(QString());
        label_2->setText(QString());
        puntaje->setText(QString());
        reanudar->setText(QApplication::translate("menupausa", "Cerrar", Q_NULLPTR));
        label_4->setText(QApplication::translate("menupausa", "LVL:", Q_NULLPTR));
        nivel->setText(QString());
        label_5->setText(QString());
        nombre->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class menupausa: public Ui_menupausa {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUPAUSA_H
