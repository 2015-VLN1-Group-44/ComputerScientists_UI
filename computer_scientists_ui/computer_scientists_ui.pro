#-------------------------------------------------
#
# Project created by QtCreator 2015-12-10T11:35:23
#
#-------------------------------------------------

QT       += core gui
QT       += core sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = computer_scientists_ui
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    repository.cpp \
    scientist_service.cpp \
    scientist.cpp \
    computers.cpp \
    computer_service.cpp \
    add_scientist.cpp

HEADERS  += mainwindow.h \
    repository.h \
    scientist_service.h \
    scientist.h \
    computers.h \
    computer_service.h \
    constants.h \
    add_scientist.h

FORMS    += mainwindow.ui \
    add_scientist.ui
