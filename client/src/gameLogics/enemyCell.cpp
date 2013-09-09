#include "enemyCell.h"

EnemyCell::EnemyCell(QObject *parent) :
    QObject(parent),
    state(HIDE),
    attackStatus(NOT_ATTACKED),
    cellView(NULL)
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

void EnemyCell::setView(Cell* _cellView)
{
    cellView = _cellView;
}

AttackStatus EnemyCell::getAttackStatus()
{
    return attackStatus;
}
