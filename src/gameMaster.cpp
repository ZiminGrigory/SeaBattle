#include "gameMaster.h"

GameMaster::GameMaster(QObject* parent):
    QObject(parent)
{


    connect(player1.data(), SIGNAL(turnMade(int)), this, SLOT(informOpponent(int)));
    connect(player2.data(), SIGNAL(turnMade(int)), this, SLOT(informOpponent(int)));
}

void GameMaster::offerTurn()
{
    turnedPlayer->turn();
}

void GameMaster::informOpponent(int id)
{
    informPlayer(waitingPlayer->enemyTurn(id));
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

    offerTurn();
}
