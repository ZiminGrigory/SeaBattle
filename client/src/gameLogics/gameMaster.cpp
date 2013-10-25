#include "gameMaster.h"

const int GameMaster::turnTimeout = 30 * 1000;


GameMaster::GameMaster(GameType type,
					   const QSharedPointer<InterfaceBattleWidget> &_view,
					   const QSharedPointer<Client> &_client, const QSharedPointer<AudioPlayer> audioPlayer,
					   QObject* parent):

    QObject(parent),
    playerField(NULL),
    enemyField(NULL),
    player(NULL),
	enemy(NULL),
    view(_view),
	audioPlayer(audioPlayer),
	client(_client),
	isFirst(true)
{   
	view->showPlayerField();
	view->showInfoTab();
    playerField = QSharedPointer<GameField>(new PlayerField(view->getPlayerFieldView(), view->getInfoTabView()));
    enemyField = QSharedPointer<GameField>(new GameField(view->getEnemyFieldView()));

    if (type == AI_SIMPLE_GAME)
    {
		player = QSharedPointer<Player>(new HumanPlayer(playerField, enemyField
                                                        , view->getPlayerFieldView()
                                                        , view->getEnemyFieldView()
														, view->getInfoTabView()
														, view->getChatAndStatus()));
        enemy = QSharedPointer<Player>(new AIPlayerSimple(enemyField, playerField));
    }
    else if (type == AI_HARD_GAME)
    {
		player = QSharedPointer<Player>(new HumanPlayer(playerField, enemyField
                                                        , view->getPlayerFieldView()
                                                        , view->getEnemyFieldView()
														, view->getInfoTabView()
														, view->getChatAndStatus()));
        // ai hard not implemented yet
        enemy = QSharedPointer<Player>(new AIPlayerSmart(enemyField, playerField));
    }

    else if (type == NETWORK_GAME)
    {
		player = QSharedPointer<Player>(new NetworkHumanPlayer(playerField
                                                               , enemyField
                                                               , view->getPlayerFieldView()
                                                               , view->getEnemyFieldView()
                                                               , view->getInfoTabView()
															   , view->getChatAndStatus()
                                                               , client));
        enemy = QSharedPointer<Player>(new RemotePlayer(enemyField
                                                        , playerField
                                                        , client));
    }

	mChat = QSharedPointer<LogAndChat>(new LogAndChat(view->getChatAndStatus()));


    connect(player.data(), SIGNAL(chat(QString)), SLOT(chat(QString)));
    connect(enemy.data(), SIGNAL(chat(QString)), SLOT(chat(QString)));

    connect(playerField.data(), SIGNAL(shipPlacementResult(PlacementStatus)),
            this, SLOT(playShipSetSound(PlacementStatus)));

	turnedPlayer = player;
	waitingPlayer = enemy;
    turnTimer.setSingleShot(true);
}

void GameMaster::startGame()
{
    connect(player.data(), SIGNAL(fleetInstalled(Player*)), this, SLOT(playerReadyToBattle(Player*)));
    connect(enemy.data(), SIGNAL(fleetInstalled(Player*)), this, SLOT(playerReadyToBattle(Player*)));

    view->showPlayerField();
    view->getPlayerFieldView()->setEnabled(true);
    view->showInfoTab();
    view->setMessage("Install fleet");

    player->installFleet();
    enemy->installFleet();

    audioPlayer->playSound(BEGIN_SOUND);
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
    }
    else if (enemy == sender)
    {
        disconnect(enemy.data(), SIGNAL(fleetInstalled(Player*)), this, SLOT(playerReadyToBattle(Player*)));
        if (isFirst)
        {
            turnedPlayer = enemy;
            waitingPlayer = player;
        }
    }
    if (!isFirst)
    {
        view->showEnemyField();
        view->getEnemyFieldView()->setEnabled(true);
        view->getPlayerFieldView()->setEnabled(false);
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
    if (turnedPlayer == player){
        view->setMessage("Your Turn");
	} else{
        view->setMessage("Enemy Turn");

	}
    connect(turnedPlayer.data(), SIGNAL(turnMade(int, AttackStatus)), this, SLOT(informOpponent(int, AttackStatus)));
    connect(&turnTimer, SIGNAL(timeout()), turnedPlayer.data(), SLOT(randomTurn()));
    turnTimer.start(turnTimeout);
    view->setTime(turnTimeout / 1000);

    turnedPlayer->turn();
}

void GameMaster::informOpponent(int id, AttackStatus turnResult)
{
    disconnect(turnedPlayer.data(), SIGNAL(turnMade(int, AttackStatus)), this, SLOT(informOpponent(int, AttackStatus)));
    turnTimer.stop();
    //disconnect(&turnTimer, SIGNAL(timeout()), turnedPlayer.data(), SLOT(randomTurn()));

    waitingPlayer->enemyTurn(id);
	if(turnedPlayer == player) {
		mChat->cellAttacked(ENEMY, id, turnResult);
	} else {
		mChat->cellAttacked(YOU, id, turnResult);
	}
    nextTurn(turnResult);
}

/*
void GameMaster::informPlayer(AttackStatus attackResult)
{
    turnedPlayer->turnResult(attackResult);
    nextTurn(attackResult);
}
*/

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
    audioPlayer->playSound(SHIP_SET_SOUND);
}
