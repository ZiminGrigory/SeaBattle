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


<<<<<<< HEAD
SOURCES += client/src/main.cpp\
    client/src/view/mainwindow.cpp \
    client/src/gameLogics/enemyCell.cpp \
    client/src/gameLogics/playerCell.cpp \
    client/src/gameLogics/playerField.cpp \
    client/src/gameLogics/enemyField.cpp \
    client/src/gameLogics/humanPlayer.cpp \
    client/src/gameLogics/aiPlayer.cpp \
    client/src/gameLogics/gameMaster.cpp \
    client/src/view/field.cpp \
    client/src/view/cell.cpp \
    client/src/gameLogics/fleetInstaller.cpp \
    client/src/view/tabOfInformation.cpp \
    client/src/view/view.cpp \
    client/src/gameLogics/gameCell.cpp \
    client/src/gameLogics/gameField.cpp \
    client/src/view/fieldView.cpp \
    client/src/view/infoTabView.cpp \
    client/src/gameLogics/aiPlayerSimple.cpp

HEADERS  += client/src/view/mainwindow.h \
    client/src/gameLogics/enemyCell.h \
    client/src/gameLogics/types.h \
    client/src/gameLogics/playerCell.h \
    client/src/gameLogics/ship.h \
    client/src/gameLogics/playerField.h \
    client/src/gameLogics/enemyField.h \
    client/src/gameLogics/player.h \
    client/src/gameLogics/humanPlayer.h \
    client/src/gameLogics/aiPlayer.h \
    client/src/gameLogics/gameMaster.h \
    client/src/gameLogics/fleetFactory.h \
    client/src/gameLogics/cellShip.h \
    client/src/view/field.h \
    client/src/view/cell.h \
    client/src/gameLogics/fleetInstaller.h \
    client/src/view/tabOfInformation.h \
    client/src/view/view.h \
    client/src/gameLogics/gameCell.h \
    client/src/gameLogics/gameField.h \
    client/src/view/fieldView.h \
    client/src/view/infoTabView.h \
    client/src/gameLogics/aiPlayerSimple.h

FORMS    += client/gui/tabOfInformation.ui \
    client/gui/mainwindow.ui \
    client/gui/field.ui

RESOURCES += client/gui/pictures/pictures.qrc

INCLUDEPATH += client/src/view client/src/gameLogics client/src
=======
SOURCES += src/main.cpp\
        src/mainwindow.cpp \
    src/enemyCell.cpp \
    src/playerCell.cpp \
    src/playerField.cpp \
    src/enemyField.cpp \
    src/humanPlayer.cpp \
    src/aiPlayer.cpp \
    src/gameMaster.cpp \
    src/field.cpp \
	src/cell.cpp \
	src/fleetInstaller.cpp \
    src/tabOfInformation.cpp \
    src/view.cpp \
    src/aiPlayerSimple.cpp

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
    src/field.h \
	src/cell.h \
	src/fleetInstaller.h \
    src/tabOfInformation.h \
    src/view.h \
    src/aiPlayerSimple.h

FORMS    += gui/mainwindow.ui \
    src/field.ui \
	src/tabOfInformation.ui

RESOURCES += \
	src/pictures.qrc
>>>>>>> 51113694a8344743112a0373549dd2ce0ff60285
