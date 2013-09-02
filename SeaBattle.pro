#-------------------------------------------------
#
# Project created by QtCreator 2013-08-05T21:31:46
#
#-------------------------------------------------

QT       += core gui
QT       += widgets

DEFINES += QT4

TARGET = SeaBattle
TEMPLATE = app


SOURCES += src/main.cpp\
        src/mainwindow.cpp \
    src/enemyCell.cpp \
    src/playerCell.cpp \
    src/playerField.cpp \
    src/enemyField.cpp \
    src/humanPlayer.cpp \
    src/aiPlayer.cpp \
    src/gameMaster.cpp \
    src/fleetInstaller.cpp \
    src/field.cpp \
    src/cell.cpp

HEADERS  += src/mainwindow.h \
    src/enemyCell.h \
    src/types.h \
    src/playerCell.h \
    src/ship.h \
    src/playerField.h \
    src/enemyField.h \
    src/player.h \
    src/humanPlayer.h \
    src/aiPlayer.h \
    src/gameMaster.h \
    src/fleetFactory.h \
    src/cellShip.h \
    src/fleetInstaller.h \
    src/field.h \
    src/cell.h

FORMS    += gui/mainwindow.ui \
    src/field.ui
