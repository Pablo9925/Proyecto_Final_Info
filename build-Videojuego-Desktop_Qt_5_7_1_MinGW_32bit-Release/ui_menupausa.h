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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_menupausa
{
public:
    QLabel *label;
    QLabel *vida;
    QLabel *label_3;
    QLabel *municion;

    void setupUi(QWidget *menupausa)
    {
        if (menupausa->objectName().isEmpty())
            menupausa->setObjectName(QStringLiteral("menupausa"));
        menupausa->resize(421, 283);
        menupausa->setStyleSheet(QStringLiteral(""));
        label = new QLabel(menupausa);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 40, 61, 61));
        label->setStyleSheet(QLatin1String("\n"
"image: url(:/escena/vida.png);"));
        vida = new QLabel(menupausa);
        vida->setObjectName(QStringLiteral("vida"));
        vida->setGeometry(QRect(120, 30, 61, 81));
        QFont font;
        font.setPointSize(20);
        vida->setFont(font);
        vida->setStyleSheet(QStringLiteral(""));
        label_3 = new QLabel(menupausa);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 120, 81, 71));
        label_3->setStyleSheet(QStringLiteral("image: url(:/escena/ammo.png);"));
        municion = new QLabel(menupausa);
        municion->setObjectName(QStringLiteral("municion"));
        municion->setGeometry(QRect(130, 110, 81, 91));
        municion->setFont(font);
        municion->setStyleSheet(QLatin1String("\n"
"background-image: url(:/sprites personaje/Dead (1).png);"));

        retranslateUi(menupausa);

        QMetaObject::connectSlotsByName(menupausa);
    } // setupUi

    void retranslateUi(QWidget *menupausa)
    {
        menupausa->setWindowTitle(QApplication::translate("menupausa", "Form", Q_NULLPTR));
        label->setText(QString());
        vida->setText(QString());
        label_3->setText(QString());
        municion->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class menupausa: public Ui_menupausa {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUPAUSA_H
