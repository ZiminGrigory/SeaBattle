#pragma once

#include <QObject>
#include <QApplication>
#include <QSharedPointer>

#include "types.h"
#include "gameMaster.h"
#include "MainWindow.h"
#include "BattleWidget.h"
#include "StartMenu.h"
#include "AiLvlList.h"
#include "ConnectWidget.h"

class Game : public QApplication
{
    Q_OBJECT
public:
    explicit Game(int& argc, char** argv);

public slots:
    /**
      * Show main game menu.
      */
    void gameMenu();
    /**
      * Show widget with ai levels.
      */
    void aiLevelMenu();
    /**
      * Show widget with information about network connection.
      */
    void connectionMenu();
    /**
      * Start game with stupid ai.
      */
    void startAISimpleGame();
    /**
      * Start game with smart ai.
      */
    void startAIHardGame();
    /**
      * Start network game.
      */
    void startNetworkGame();
private:
	QSharedPointer<InterfaceMainWindow> view;
    QSharedPointer<GameMaster> gameMaster;
};
