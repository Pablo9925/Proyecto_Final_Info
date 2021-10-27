/********************************************************************************
** Form generated from reading UI file 'next.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEXT_H
#define UI_NEXT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_next
{
public:
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *salir;

    void setupUi(QWidget *next)
    {
        if (next->objectName().isEmpty())
            next->setObjectName(QStringLiteral("next"));
        next->resize(345, 240);
        next->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label = new QLabel(next);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 10, 261, 81));
        label->setStyleSheet(QStringLiteral("image: url(:/escena/victoria.png);"));
        pushButton = new QPushButton(next);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(30, 150, 91, 51));
        salir = new QPushButton(next);
        salir->setObjectName(QStringLiteral("salir"));
        salir->setGeometry(QRect(210, 140, 93, 51));

        retranslateUi(next);

        QMetaObject::connectSlotsByName(next);
    } // setupUi

    void retranslateUi(QWidget *next)
    {
        next->setWindowTitle(QApplication::translate("next", "Form", Q_NULLPTR));
        label->setText(QString());
        pushButton->setText(QApplication::translate("next", "Siguiente", Q_NULLPTR));
        salir->setText(QApplication::translate("next", "Cerrar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class next: public Ui_next {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEXT_H
