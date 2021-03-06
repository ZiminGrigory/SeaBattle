#pragma once

#include <QObject>
#include <QApplication>
#include <QSharedPointer>

#include "types.h"
#include "connectionMenu.h"
#include "aiGameMaster.h"
#include "networkGameMaster.h"


#include "audioPlayer.h"

#ifdef QML_VIEW
	#include "qmlMainWindow.h"
#elif WIDGETS_VIEW
	#include "MainWindow.h"
#endif

class ConnectionMenu;

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
    void startNetworkGame(const QSharedPointer<Client>& client);
	/**
	 * @brief settingsMenu start widget with settings menu
	 */
	void settingsMenu();
private slots:
	void handleBW();
	void exitButtonHandler();
private:
	void hideAllWidget();
	QSharedPointer<InterfaceMainWindow> view;
    QSharedPointer<GameMaster> gameMaster;
    QSharedPointer<ConnectionMenu> mConnectionMenu;
	QSharedPointer<AudioPlayer> audioPlayer;


};
