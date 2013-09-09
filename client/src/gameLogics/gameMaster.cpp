#include "gameMaster.h"

GameMaster::GameMaster(const QSharedPointer<View>& _view,
                       QObject* parent):
    QObject(parent),
    playerField(NULL),
    enemyField(NULL),
    player(NULL),
    enemy(NULL),
    view(_view)
{
    playerField = QSharedPointer<GameField>(new GameField(view->getPlayerFieldView()));
    enemyField = QSharedPointer<GameField>(new GameField(view->getEnemyFieldView()));

    player = QSharedPointer<Player>(new HumanPlayer(playerField, enemyField, view->getPlayerFieldView()));
    enemy = QSharedPointer<Player>(new AIPlayer(enemyField, playerField));
}

void GameMaster::startGame()
{
    connect(player.data(), SIGNAL(turnMade(int)), this, SLOT(informOpponent(int)));
    connect(enemy.data(), SIGNAL(turnMade(int)), this, SLOT(informOpponent(int)));
    connect(player.data(), SIGNAL(fleetInstalled()), this, SLOT(playerReadyToBattle()));
    connect(enemy.data(), SIGNAL(fleetInstalled()), this, SLOT(playerReadyToBattle()));

    view->showPlayerField();
    view->getPlayerFieldView()->setEnabled(true);
    view->showInfoTab();

    view->setMessage("Установка флота");
    QSharedPointer<FleetInstaller> playerInst(new FleetInstaller(FleetFactory::createFleet(),
                                                                 playerField, view->getInfoTabView()));
    player->installFleet(playerInst);

    QSharedPointer<FleetInstaller> enemyInst(new FleetInstaller(FleetFactory::createFleet(),
                                             enemyField, QSharedPointer<InfoTabView>(NULL)));
    enemy->installFleet(enemyInst);

    turnedPlayer = player;
    waitingPlayer = enemy;
}

void GameMaster::playerReadyToBattle()
{
    static int playersReady = 2;
    --playersReady;
    if (playersReady == 0)
    {
        view->showEnemyField();
        view->getEnemyFieldView()->setEnabled(true);
        view->getPlayerFieldView()->setEnabled(false);
        offerTurn();
    }
}

void GameMaster::offerTurn()
{
    if (turnedPlayer == player){
        view->setMessage("ВАШ ХОД");
	} else{
        view->setMessage("ХОД ПРОТИВНИКА");
	}
    turnedPlayer->turn();
}

void GameMaster::informOpponent(int id)
{
    waitingPlayer->enemyTurn(id);
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
    }
    else
    {
        // if ship was wounded or killed then
        // next turn make the same player
    }

    if (player->lose() || enemy->lose())
    {
        // to do: end game and send message about win.
    }
    else
    {
        // else continue game
        offerTurn();
    }
}
