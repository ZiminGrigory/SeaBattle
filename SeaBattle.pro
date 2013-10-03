#-------------------------------------------------
#
# Project created by QtCreator 2013-08-05T21:31:46
#
#-------------------------------------------------
CONFIG += mobility
MOBILITY += multimedia

QT       += core gui network
QT       += widgets
#QT	 += phonon

DEFINES += QT4

TARGET = SeaBattle
TEMPLATE = app

SOURCES += client/src/main.cpp\
    client/src/gameLogics/enemyCell.cpp \
    client/src/gameLogics/playerCell.cpp \
    client/src/gameLogics/playerField.cpp \
    client/src/gameLogics/humanPlayer.cpp \
    client/src/gameLogics/aiPlayer.cpp \
    client/src/gameLogics/gameMaster.cpp \
    client/src/view/field.cpp \
    client/src/view/cell.cpp \
    client/src/gameLogics/fleetInstaller.cpp \
    client/src/view/tabOfInformation.cpp \
    client/src/gameLogics/gameCell.cpp \
    client/src/gameLogics/gameField.cpp \
    client/src/gameLogics/ship.cpp \
    client/src/gameLogics/aiPlayerSimple.cpp \
    client/src/gameLogics/textureAnalyzer.cpp \
    client/src/gameLogics/player.cpp \
    client/src/view/BattleWidget.cpp \
    client/src/gameLogics/remotePlayer.cpp \
    client/src/gameLogics/networkHumanPlayer.cpp \
    client/src/gameLogics/ArrowAnalyzer.cpp \
    client/src/view/ChatAndStatus.cpp \
    client/src/view/StartMenu.cpp \
    client/src/view/AiLvlList.cpp \
    client/src/view/ConnectWidget.cpp \
	client/src/view/MainWindow.cpp \
    client/src/tcpClient/client.cpp \
    client/src/tcpClient/clientstate.cpp \
    client/src/tcpClient/searchGameState.cpp \
    client/src/tcpClient/noConnectionState.cpp \
    client/src/tcpClient/stateCollection.cpp \
    client/src/tcpClient/waitingForPlayerConnectionState.cpp \
    client/src/tcpClient/gameState.cpp \
    client/src/appLogics/game.cpp \
    client/src/tcpClient/waitingForServerConnectionState.cpp \
    client/src/appLogics/connectionMenu.cpp
#    client/src/audioPlayer/audioPlayer.cpp \

HEADERS  += client/src/gameLogics/enemyCell.h \
    client/src/gameLogics/types.h \
    client/src/gameLogics/playerCell.h \
    client/src/gameLogics/ship.h \
    client/src/gameLogics/playerField.h \
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
    client/src/gameLogics/gameCell.h \
    client/src/gameLogics/gameField.h \
    client/src/gameLogics/aiPlayerSimple.h \
    client/src/gameLogics/textureAnalyzer.h \
    client/src/view/BattleWidget.h \
    client/src/gameLogics/remotePlayer.h \
    client/src/gameLogics/networkHumanPlayer.h \
    client/src/gameLogics/ArrowAnalyzer.h \
    client/src/view/ChatAndStatus.h \
    client/src/view/StartMenu.h \
    client/src/view/AiLvlList.h \
    client/src/view/ConnectWidget.h \
    client/src/view/MainWindow.h \
    client/src/view/InterfaceAiLvlList.h \
    client/src/view/InterfaceStartMenu.h \
    client/src/view/InterfaceChatAndStatus.h \
    client/src/view/InterfaceConnectWidget.h \
    client/src/view/InterfaceMainWindow.h \
    client/src/view/InterfaceBattleWidget.h \
    client/src/view/InterfaceField.h \
    client/src/view/InterfaceInfoTab.h \
    client/src/tcpClient/protocol.h \
    client/src/tcpClient/client.h \
    client/src/tcpClient/clientstate.h \
    client/src/tcpClient/searchGameState.h \
    client/src/tcpClient/noConnectionState.h \
    client/src/tcpClient/stateCollection.h \
    client/src/tcpClient/waitingForPlayerConnectionState.h \
    client/src/tcpClient/gameState.h \
    client/src/appLogics/game.h \
    client/src/tcpClient/waitingForServerConnectionState.h \
    client/src/appLogics/connectionMenu.h
#    client/src/audioPlayer/audioPlayer.h \

FORMS    += client/gui/tabOfInformation.ui \
    client/gui/field.ui \
    client/src/view/BattleWidget.ui \
    client/src/view/ChatAndStatus.ui \
    client/src/view/StartMenu.ui \
    client/src/view/AiLvlList.ui \
    client/src/view/ConnectWidget.ui \
    client/src/view/MainWindow.ui

RESOURCES += client/gui/pictures/pictures.qrc \
    client/gui/sounds/sounds.qrc

INCLUDEPATH += client/src/view\
		 client/src/gameLogics \
		 client/src client/src/appLogics client/src/tcpClient\
		 var/lib usr/lib usr/share/doc

LIBS += pulse

DEFINES += QT_SHAREDPOINTER_TRACK_POINTERS
