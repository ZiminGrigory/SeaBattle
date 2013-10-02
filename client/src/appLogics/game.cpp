#include "game.h"

Game::Game(int& argc, char** argv):
    QApplication(argc, argv),
	view(QSharedPointer<InterfaceMainWindow>(new MainWindow())),
    gameMaster(QSharedPointer<GameMaster>(NULL))
{
	connect(view->getInterfaceStartMenu().data(), SIGNAL(buttonExitPushed()), SLOT(closeAllWindows()));
	connect(view->getInterfaceStartMenu().data(), SIGNAL(buttonVsPcPushed()), SLOT(aiLevelMenu()));
	connect(view->getInterfaceStartMenu().data(), SIGNAL(buttonVsPlayerPushed()), SLOT(connectionMenu()));

	connect(view->getInterfaceAiLvlList().data(), SIGNAL(buttonExitPushed()), SLOT(gameMenu()));
	connect(view->getInterfaceAiLvlList().data(), SIGNAL(buttonVsSimplePushed()), SLOT(startAISimpleGame()));
	connect(view->getInterfaceAiLvlList().data(), SIGNAL(buttonVsProPushed()), SLOT(startAIHardGame()));

	connect(view->getInterfaceConnectWidget().data(), SIGNAL(buttonExitPushed()), SLOT(gameMenu()));

    gameMenu();
}

void Game::gameMenu()
{

	view->hideWidget(BATTLE);
	view->hideWidget(AI_MENU);
	view->hideWidget(CONNECT);
	view->show();
	view->showWidget(START_MENU);
}

void Game::aiLevelMenu()
{
	view->hideWidget(START_MENU);
	view->showWidget(AI_MENU);
}

void Game::connectionMenu()
{
	view->hideWidget(START_MENU);
	view->showWidget(CONNECT);
	view->getInterfaceConnectWidget()->showLoader();
}

void Game::startAISimpleGame()
{
	view->hideWidget(AI_MENU);
	view->showWidget(BATTLE);
	gameMaster = QSharedPointer<GameMaster>(new GameMaster(AI_SIMPLE_GAME, view->getInterfaceBattleWidget(), this));
	gameMaster->startGame();
}

void Game::startAIHardGame()
{
	view->hideWidget(AI_MENU);
	view->showWidget(BATTLE);
	gameMaster = QSharedPointer<GameMaster>(new GameMaster(AI_HARD_GAME, view->getInterfaceBattleWidget(), this));
	gameMaster->startGame();
}

void Game::startNetworkGame()
{
}

