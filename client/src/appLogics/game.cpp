#include "game.h"
#include "MainWindowAdapter.h"

Game::Game(int& argc, char** argv):
	QApplication(argc, argv),
    gameMaster(QSharedPointer<GameMaster>(NULL)),
    mConnectionMenu(NULL)
{

	#ifdef WIDGETS_VIEW
		view = QSharedPointer<InterfaceMainWindow>(new MainWindowAdapter());
	#elif QML_VIEW
		view = QSharedPointer<InterfaceMainWindow>(new QmlMainWindow());
	#endif

	QSharedPointer<InterfaceConnectWidget> connectWidget = view->getInterfaceConnectWidget();
    mConnectionMenu = QSharedPointer<ConnectionMenu>(new ConnectionMenu(this, connectWidget));
	audioPlayer = QSharedPointer<AudioPlayer> (new AudioPlayer);

	connect(view->getInterfaceSettingsMenu().data(), SIGNAL(volumeChanched(int))
			, audioPlayer.data(), SLOT(setVolume(int)));
	connect(view->getInterfaceSettingsMenu().data(), SIGNAL(mute(bool))
			, audioPlayer.data(), SLOT(mute(bool)));

	connect(view->getInterfaceStartMenu().data(), SIGNAL(buttonExitPushed()), SLOT(exitButtonHandler()));
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
	view->showWidget(START_MENU);
	view->showMain();
}

void Game::aiLevelMenu()
{
	hideAllWidget();
	view->showWidget(AI_MENU);
	gameMaster.reset();
	gameMaster.clear();
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
    gameMaster = QSharedPointer<GameMaster>(new AiGameMaster(AiGameMaster::EASY,
														   view->getInterfaceBattleWidget(),
														   audioPlayer,
                                                           this));
    connect(gameMaster.data(), SIGNAL(gameInterrupted()), SLOT(handleBW()));
	gameMaster->startGame();
}

void Game::startAIHardGame()
{
	hideAllWidget();
	view->showWidget(BATTLE);
    gameMaster = QSharedPointer<GameMaster>(new AiGameMaster(AiGameMaster::HARD,
														   view->getInterfaceBattleWidget(),
														   audioPlayer,
                                                           this));
    connect(gameMaster.data(), SIGNAL(gameInterrupted()), SLOT(handleBW()));
	gameMaster->startGame();
}

void Game::startNetworkGame(const QSharedPointer<Client>& client)
{
	hideAllWidget();
	view->showWidget(BATTLE);
	gameMaster = QSharedPointer<GameMaster>(new NetworkGameMaster(view->getInterfaceBattleWidget(),
														   audioPlayer,
                                                           client,
                                                           this));
    connect(gameMaster.data(), SIGNAL(gameInterrupted()), SLOT(handleBW()));
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
	gameMaster.reset();
	gameMaster.clear();
	view->getInterfaceBattleWidget()->clearItself();
	gameMenu();
}

void Game::exitButtonHandler()
{
	qDebug() << "Exit ...";
	// closeAllWindows() doesn't work with QQuickWindow for some reasons
	#ifdef WIDGETS_VIEW
		closeAllWindows();
	#elif QML_VIEW
		quit();
	#endif
}

void Game::hideAllWidget()
{
	view->hideWidget(START_MENU);
	view->hideWidget(BATTLE);
	view->hideWidget(AI_MENU);
	view->hideWidget(CONNECT);
	view->hideWidget(SETTINGS);
}


