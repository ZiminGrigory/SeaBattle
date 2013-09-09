#include "enemyField.h"

EnemyField::EnemyField(View* _view, QObject *parent) :
    QObject(parent),
    lastAttackedCellId(0),
    view(_view)
{
    /*
    for (int i = 0; i < FIELD_ROW_NUM; i++)
    {
        for (int j = 0; j < FIELD_COL_NUM; j++)
        {
            field[i][j].setView(view->getCellView(ENEMY, getIdByCoordinates(i, j)));
        }
    }
    */
}

void EnemyField::attackResult(AttackStatus res)
{
    int x = lastAttackedCellId / FIELD_ROW_NUM;
    int y = lastAttackedCellId - x * FIELD_ROW_NUM;

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

bool EnemyField::attack(int id)
{
    int i = id / FIELD_ROW_NUM;
    int j = id % FIELD_COL_NUM;
    if (!checkCoord(i, j) || !field[i][j].attack())
    {
        return false;
    }
    else
    {
        lastAttackedCellId = id;
        return true;
    }
}

void EnemyField::setPlr(Players _plr)
{
    plr = _plr;
}

void EnemyField::markKilled(int i, int j, QStack<Coord> *markedCells)
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
