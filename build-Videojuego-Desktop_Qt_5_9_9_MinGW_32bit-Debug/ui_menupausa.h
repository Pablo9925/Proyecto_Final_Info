/********************************************************************************
** Form generated from reading UI file 'menupausa.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
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
        menupausa->resize(480, 198);
        label = new QLabel(menupausa);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(100, 40, 47, 14));
        vida = new QLabel(menupausa);
        vida->setObjectName(QStringLiteral("vida"));
        vida->setGeometry(QRect(240, 40, 47, 14));
        label_3 = new QLabel(menupausa);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(90, 100, 47, 14));
        municion = new QLabel(menupausa);
        municion->setObjectName(QStringLiteral("municion"));
        municion->setGeometry(QRect(240, 100, 47, 14));

        retranslateUi(menupausa);

        QMetaObject::connectSlotsByName(menupausa);
    } // setupUi

    void retranslateUi(QWidget *menupausa)
    {
        menupausa->setWindowTitle(QApplication::translate("menupausa", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("menupausa", "vidas", Q_NULLPTR));
        vida->setText(QString());
        label_3->setText(QApplication::translate("menupausa", "minicion", Q_NULLPTR));
        municion->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class menupausa: public Ui_menupausa {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUPAUSA_H
