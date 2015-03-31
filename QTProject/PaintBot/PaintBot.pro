#-------------------------------------------------
#
# Project created by QtCreator 2015-02-25T19:02:10
#
#-------------------------------------------------

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PaintBot
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    robot.cpp \
    coloritem.cpp \
    myserver.cpp \
    client.cpp

HEADERS  += mainwindow.h \
    robot.h \
    coloritem.h \
    myserver.h \
    client.h

FORMS    += mainwindow.ui
