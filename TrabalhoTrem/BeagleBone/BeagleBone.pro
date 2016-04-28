QT += core
QT -= gui

CONFIG += c++11

TARGET = BeagleBone
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    mainwindow.cpp

FORMS += \
    mainwindow.ui

DISTFILES +=

HEADERS += \
    mainwindow.h
