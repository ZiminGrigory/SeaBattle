#include "squareShootStrategy.h"

SquareShootStrategy::SquareShootStrategy(const QSharedPointer<GameField>& enmField):
    enemyField(enmField),
    id(0)
{
    qsrand(QTime::currentTime().msec());
}

DiagonalShoot::DiagonalShoot(const QSharedPointer<GameField> &enmField):
    SquareShootStrategy(enmField)
{

}

int SquareShootStrategy::squareSize(int squareNumberWidth, int squareNumberHeight, int size)
{
    int squaresize;
    switch (size) {
    case 4:
        if (squareNumberHeight <= 1 && squareNumberWidth <= 1)
            squaresize = 4;
        else
            squaresize = 2;
        break;
    case 3:
        if(squareNumberHeight < 3 && squareNumberWidth < 3)
            squaresize = 3;
        else
            squaresize = 1;

    }
    return squaresize;

}

bool DiagonalShoot::hasNext(int squareNumberWidth, int squareNumberHeight, int shipSize)
{
    int x = squareNumberWidth * shipSize;
    int y = squareNumberHeight * shipSize;
    int squaresize = squareSize(squareNumberWidth, squareNumberWidth, shipSize);
    for(int i = 0; i < squaresize; i++)
    {
        id = y * 10 + x;
        //cout << id;
        if (enemyField->attackable(id))
            return false;
        x++;
        y++;

    }
    return true;

}

bool DiagonalShoot::fourSquareShooted(int squareNumberWidth, int squareNumberHeight)
{
    return hasNext(squareNumberWidth, squareNumberHeight, 4);
}


int DiagonalShoot::nextCell(int squareNumberWidth, int squareNumberHeight, int shipSize)
{
    int x = squareNumberWidth * shipSize;
    int y = squareNumberHeight * shipSize;
    int direction = qrand() % 2;
    int d;
    int squaresize = squareSize(squareNumberWidth, squareNumberWidth, shipSize);
    if (direction == 1)
        d = 1;
    else
    {
        y += squaresize - 1;
        x += squaresize - 1;
        d = -1;
    }

    for(int i = 0; i < squaresize; i++)
    {
        id = y * 10 + x;
        //cout << id;
        if (enemyField->attackable(id))
            return id;
        x +=d;
        y +=d;

    }

}

int DiagonalShoot::fourSquare(int squareNumberWidth, int squareNumberHeight)
{
    return nextCell(squareNumberWidth, squareNumberHeight, 4);
}


bool DiagonalShoot::threeSquareShooted(int squareNumberWidth, int squareNumberHeight)
{
    return hasNext(squareNumberWidth, squareNumberHeight, 3);

}
int DiagonalShoot::threeSquare(int squareNumberWidth, int squareNumberHeight)
{
    return nextCell(squareNumberWidth, squareNumberHeight, 3);
}

bool DiagonalShoot::twoSquareShooted(int squareNumberWidth, int squareNumberHeight)
{
    return hasNext(squareNumberWidth, squareNumberHeight, 2);

}

int DiagonalShoot::twoSquare(int squareNumberWidth, int squareNumberHeight)
{
    return nextCell(squareNumberWidth, squareNumberHeight, 2);
}

