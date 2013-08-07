#include "enemyCell.h"

EnemyCell::EnemyCell(QObject *parent) :
    QObject(parent),
    state(HIDE),
    attackStatus(NOT_ATTACKED)
{
}

void EnemyCell::mark(AttackStatus res)
{
    state = VISIBLE;
    attackStatus = res;
}

bool EnemyCell::attack()
{
    return (state == HIDE);
}

AttackStatus EnemyCell::getAttackStatus()
{
    return attackStatus;
}
