#-------------------------------------------------
#
# Project created by QtCreator 2015-02-26T17:23:05
#
#-------------------------------------------------

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = homebase_2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    rest_network.cpp

HEADERS  += mainwindow.h \
    rest_network.h

FORMS    += mainwindow.ui
