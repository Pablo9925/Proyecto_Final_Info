/********************************************************************************
** Form generated from reading UI file 'fracasado.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
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
    QLabel *label;

    void setupUi(QWidget *Fracasado)
    {
        if (Fracasado->objectName().isEmpty())
            Fracasado->setObjectName(QStringLiteral("Fracasado"));
        Fracasado->resize(480, 640);
        Siguiente = new QPushButton(Fracasado);
        Siguiente->setObjectName(QStringLiteral("Siguiente"));
        Siguiente->setGeometry(QRect(200, 200, 131, 61));
        label = new QLabel(Fracasado);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 50, 81, 81));

        retranslateUi(Fracasado);

        QMetaObject::connectSlotsByName(Fracasado);
    } // setupUi

    void retranslateUi(QWidget *Fracasado)
    {
        Fracasado->setWindowTitle(QApplication::translate("Fracasado", "Form", Q_NULLPTR));
        Siguiente->setText(QApplication::translate("Fracasado", "PushButton", Q_NULLPTR));
        label->setText(QApplication::translate("Fracasado", "perdistes", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Fracasado: public Ui_Fracasado {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRACASADO_H
