#include "enemyField.h"

EnemyField::EnemyField(QObject *parent) :
    QObject(parent),
    mapper(this)
{
    for (int i = 0; i < FIELD_ROW_NUM; i++)
    {
        for (int j = 0; j < FIELD_COL_NUM; j++)
        {
            connect(&field[i][j], SIGNAL(attacked()), &mapper, SLOT(map()));
            mapper.setMapping(&field[i][j], i * FIELD_ROW_NUM + j);
        }
    }
    connect(&mapper, SIGNAL(mapped(int)), this, SLOT(attack(int)));
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

void EnemyField::attack(int id)
{
    lastAttackedCellId = id;
    emit attacked(id);
}

void EnemyField::markKilled(int x, int y, QStack<Coord> *markedCells)
{
    if (checkCoord(x, y))
    {
        if (field[x][y].getAttackStatus() == KILLED)
        {
            return;
        }
        else if (field[x][y].getAttackStatus() == WOUNDED)
        {
            field[x][y].mark(KILLED);
            markedCells->push(Coord(x, y));
        }
        else
        {
            field[x][y].mark(MISS);
        }
    }
}

bool EnemyField::checkCoord(int x, int y)
{
    return !((x < 0) || (x >= FIELD_ROW_NUM) || (y < 0) || (y >= FIELD_COL_NUM));
}
