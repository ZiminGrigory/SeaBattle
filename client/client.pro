
QT       += core gui network multimedia widgets

DEFINES += QT5

TARGET = client
TEMPLATE = app

SOURCES += src/main.cpp \
    src/gameLogics/enemyCell.cpp \
    src/gameLogics/playerCell.cpp \
    src/gameLogics/playerField.cpp \
    src/gameLogics/humanPlayer.cpp \
    src/gameLogics/aiPlayer.cpp \
    src/gameLogics/gameMaster.cpp \
    src/view/field.cpp \
    src/view/cell.cpp \
    src/gameLogics/fleetInstaller.cpp \
    src/view/tabOfInformation.cpp \
    src/gameLogics/gameCell.cpp \
    src/gameLogics/gameField.cpp \
    src/gameLogics/ship.cpp \
    src/gameLogics/aiPlayerSimple.cpp \
    src/gameLogics/textureAnalyzer.cpp \
    src/gameLogics/player.cpp \
    src/view/BattleWidget.cpp \
    src/gameLogics/remotePlayer.cpp \
    src/gameLogics/networkHumanPlayer.cpp \
    src/gameLogics/ArrowAnalyzer.cpp \
    src/view/ChatAndStatus.cpp \
    src/view/StartMenu.cpp \
    src/view/AiLvlList.cpp \
    src/view/ConnectWidget.cpp \
        src/view/MainWindow.cpp \
    src/tcpClient/client.cpp \
    src/tcpClient/clientstate.cpp \
    src/tcpClient/searchGameState.cpp \
    src/tcpClient/noConnectionState.cpp \
    src/tcpClient/stateCollection.cpp \
    src/tcpClient/waitingForPlayerConnectionState.cpp \
    src/tcpClient/gameState.cpp \
    src/appLogics/game.cpp \
    src/tcpClient/waitingForServerConnectionState.cpp \
    src/appLogics/connectionMenu.cpp \
    src/audioPlayer/audioPlayer.cpp

HEADERS  += src/gameLogics/enemyCell.h \
    src/gameLogics/types.h \
    src/gameLogics/playerCell.h \
    src/gameLogics/ship.h \
    src/gameLogics/playerField.h \
    src/gameLogics/player.h \
    src/gameLogics/humanPlayer.h \
    src/gameLogics/aiPlayer.h \
    src/gameLogics/gameMaster.h \
    src/gameLogics/fleetFactory.h \
    src/gameLogics/cellShip.h \
    src/view/field.h \
    src/view/cell.h \
    src/gameLogics/fleetInstaller.h \
    src/view/tabOfInformation.h \
    src/gameLogics/gameCell.h \
    src/gameLogics/gameField.h \
    src/gameLogics/aiPlayerSimple.h \
    src/gameLogics/textureAnalyzer.h \
    src/view/BattleWidget.h \
    src/gameLogics/remotePlayer.h \
    src/gameLogics/networkHumanPlayer.h \
    src/gameLogics/ArrowAnalyzer.h \
    src/view/ChatAndStatus.h \
    src/view/StartMenu.h \
    src/view/AiLvlList.h \
    src/view/ConnectWidget.h \
    src/view/MainWindow.h \
    src/view/InterfaceAiLvlList.h \
    src/view/InterfaceStartMenu.h \
    src/view/InterfaceChatAndStatus.h \
    src/view/InterfaceConnectWidget.h \
    src/view/InterfaceMainWindow.h \
    src/view/InterfaceBattleWidget.h \
    src/view/InterfaceField.h \
    src/view/InterfaceInfoTab.h \
    ../protocol.h \
    src/tcpClient/client.h \
    src/tcpClient/clientstate.h \
    src/tcpClient/searchGameState.h \
    src/tcpClient/noConnectionState.h \
    src/tcpClient/stateCollection.h \
    src/tcpClient/waitingForPlayerConnectionState.h \
    src/tcpClient/gameState.h \
    src/appLogics/game.h \
    src/tcpClient/waitingForServerConnectionState.h \
    src/appLogics/connectionMenu.h \
    src/audioPlayer/audioPlayer.h

FORMS    += gui/tabOfInformation.ui \
    gui/field.ui \
    src/view/BattleWidget.ui \
    src/view/ChatAndStatus.ui \
    src/view/StartMenu.ui \
    src/view/AiLvlList.ui \
    src/view/ConnectWidget.ui \
    src/view/MainWindow.ui

RESOURCES += gui/pictures/pictures.qrc \
    gui/sounds/sounds.qrc

INCLUDEPATH += src/view src/gameLogics src/appLogics src/tcpClient src/audioPlayer ../
