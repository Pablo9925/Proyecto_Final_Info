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

    void setupUi(QWidget *next)
    {
        if (next->objectName().isEmpty())
            next->setObjectName(QStringLiteral("next"));
        next->resize(480, 240);
        label = new QLabel(next);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 80, 47, 14));
        pushButton = new QPushButton(next);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(280, 150, 91, 51));

        retranslateUi(next);

        QMetaObject::connectSlotsByName(next);
    } // setupUi

    void retranslateUi(QWidget *next)
    {
        next->setWindowTitle(QApplication::translate("next", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("next", "TextLabel", Q_NULLPTR));
        pushButton->setText(QApplication::translate("next", "PushButton", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class next: public Ui_next {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEXT_H
