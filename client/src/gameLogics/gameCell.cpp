#include "gameCell.h"

GameCell::GameCell()
{
}

AttackStatus GameCell::attack()
{
    if (ship)
    {
        int health = ship->damage();
        if (health == 0)
        {
            return KILLED;
        }
        else
        {
            return WOUNDED;
        }
    }
    else
    {
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
