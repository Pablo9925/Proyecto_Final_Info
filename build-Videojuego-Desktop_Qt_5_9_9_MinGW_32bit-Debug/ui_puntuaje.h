/********************************************************************************
** Form generated from reading UI file 'puntuaje.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PUNTUAJE_H
#define UI_PUNTUAJE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Puntuaje
{
public:
    QLabel *label;
    QLabel *nom1;
    QLabel *nom2;
    QLabel *pun1;
    QLabel *pun2;
    QPushButton *salir;

    void setupUi(QWidget *Puntuaje)
    {
        if (Puntuaje->objectName().isEmpty())
            Puntuaje->setObjectName(QStringLiteral("Puntuaje"));
        Puntuaje->resize(401, 319);
        Puntuaje->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label = new QLabel(Puntuaje);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 20, 311, 71));
        label->setStyleSheet(QStringLiteral("image: url(:/escena/puntaje.png);"));
        nom1 = new QLabel(Puntuaje);
        nom1->setObjectName(QStringLiteral("nom1"));
        nom1->setGeometry(QRect(20, 130, 141, 41));
        QFont font;
        font.setPointSize(12);
        nom1->setFont(font);
        nom1->setLayoutDirection(Qt::RightToLeft);
        nom2 = new QLabel(Puntuaje);
        nom2->setObjectName(QStringLiteral("nom2"));
        nom2->setGeometry(QRect(230, 130, 151, 41));
        nom2->setFont(font);
        pun1 = new QLabel(Puntuaje);
        pun1->setObjectName(QStringLiteral("pun1"));
        pun1->setGeometry(QRect(20, 200, 151, 41));
        pun1->setFont(font);
        pun1->setLayoutDirection(Qt::RightToLeft);
        pun2 = new QLabel(Puntuaje);
        pun2->setObjectName(QStringLiteral("pun2"));
        pun2->setGeometry(QRect(230, 200, 151, 51));
        pun2->setFont(font);
        salir = new QPushButton(Puntuaje);
        salir->setObjectName(QStringLiteral("salir"));
        salir->setGeometry(QRect(150, 270, 93, 28));

        retranslateUi(Puntuaje);

        QMetaObject::connectSlotsByName(Puntuaje);
    } // setupUi

    void retranslateUi(QWidget *Puntuaje)
    {
        Puntuaje->setWindowTitle(QApplication::translate("Puntuaje", "Form", Q_NULLPTR));
        label->setText(QString());
        nom1->setText(QString());
        nom2->setText(QString());
        pun1->setText(QString());
        pun2->setText(QString());
        salir->setText(QApplication::translate("Puntuaje", "Cerrar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Puntuaje: public Ui_Puntuaje {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PUNTUAJE_H
