#include "squareShootStrategy.h"

SquareShootStrategy::SquareShootStrategy(const QSharedPointer<GameField>& enmField):
    enemyField(enmField),
    id(0)
{
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

bool DiagonalShoot::fourSquareShooted(int squareNumberWidth, int squareNumberHeight)
{
    int x = squareNumberWidth * 4;
    int y = squareNumberHeight * 4;
    int squaresize = squareSize(squareNumberWidth, squareNumberWidth, 4);
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
int DiagonalShoot::fourSquare(int squareNumberWidth, int squareNumberHeight)
{
    int x = squareNumberWidth * 4;
    int y = squareNumberHeight * 4;
    int squaresize = squareSize(squareNumberWidth, squareNumberWidth, 4);
    for(int i = 0; i < squaresize; i++)
    {
        id = y * 10 + x;
        //cout << id;
        if (enemyField->attackable(id))
            return id;
        x++;
        y++;

    }

}


bool DiagonalShoot::threeSquareShooted(int squareNumberWidth, int squareNumberHeight)
{
    int x = squareNumberWidth * 3;
    int y = squareNumberHeight * 3;
    int squaresize = squareSize(squareNumberWidth, squareNumberWidth, 3);
    for (int i = 0; i < squaresize; i++)
    {
        id = y * 10 + x;
        if(enemyField->attackable(id))
            return false;
        x++;
        y++;
    }
    return true;

}
int DiagonalShoot::threeSquare(int squareNumberWidth, int squareNumberHeight)
{
    int x = squareNumberWidth * 3;
    int y = squareNumberHeight * 3;
    int squaresize = squareSize(squareNumberWidth, squareNumberWidth, 3);
    for (int i = 0; i < squaresize; i++)
    {
        id = y * 10 + x;
        if(enemyField->attackable(id))
            return id;
        x++;
        y++;
    }
}

bool DiagonalShoot::twoSquareShooted(int squareNumberWidth, int squareNumberHeight)
{
    int x = squareNumberWidth * 2;
    int y = squareNumberHeight * 2;
    int squaresize = 2;
    for (int i = 0; i < squaresize; i++)
    {
        id = y * 10 + x;
        if(enemyField->attackable(id))
            return false;
        x++;
        y++;
    }
    return true;

}

int DiagonalShoot::twoSquare(int squareNumberWidth, int squareNumberHeight)
{
    int x = squareNumberWidth * 2;
    int y = squareNumberHeight * 2;
    int squaresize = 2;
    for (int i = 0; i < squaresize; i++)
    {
        id = y * 10 + x;
        if(enemyField->attackable(id))
            return id;
        x++;
        y++;
    }
}

