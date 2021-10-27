#-------------------------------------------------
#
# Project created by QtCreator 2021-10-10T14:39:53
#
#-------------------------------------------------

QT       += core gui widgets
QT += multimedia

TARGET = Videojuego
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
    bala.cpp \
    inicio.cpp \
        main.cpp \
        mainwindow.cpp \
    menupausa.cpp \
    personaje.cpp \
    logicamap.cpp \
    map.cpp \
    caja.cpp \
    coin.cpp \
    maza.cpp \
    zombie.cpp \
    fracasado.cpp

HEADERS += \
    bala.h \
    inicio.h \
        mainwindow.h \
    menupausa.h \
    personaje.h \
    logicamap.h \
    map.h \
    caja.h \
    coin.h \
    maza.h \
    zombie.h \
    fracasado.h

FORMS += \
    inicio.ui \
        mainwindow.ui \
    menupausa.ui \
    fracasado.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    sprites.qrc \
    escena.qrc \
    sonidos.qrc \
    zombie.qrc
