#include "playerField.h"

PlayerField::PlayerField(QObject *parent) :
    QObject(parent)
{
}

AttackStatus PlayerField::attack(int id)
{
    int x = id / FIELD_ROW_NUM;
    int y = id % FIELD_COL_NUM;
    return field[x][y].attack();
}

QSharedPointer<Ship> PlayerField::getShip(int id)
{
    int x = id / FIELD_ROW_NUM;
    int y = id - x * FIELD_ROW_NUM;
    if (!checkCoord(x, y))
    {
        return QSharedPointer<Ship>();
    }
    return field[x][y].getShip();
}

void PlayerField::setShip(int id, bool orientation, QSharedPointer<Ship> ship)
{
    QPair<int, int> coord = coordinates(id);
    int row = coord.first;
    int col = coord.second;
    // if orientation == true, then ship has horizontal orientation
    if (orientation)
    {
        for (int i = 0; i < ship->health(); i++)
        {
            if (checkCoord(row, col + i))
            {
                field[row][col + i].setShip(ship);
            }
        }
    }
    // otherwise - vertical orientation
    else
    {
        for (int i = 0; i < ship->health(); i++)
        {
            if (checkCoord(row + i, col))
            {
                field[row + i][col].setShip(ship);
            }
        }
    }
}
