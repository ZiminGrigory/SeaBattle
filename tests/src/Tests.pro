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
    ../../src/playerField.cpp \
    ../../src/enemyField.cpp \
    ../../src/humanPlayer.cpp \
    ../../src/aiPlayer.cpp \
    ../../src/gameMaster.cpp \

HEADERS += \
    enemyFieldTest.h \
    humanPlayerTest.h \
    ../../src/enemyCell.h \
    ../../src/types.h \
    ../../src/playerCell.h \
    ../../src/ship.h \
    ../../src/playerField.h \
    ../../src/enemyField.h \
    ../../src/player.h \
    ../../src/humanPlayer.h \
    ../../src/aiPlayer.h \
    ../../src/gameMaster.h \
    aiPlayerTest.h \
    gameMasterTest.h \
    playerTest.h


