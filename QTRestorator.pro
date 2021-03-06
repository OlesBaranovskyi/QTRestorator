#-------------------------------------------------
#
# Project created by QtCreator 2017-06-19T12:34:30
#
#-------------------------------------------------

QT       += core gui
QT+=multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QTRestorator
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        widget.cpp \
    product.cpp \
    mydialogadd.cpp \
    q_restorator_main_window.cpp \
    QDish.cpp \
    qkitchen.cpp \
    qdish.cpp \
    storage.cpp \
    qtrestorator-tests.cpp \
    menu.cpp \
    order_place.cpp \
    order.cpp

HEADERS  += widget.h \
    product.h \
    mydialogadd.h \
    q_restorator_main_window.h \
    QDish.h \
    qkitchen.h \
    qdish.h \
    storage.h \
    menu.h \
    order_place.h \
    order.h

FORMS    += widget.ui
