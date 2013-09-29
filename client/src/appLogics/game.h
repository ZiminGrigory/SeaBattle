#pragma once

#include <QObject>
#include <QApplication>
#include <QSharedPointer>

#include "types.h"
#include "gameMaster.h"

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
    QSharedPointer<View> view;
    QSharedPointer<GameMaster> gameMaster;
};
