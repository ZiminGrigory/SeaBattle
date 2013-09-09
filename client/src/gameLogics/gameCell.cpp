#include "gameCell.h"

GameCell::GameCell(): attackStatus(NOT_ATTACKED)
{
}

AttackStatus GameCell::attack()
{
    if (ship)
    {
        int health = ship->damage();
        if (health == 0)
        {
			attackStatus = KILLED;
			return KILLED;
        }
        else
        {
			attackStatus = WOUNDED;
            return WOUNDED;
        }
    }
    else
    {
		attackStatus = MISS;
        return MISS;
    }
}

bool GameCell::attackable()
{
    return (state == WAS_NOT_ATTACKED);
}

AttackStatus GameCell::getAttackStatus()
{
    return attackStatus;
}

QSharedPointer<Ship> GameCell::getShip()
{
    return ship;
}

void GameCell::setShip(const QSharedPointer<Ship> &_ship)
{
    ship = _ship;
}

void GameCell::removeShip()
{
    ship = QSharedPointer<Ship>(NULL);
}
