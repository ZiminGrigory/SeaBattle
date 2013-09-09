#include "enemyCell.h"

EnemyCell::EnemyCell(QObject *parent) :
    QObject(parent),
    state(WAS_NOT_ATTACKED),
    attackStatus(NOT_ATTACKED),
    cellView(NULL)
{
}

void EnemyCell::mark(AttackStatus res)
{
    state = WAS_NOT_ATTACKED;
    attackStatus = res;
}

bool EnemyCell::attack()
{
    return (state == WAS_NOT_ATTACKED);
}

void EnemyCell::setView(Cell* _cellView)
{
    cellView = _cellView;
}

AttackStatus EnemyCell::getAttackStatus()
{
    return attackStatus;
}
