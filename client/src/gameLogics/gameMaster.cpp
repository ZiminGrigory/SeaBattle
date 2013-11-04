#include "gameMaster.h"


GameMaster::GameMaster(const QSharedPointer<InterfaceBattleWidget> &_view,
					   const QSharedPointer<AudioPlayer> _audioPlayer,
					   QObject* parent):

	QObject(parent),
	playerField(new PlayerField(_view->getPlayerFieldView(), _view->getInfoTabView())),
	enemyField(new GameField(_view->getEnemyFieldView())),
	mChat(new LogAndChat(_view->getChatAndStatus())),
	view(_view),
	audioPlayer(_audioPlayer),
	isFirst(true)
{   
	view->showPlayerField();
	view->showInfoTab();

	turnedPlayer = player;
	waitingPlayer = enemy;
}

void GameMaster::startGame()
{
	connect(player.data(), SIGNAL(fleetInstalled(Player*)), this, SLOT(playerReadyToBattle(Player*)));
	connect(enemy.data(), SIGNAL(fleetInstalled(Player*)), this, SLOT(playerReadyToBattle(Player*)));

	view->showPlayerField();
	view->getPlayerFieldView()->setAttackable(true);
	view->showInfoTab();
	view->setMessage("Install fleet");

	player->installFleet();
	enemy->installFleet();

	audioPlayer->playSound(BEGIN_SOUND);
}

void GameMaster::quitHandler()
{
	emit gameInterrupted();
	// nothing to do here
}

void GameMaster::chat(const QString& message)
{
	Player* sender = qobject_cast<Player*>(QObject::sender());
	if (sender == player)
	{
		mChat->playerMessage(YOU, message);
	}
	else if (sender == enemy)
	{
		mChat->playerMessage(ENEMY, message);
	}
}

void GameMaster::playerReadyToBattle(Player* sender)
{
	if (player == sender)
	{
		disconnect(player.data(), SIGNAL(fleetInstalled(Player*)), this, SLOT(playerReadyToBattle(Player*)));
		if (isFirst)
		{
			turnedPlayer = player;
			waitingPlayer = enemy;
		}
		view->setMessage("Ждём соперника");
		view->getInfoTabView()->playerReady(YOU);
	}
	else if (enemy == sender)
	{
		disconnect(enemy.data(), SIGNAL(fleetInstalled(Player*)), this, SLOT(playerReadyToBattle(Player*)));
		if (isFirst)
		{
			turnedPlayer = enemy;
			waitingPlayer = player;
		}
		view->setMessage("Противник готов");
		view->getInfoTabView()->playerReady(ENEMY);
	}
	if (!isFirst)
	{
		view->showEnemyField();
		view->getEnemyFieldView()->setAttackable(true);
		view->getPlayerFieldView()->setAttackable(false);
		plrFleet = 10;
		enemyFleet = 10;
		view->setCountOfFleet(YOU, plrFleet);
		view->setCountOfFleet(ENEMY, enemyFleet);
		view->showCountersOfFleet();
		offerTurn();
	}
	isFirst = false;
}

void GameMaster::offerTurn()
{
	offerTurnHook();
	if (turnedPlayer == player){
		view->setMessage("Your Turn");
	} else{
		view->setMessage("Enemy Turn");

	}
	connect(turnedPlayer.data(), SIGNAL(turnMade(int, AttackStatus)), this, SLOT(informOpponent(int, AttackStatus)));

	turnedPlayer->turn();
}

void GameMaster::informOpponent(int id, AttackStatus turnResult)
{
	informOpponentHook();
	disconnect(turnedPlayer.data(), SIGNAL(turnMade(int, AttackStatus)), this, SLOT(informOpponent(int, AttackStatus)));

	waitingPlayer->enemyTurn(id);
	if(turnedPlayer == player) {
		mChat->cellAttacked(ENEMY, id, turnResult);
	} else {
		mChat->cellAttacked(YOU, id, turnResult);
	}
	nextTurn(turnResult);
}

void GameMaster::nextTurn(AttackStatus turnResult)
{
	// if result of current turn NOT_ATTACKED then something goes wrong
	if (turnResult == NOT_ATTACKED)
	{
		// to do: throw an exception
	}
	else if (turnResult == MISS)
	{
		// swap the turned and waiting players
		ptrPlayer tmp = turnedPlayer;
		turnedPlayer = waitingPlayer;
		waitingPlayer = tmp;
		audioPlayer->playSound(MISS_SOUND);
	}
	else if (turnResult == WOUNDED)
	{
		// if ship was wounded or killed then
		// next turn make the same player
		audioPlayer->playSound(WOUNDED_SOUND);
	}
	else if (turnResult == KILLED)
	{
		audioPlayer->playSound(KILLED_SOUND);
		if (turnedPlayer == player){
			enemyFleet--;
			view->setCountOfFleet(ENEMY, enemyFleet);
		} else {
			plrFleet--;
			view->setCountOfFleet(YOU, plrFleet);
		}
	}
	if (player->lose())
	{
		view->hideTimer();
		view->setMessage("Enemy Win");
		audioPlayer->playSound(DEFEAT_SOUND);
		view->getEnemyFieldView()->showResult(YOU);
		view->getPlayerFieldView()->showResult(YOU);
	}
	else if (enemy->lose())
	{
		view->hideTimer();
		view->setMessage("You Win");
		audioPlayer->playSound(VICTORY_SOUND);
		view->getPlayerFieldView()->showResult(ENEMY);
		view->getEnemyFieldView()->showResult(ENEMY);
	}
	else
	{
		// else continue game
		offerTurn();
	}
}

void GameMaster::playShipSetSound(PlacementStatus status)
{
	Q_UNUSED(status);
	if (status == OK)
	{
		audioPlayer->playSound(SHIP_SET_SOUND);
	}
	else
	{
		audioPlayer->playSound(SHIP_SET_ERR_SOUND);
	}
}

void GameMaster::playerWantToQuit()
{
	view->showQuitDialog();
}

void GameMaster::initConnections()
{
	connect(player.data(), SIGNAL(chat(QString)), SLOT(chat(QString)));
	connect(enemy.data(), SIGNAL(chat(QString)), SLOT(chat(QString)));

	connect(player.data(), SIGNAL(quit()), this, SLOT(playerWantToQuit()));
	connect(view.data(), SIGNAL(quitDialogOkPressed()), this, SLOT(quitHandler()));

	connect(playerField.data(), SIGNAL(shipPlacementResult(PlacementStatus)),
			this, SLOT(playShipSetSound(PlacementStatus)));
}

void GameMaster::offerTurnHook()
{

}

void GameMaster::informOpponentHook()
{

}
