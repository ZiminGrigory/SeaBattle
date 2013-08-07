#include "playerField.h"

PlayerField::PlayerField(QObject *parent) :
    QObject(parent)
{
}

AttackStatus PlayerField::attack(int id)
{
    int x = id / FIELD_ROW_NUM;
    int y = id - x * FIELD_ROW_NUM;
    return field[x][y].attack();
}
