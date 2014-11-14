#-------------------------------------------------
#
# Project created by QtCreator 2014-10-13T14:43:15
#
#-------------------------------------------------


QT       += core gui sql

CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Project_A
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    markdelegate.cpp \
    dividesubj.cpp

HEADERS  += mainwindow.h \
    markdelegate.h \
    dividesubj.h

FORMS    += mainwindow.ui \
    dividesubj.ui
