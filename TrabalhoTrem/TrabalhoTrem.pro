#-------------------------------------------------
#
# Project created by QtCreator 2016-04-15T06:45:49
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TrabalhoTrem
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    trem.cpp \
    thread.cpp \
    getentry.cpp \
    BeagleBone/main.cpp \
    BeagleBone/mainwindow.cpp \
    ../../../../../Dev/BlackLib/v3_0/BlackGPIO/BlackGPIO.cpp \
    ../../../../../Dev/BlackLib/v3_0/BlackCore.cpp

HEADERS  += mainwindow.h \
    trem.h \
    thread.h \
    getentry.h \
    BeagleBone/mainwindow.h \
    ../../../../../Dev/BlackLib/v3_0/BlackGPIO/BlackGPIO.h \
    ../../../../../Dev/BlackLib/v3_0/BlackCore.h \
    ../../../../../Dev/BlackLib/v3_0/BlackDef.h \
    ../../../../../Dev/BlackLib/v3_0/BlackErr.h

FORMS    += mainwindow.ui

CONFIG  += c++11
LIBS += -pthread

DISTFILES += \
    compila.sh
