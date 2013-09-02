#include "enemyField.h"

EnemyField::EnemyField(QObject *parent) :
    QObject(parent)
{
    /*
    for (int i = 0; i < FIELD_ROW_NUM; i++)
    {
        for (int j = 0; j < FIELD_COL_NUM; j++)
        {
            connect(&field[i][j], SIGNAL(attacked()), &mapper, SLOT(map()));
            mapper.setMapping(&field[i][j], i * FIELD_ROW_NUM + j);
        }
    }
    connect(&mapper, SIGNAL(mapped(int)), this, SLOT(attack(int)));
    */
}

void EnemyField::attackResult(AttackStatus res)
{
    int x = lastAttackedCellId / FIELD_ROW_NUM;
    int y = lastAttackedCellId - x * FIELD_ROW_NUM;
    if ((res == MISS) || (res == WOUNDED))
    {
        field[x][y].mark(res);
    }
    else if (res == KILLED)
    {
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

void EnemyField::markKilled(int i, int j, QStack<Coord> *markedCells)
{
    if (checkCoord(i, j))
    {
        if (field[i][j].getAttackStatus() == KILLED)
        {
            return;
        }
        else if (field[i][j].getAttackStatus() == WOUNDED)
        {
            field[i][j].mark(KILLED);
            markedCells->push(Coord(i, j));
        }
        else
        {
            field[i][j].mark(MISS);
        }
    }
}
