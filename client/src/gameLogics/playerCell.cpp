#include "playerCell.h"

PlayerCell::PlayerCell(QObject *parent) :
    QObject(parent),
    ship(NULL)
{
}

AttackStatus PlayerCell::attack()
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

QSharedPointer<Ship> PlayerCell::getShip()
{
    return ship;
}

void PlayerCell::setShip(const QSharedPointer<Ship> &_ship)
{
    ship = _ship;
}

void PlayerCell::mark(AttackStatus res)
{
}

void PlayerCell::setView(Cell *_cellView)
{
	cellView = _cellView;
}

void PlayerCell::deleteShip()
{
	ship.clear();
}
