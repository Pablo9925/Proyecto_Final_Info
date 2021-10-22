#include "mainwindow.h"
#include <QApplication>
#include "inicio.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    inicio m ;
    m.show();
    //zMainWindow w;
   // w.show();
    return a.exec();
}
