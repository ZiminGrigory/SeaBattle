#include "gameField.h"

void GameField::setShip(int id, bool orientation, QSharedPointer<Ship> ship)
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

QSharedPointer<Ship> GameField::getShip(int id)
{
    int x = id / FIELD_ROW_NUM;
    int y = id - x * FIELD_ROW_NUM;
    if (!checkCoord(x, y))
    {
        return QSharedPointer<Ship>();
    }
    return field[x][y].getShip();
}

void GameField::removeShip(int id)
{

}

AttackStatus GameField::attack(int id)
{
    int x = id / FIELD_ROW_NUM;
    int y = id - x * FIELD_ROW_NUM;

    if (res == MISS)
    {
        view->paintCell(ENEMY, getIdByCoordinates(x, y), MISS_CELL);
        field[x][y].mark(res);
    }
    else if (res == WOUNDED)
    {
        view->paintCell(ENEMY, getIdByCoordinates(x, y), SHIP_DAMAGED);
        field[x][y].mark(res);
    }
    else if (res == KILLED)
    {
        view->paintCell(ENEMY, getIdByCoordinates(x, y), SHIP_KILLED);
        field[x][y].mark(res);
        QStack<Coord> markedCells;
        markedCells.push(Coord(x, y));
        while (!markedCells.isEmpty())
        {
            Coord coord = markedCells.pop();
            int _x = coord.first;
            int _y = coord.second;
            markKilled(_x + 1, _y, &markedCells);
            markKilled(_x + 1, _y + 1, &markedCells);
            markKilled(_x, _y + 1, &markedCells);
            markKilled(_x - 1, _y + 1, &markedCells);
            markKilled(_x - 1, _y, &markedCells);
            markKilled(_x - 1, _y - 1, &markedCells);
            markKilled(_x, _y - 1, &markedCells);
            markKilled(_x + 1, _y - 1, &markedCells);
        }
    }
}

bool GameField::attackable()
{
    int i = id / FIELD_ROW_NUM;
    int j = id % FIELD_COL_NUM;
    if (!checkCoord(i, j) || !field[i][j].attackable())
    {
        return false;
    }
    else
    {
        return true;
    }
}

void GameField::markKilled(int i, int j, QStack<Coord>* markedCells)
{
    if (checkCoord(i, j))
    {
        if (field[i][j].getAttackStatus() == KILLED)
        {
            view->paintCell(plr, getIdByCoordinates(i, j), SHIP_KILLED);
            return;
        }
        else if (field[i][j].getAttackStatus() == WOUNDED)
        {
            field[i][j].mark(KILLED);
            view->paintCell(plr, getIdByCoordinates(i, j), SHIP_KILLED);
            markedCells->push(Coord(i, j));
        }
        else
        {
            field[i][j].mark(MISS);
            view->paintCell(plr, getIdByCoordinates(i, j), MISS_CELL);
        }
    }
}
