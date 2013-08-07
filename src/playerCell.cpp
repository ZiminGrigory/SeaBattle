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

void PlayerCell::mark(AttackStatus res)
{
}
