#-------------------------------------------------
#
# Project created by QtCreator 2013-08-05T21:31:46
#
#-------------------------------------------------

QT       += core gui

TARGET = SeaBattle
TEMPLATE = app


SOURCES += src/main.cpp\
        src/mainwindow.cpp \
    src/enemyCell.cpp \
    src/playerCell.cpp \
    src/ship.cpp \
    src/playerField.cpp \
    src/enemyField.cpp

HEADERS  += src/mainwindow.h \
    src/enemyCell.h \
    src/types.h \
    src/playerCell.h \
    src/ship.h \
    src/playerField.h \
    src/enemyField.h

FORMS    += gui/mainwindow.ui
