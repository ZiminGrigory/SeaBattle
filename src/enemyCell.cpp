#include "enemyCell.h"

EnemyCell::EnemyCell(QObject *parent) :
    QObject(parent),
    state(HIDE),
    attackStatus(NOT_ATTACKED)
{
}

void EnemyCell::mark(AttackStatus res)
{
    attackStatus = res;
}

void EnemyCell::attack()
{
    emit attacked();
}

AttackStatus EnemyCell::getAttackStatus()
{
    return attackStatus;
}
