#include "playerField.h"

PlayerField::PlayerField(View* _view, QObject *parent) :
    QObject(parent),
    view(_view)
{
    /*
    for (int i = 0; i < FIELD_ROW_NUM; i++)
    {
        for (int j = 0; j < FIELD_COL_NUM; j++)
        {
            field[i][j].setView(view->getCellView(YOU, getIdByCoordinates(i, j)));
        }
    }
    */
}

AttackStatus PlayerField::attack(int id)
{
    int x = id / FIELD_ROW_NUM;
    int y = id % FIELD_COL_NUM;
    AttackStatus status =  field[x][y].attack();

    if (status == MISS)
    {
        view->paintCell(plr, id, MISS_CELL);
    }
    else if (status == WOUNDED)
    {
        view->paintCell(plr, id, SHIP_DAMAGED);
    }
    else if (status == KILLED)
    {
        view->paintCell(plr, id, SHIP_KILLED);
    }
    return status;
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
                view->paintCell(plr, getIdByCoordinates(row, col + i), SHIP_SINGLE);
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
                view->paintCell(plr, getIdByCoordinates(row + i, col), SHIP_SINGLE);
            }
        }
    }
}

void PlayerField::setPlr(Players _plr)
{
    plr = _plr;
}
