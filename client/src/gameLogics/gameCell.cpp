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
            mark(KILLED);
            return KILLED;
        }
        else
        {
            mark(WOUNDED);
            return WOUNDED;
        }
    }
    else
    {
        mark(MISS);
        return MISS;
    }
}

bool GameCell::attackable()
{
    return (state == WAS_NOT_ATTACKED);
}

QSharedPointer<Ship> GameCell::getShip()
{
    return ship;
}

void GameCell::setShip(const QSharedPointer<Ship> &_ship)
{
    ship = _ship;
}
