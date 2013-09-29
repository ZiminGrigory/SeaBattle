#include "gameMaster.h"

const int GameMaster::turnTimeout = 30 * 1000;


GameMaster::GameMaster(GameType type,
					   const QSharedPointer<InterfaceBattleWidget> &_view,
					   QObject* parent):

    QObject(parent),
    playerField(NULL),
    enemyField(NULL),
    player(NULL),
	enemy(NULL),
	view(_view)/*,
	audioPlayer(QSharedPointer<AudioPlayer>(new AudioPlayer()))*/
{   
	view->showPlayerField();
	view->showInfoTab();
	playerField = QSharedPointer<GameField>(new PlayerField(view->getPlayerFieldView()));
    enemyField = QSharedPointer<GameField>(new GameField(view->getEnemyFieldView()));

	player = QSharedPointer<Player>(new HumanPlayer(playerField, enemyField
													, view->getPlayerFieldView()
                                                    , view->getEnemyFieldView()
                                                    , view->getInfoTabView()));
    if (type == AI_SIMPLE_GAME)
    {
        enemy = QSharedPointer<Player>(new AIPlayerSimple(enemyField, playerField));
    }
    else if (type == AI_HARD_GAME)
    {
        // ai hard not implemented yet
        enemy = QSharedPointer<Player>(new AIPlayerSimple(enemyField, playerField));
    }

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
    QSharedPointer<FleetInstaller> playerInst(new FleetInstaller(FleetFactory::createFleet(),
                                                                 playerField, view->getInfoTabView()));
    player->installFleet(playerInst);

    QSharedPointer<FleetInstaller> enemyInst(new FleetInstaller(FleetFactory::createFleet(),
											 enemyField, QSharedPointer<InterfaceInfoTab>(NULL)));
    enemy->installFleet(enemyInst);

    turnedPlayer = player;
    waitingPlayer = enemy;
  // audioPlayer->playSound(BEGIN_SOUND);
}

void GameMaster::playerReadyToBattle(Player* sender)
{
    static bool isFirst = true;
    if (player == sender)
    {
        disconnect(player.data(), SIGNAL(fleetInstalled(Player*)), this, SLOT(playerReadyToBattle(Player*)));
    }
    else if (enemy == sender)
    {
        disconnect(enemy.data(), SIGNAL(fleetInstalled(Player*)), this, SLOT(playerReadyToBattle(Player*)));
    }
    if (!isFirst)
    {
        view->showEnemyField();
        view->getEnemyFieldView()->setEnabled(true);
        view->getPlayerFieldView()->setEnabled(false);
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
//        audioPlayer->playSound(MISS_SOUND);

    }
    else if (turnResult == WOUNDED)
    {
        // if ship was wounded or killed then
        // next turn make the same player
//        audioPlayer->playSound(WOUNDED_SOUND);
    }
    else if (turnResult == KILLED)
    {
//        audioPlayer->playSound(KILLED_SOUND);
    }
    if (player->lose())
    {
		view->hideTimer();
        view->setMessage("Enemy Win");
//        audioPlayer->playSound(DEFEAT_SOUND);
		view->getEnemyFieldView()->showResult(YOU);
		view->getPlayerFieldView()->showResult(YOU);
    }
    else if (enemy->lose())
    {
		view->hideTimer();
        view->setMessage("You Win");
//        audioPlayer->playSound(VICTORY_SOUND);
		view->getPlayerFieldView()->showResult(ENEMY);
		view->getEnemyFieldView()->showResult(ENEMY);
    }
    else
    {
        // else continue game
        offerTurn();
    }
}
