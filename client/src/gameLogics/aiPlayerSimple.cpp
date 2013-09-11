#include "aiPlayerSimple.h"

AIPlayerSimple::AIPlayerSimple(const QSharedPointer<GameField> &plrField,
								const QSharedPointer<GameField> &enmField,
								 QObject *parent):
    AIPlayer(plrField, enmField, parent)
{
    isWounded = false;
    lastAttackResult = NOT_ATTACKED;
    for(int i = 0; i < 3; i++)
        attackedCells[i] = 0;
    //connect(this, SIGNAL(turnMade(int)), );
    qsrand(QTime::currentTime().msec());
}

void AIPlayerSimple::installFleet(const QSharedPointer<FleetInstaller> &fleetInstaller)
{
    this->randomInstallFleet(fleetInstaller);
	emit fleetInstalled(this);
}



void AIPlayerSimple::turn()
{
    QTimer::singleShot(AIPlayer::delay, this, SLOT(delayTurn()));
}

void AIPlayerSimple::delayTurn()
{
    int id = 0;
    if((isWounded) && (lastAttackResult == WOUNDED)) // here we've found right direction for attack (3 or 4 ships)
    {
        switch(direction)
        {
        case LEFT:
            id = lastAttackedCell - 1;
            break;
        case DOWN:
            id = lastAttackedCell + 10;
            break;
        case RIGHT:
            id = lastAttackedCell  + 1;
            break;
        case HIGH:
            id = lastAttackedCell - 10;
            break;
        }
    }
    else if ((isWounded) && (lastAttackResult == MISS))
    {
        id = tryToKill(lastAttackedCell);
    }
    else
    {
        switch(lastAttackResult)
        {
        case (NOT_ATTACKED):
            id = this->chooseRandomCell();
            lastAttackedCell = id;
            break;
        case(MISS):
            id = chooseRandomCell();
            isWounded = false;
            clear();
            lastAttackedCell = id;
            break;
        case(WOUNDED):
            isWounded = true;
            id = tryToKill(lastAttackedCell);
            break;
        case (KILLED):
            id = this->chooseRandomCell();
            isWounded = false;
            clear();
            lastAttackedCell = id;
            break;
        }


    }
    lastAttackResult = enemyField->attack(id);
    emit turnMade(id, lastAttackResult);
}

