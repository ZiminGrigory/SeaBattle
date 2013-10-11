#include "game.h"

Game::Game(int& argc, char** argv):
    QApplication(argc, argv),
	view(QSharedPointer<InterfaceMainWindow>(new MainWindow())),
    gameMaster(QSharedPointer<GameMaster>(NULL)),
    mConnectionMenu(NULL)
{
    QSharedPointer<InterfaceConnectWidget> connectWidget = view->getInterfaceConnectWidget();
    mConnectionMenu = QSharedPointer<ConnectionMenu>(new ConnectionMenu(this, connectWidget));

	connect(view->getInterfaceStartMenu().data(), SIGNAL(buttonExitPushed()), SLOT(closeAllWindows()));
	connect(view->getInterfaceStartMenu().data(), SIGNAL(buttonVsPcPushed()), SLOT(aiLevelMenu()));
	connect(view->getInterfaceStartMenu().data(), SIGNAL(buttonVsPlayerPushed()), SLOT(connectionMenu()));
	connect(view->getInterfaceStartMenu().data(), SIGNAL(buttonSettingsPushed()), SLOT(settingsMenu()));

	connect(view->getInterfaceAiLvlList().data(), SIGNAL(buttonExitPushed()), SLOT(gameMenu()));
	connect(view->getInterfaceAiLvlList().data(), SIGNAL(buttonVsSimplePushed()), SLOT(startAISimpleGame()));
	connect(view->getInterfaceAiLvlList().data(), SIGNAL(buttonVsProPushed()), SLOT(startAIHardGame()));

	connect(view->getInterfaceSettingsMenu().data(), SIGNAL(buttonBackPushed()), SLOT(gameMenu()));

    gameMenu();
}

void Game::gameMenu()
{
	hideAllWidget();
	view->show();
	view->showWidget(START_MENU);
}

void Game::aiLevelMenu()
{
	hideAllWidget();
	view->showWidget(AI_MENU);
}

void Game::connectionMenu()
{
	hideAllWidget();
    view->showWidget(CONNECT);
    mConnectionMenu->startConnection();
}

void Game::startAISimpleGame()
{
	hideAllWidget();
	view->showWidget(BATTLE);
    gameMaster = QSharedPointer<GameMaster>(new GameMaster(AI_SIMPLE_GAME,
                                                           view->getInterfaceBattleWidget(),
                                                           QSharedPointer<Client>(NULL),
                                                           this));
	gameMaster->startGame();
}

void Game::startAIHardGame()
{
	hideAllWidget();
	view->showWidget(BATTLE);
    gameMaster = QSharedPointer<GameMaster>(new GameMaster(AI_HARD_GAME,
                                                           view->getInterfaceBattleWidget(),
                                                           QSharedPointer<Client>(NULL),
                                                           this));
	gameMaster->startGame();
}

void Game::startNetworkGame(const QSharedPointer<Client>& client)
{
	hideAllWidget();
    view->showWidget(BATTLE);
    gameMaster = QSharedPointer<GameMaster>(new GameMaster(NETWORK_GAME,
                                                           view->getInterfaceBattleWidget(),
                                                           client,
                                                           this));
    gameMaster->startGame();

	//client->send(Protocol::CHECK_STATE, QByteArray());
}

void Game::settingsMenu()
{
	hideAllWidget();
	view->showWidget(SETTINGS);
}

void Game::hideAllWidget()
{
	view->hideWidget(START_MENU);
	view->hideWidget(BATTLE);
	view->hideWidget(AI_MENU);
	view->hideWidget(CONNECT);
	view->hideWidget(SETTINGS);
}


