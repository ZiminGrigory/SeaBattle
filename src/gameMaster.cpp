#include "gameMaster.h"

GameMaster::GameMaster(Player *plr1, Player *plr2, const FleetFactory& fleetCreator, QObject* parent):
    QObject(parent),
    player1(plr1),
    player2(plr2)
{
    player1->createFleet(fleetCreator);
    player2->createFleet(fleetCreator);

    turnedPlayer = player1;
    waitingPlayer = player2;

    connect(player1.data(), SIGNAL(turnMade(int)), this, SLOT(informOpponent(int)));
    connect(player2.data(), SIGNAL(turnMade(int)), this, SLOT(informOpponent(int)));

    connect(player1.data(), SIGNAL(attackResult(AttackStatus)), this, SLOT(informPlayer(AttackStatus)));
    connect(player2.data(), SIGNAL(attackResult(AttackStatus)), this, SLOT(informPlayer(AttackStatus)));
}

void GameMaster::offerTurn()
{
    turnedPlayer->turn();
}

void GameMaster::informOpponent(int id)
{
    waitingPlayer->enemyTurn(id);
}

void GameMaster::informPlayer(AttackStatus attackResult)
{
    turnedPlayer->turnResult(attackResult);
    nextTurn(attackResult);
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
        waitingPlayer = turnedPlayer;
    }
    else
    {
        // if ship was wounded or killed then
        // next turn make the same player
    }

    if (waitingPlayer->lose())
    {
        // to do: end game and send message about win.
    }
    else
    {
        // else continue game
        offerTurn();
    }
}
