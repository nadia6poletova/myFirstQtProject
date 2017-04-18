#-------------------------------------------------
#
# Project created by QtCreator 2016-11-30T20:21:20
#
#-------------------------------------------------

QT       += core gui

QT       += sql

QT       +=xlsx

QTPLUGIN += qsqlmysql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Databasekurs
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    MyEmployees.cpp \
    form.cpp

HEADERS  += mainwindow.h \
    MyEmployees.h \
    form.h

FORMS    += mainwindow.ui \
    form.ui
