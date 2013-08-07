#-------------------------------------------------
#
# Project created by QtCreator 2013-08-06T15:48:20
#
#-------------------------------------------------

QT       += core testlib

QT       -= gui

TARGET = Tests
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    ../../src/enemyCell.cpp \
    ../../src/playerCell.cpp \
    ../../src/ship.cpp \
    ../../src/playerField.cpp \
    ../../src/enemyField.cpp

HEADERS += \
    enemyFieldTest.h \
    ../../src/enemyCell.h \
    ../../src/types.h \
    ../../src/playerCell.h \
    ../../src/ship.h \
    ../../src/playerField.h \
    ../../src/enemyField.h

