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

    void setupUi(QWidget *menupausa)
    {
        if (menupausa->objectName().isEmpty())
            menupausa->setObjectName(QStringLiteral("menupausa"));
        menupausa->resize(371, 320);
        menupausa->setStyleSheet(QStringLiteral("background-color: rgb(227, 241, 255);"));
        label = new QLabel(menupausa);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 0, 61, 61));
        label->setStyleSheet(QLatin1String("\n"
"image: url(:/escena/vida.png);"));
        vida = new QLabel(menupausa);
        vida->setObjectName(QStringLiteral("vida"));
        vida->setGeometry(QRect(100, 0, 161, 61));
        QFont font;
        font.setPointSize(20);
        vida->setFont(font);
        vida->setStyleSheet(QStringLiteral("background-color: rgb(227, 241, 255);"));
        label_3 = new QLabel(menupausa);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 90, 61, 61));
        label_3->setStyleSheet(QStringLiteral("image: url(:/escena/ammo.png);"));
        municion = new QLabel(menupausa);
        municion->setObjectName(QStringLiteral("municion"));
        municion->setGeometry(QRect(100, 90, 161, 61));
        municion->setFont(font);
        municion->setStyleSheet(QStringLiteral("background-color: rgb(227, 241, 255);"));
        label_2 = new QLabel(menupausa);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 170, 61, 61));
        label_2->setStyleSheet(QLatin1String("\n"
"image: url(:/escena/coin.png);"));
        puntaje = new QLabel(menupausa);
        puntaje->setObjectName(QStringLiteral("puntaje"));
        puntaje->setGeometry(QRect(100, 170, 161, 61));
        puntaje->setFont(font);
        reanudar = new QPushButton(menupausa);
        reanudar->setObjectName(QStringLiteral("reanudar"));
        reanudar->setGeometry(QRect(270, 140, 93, 28));
        label_4 = new QLabel(menupausa);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 250, 61, 61));
        label_4->setFont(font);
        label_4->setLayoutDirection(Qt::RightToLeft);
        nivel = new QLabel(menupausa);
        nivel->setObjectName(QStringLiteral("nivel"));
        nivel->setGeometry(QRect(100, 250, 161, 51));
        nivel->setFont(font);

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
    } // retranslateUi

};

namespace Ui {
    class menupausa: public Ui_menupausa {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUPAUSA_H
