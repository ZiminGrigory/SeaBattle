#include "game.h"

Game::Game(int& argc, char** argv):
    QApplication(argc, argv),
	view(QSharedPointer<InterfaceMainWindow>(new MainWindow())),
    gameMaster(QSharedPointer<GameMaster>(NULL)),
    mConnectionMenu(NULL)
{
    QSharedPointer<InterfaceConnectWidget> connectWidget = view->getInterfaceConnectWidget();
    mConnectionMenu = QSharedPointer<ConnectionMenu>(new ConnectionMenu(this, connectWidget));
	audioPlayer = QSharedPointer<AudioPlayer> (new AudioPlayer);

	connect(view->getInterfaceSettingsMenu().data(), SIGNAL(volumeChanched(int))
			, audioPlayer.data(), SLOT(setVolume(int)));
	connect(view->getInterfaceSettingsMenu().data(), SIGNAL(mute(bool))
			, audioPlayer.data(), SLOT(mute(bool)));

	connect(view->getInterfaceStartMenu().data(), SIGNAL(buttonExitPushed()), SLOT(closeAllWindows()));
	connect(view->getInterfaceStartMenu().data(), SIGNAL(buttonVsPcPushed()), SLOT(aiLevelMenu()));
	connect(view->getInterfaceStartMenu().data(), SIGNAL(buttonVsPlayerPushed()), SLOT(connectionMenu()));
	connect(view->getInterfaceStartMenu().data(), SIGNAL(buttonSettingsPushed()), SLOT(settingsMenu()));

	connect(view->getInterfaceAiLvlList().data(), SIGNAL(buttonExitPushed()), SLOT(gameMenu()));
	connect(view->getInterfaceAiLvlList().data(), SIGNAL(buttonVsSimplePushed()), SLOT(startAISimpleGame()));
	connect(view->getInterfaceAiLvlList().data(), SIGNAL(buttonVsProPushed()), SLOT(startAIHardGame()));

	connect(view->getInterfaceSettingsMenu().data(), SIGNAL(buttonBackPushed()), SLOT(gameMenu()));
	connect(view->getInterfaceBattleWidget().data(), SIGNAL(buttonBackPressed()), SLOT(handleBW()));
    gameMenu();
}

void Game::gameMenu()
{
	hideAllWidget();
	view->showWidget(START_MENU);
	view->getInterfaceStartMenu()->resize(WINDOW_SIZE);
	view->resize(WINDOW_SIZE);
	view->update();
	view->show();
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
	gameMaster.reset();
    gameMaster = QSharedPointer<GameMaster>(new GameMaster(AI_SIMPLE_GAME,
                                                           view->getInterfaceBattleWidget(),
                                                           QSharedPointer<Client>(NULL),
														   audioPlayer,
                                                           this));
	gameMaster->startGame();
}

void Game::startAIHardGame()
{
	hideAllWidget();
	view->showWidget(BATTLE);
	gameMaster.reset();
    gameMaster = QSharedPointer<GameMaster>(new GameMaster(AI_HARD_GAME,
                                                           view->getInterfaceBattleWidget(),
                                                           QSharedPointer<Client>(NULL),
														   audioPlayer,
                                                           this));
	gameMaster->startGame();
}

void Game::startNetworkGame(const QSharedPointer<Client>& client)
{
	hideAllWidget();
    view->showWidget(BATTLE);
	gameMaster.reset();
    gameMaster = QSharedPointer<GameMaster>(new GameMaster(NETWORK_GAME,
                                                           view->getInterfaceBattleWidget(),
                                                           client,
														   audioPlayer,
                                                           this));
    gameMaster->startGame();

	//client->send(Protocol::CHECK_STATE, QByteArray());
}

void Game::settingsMenu()
{
	hideAllWidget();
	view->showWidget(SETTINGS);
}

void Game::handleBW()
{
	view->getInterfaceBattleWidget()->clearItself();
	gameMenu();
}

void Game::hideAllWidget()
{
	view->hideWidget(START_MENU);
	view->hideWidget(BATTLE);
	view->hideWidget(AI_MENU);
	view->hideWidget(CONNECT);
	view->hideWidget(SETTINGS);
}


