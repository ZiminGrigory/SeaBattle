#include "squareShootStrategy.h"

SquareShootStrategy::SquareShootStrategy(const QSharedPointer<GameField>& enmField):
    enemyField(enmField),
    id(0)
{

    shootedSquares4 = new QList<int>();
    shootedSquares3 = new QList<int>();
    shootedSquares2 = new QList<int>();
   // shootedSquares->clear();
    qsrand(QTime::currentTime().msec());
}

DiagonalShoot::DiagonalShoot(const QSharedPointer<GameField> &enmField):
    SquareShootStrategy(enmField)
{

}
DoubleDiagonalShoot::DoubleDiagonalShoot(const QSharedPointer<GameField> &enmField):
    SquareShootStrategy(enmField)
{

}

int SquareShootStrategy::makeId(int x, int y)
{
    return x*3 + y;
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
		break;
    case 2:
        squaresize = 2;

    }
    return squaresize;

}

bool DiagonalShoot::hasNext(int squareNumberWidth, int squareNumberHeight, int shipSize)
{
    int id = makeId(squareNumberWidth, squareNumberHeight);
    switch (shipSize)
    {
    case 4:
        if(shootedSquares4->contains(makeId(squareNumberWidth, squareNumberHeight)))
            return true;
        break;
    case 3:
        if (shootedSquares3->contains(makeId(squareNumberWidth, squareNumberHeight)))
            return true;
        break;
    case 2:
        if(shootedSquares2->contains(makeId(squareNumberWidth, squareNumberHeight)))
            return true;
        break;
    }
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
    switch (shipSize)
    {
    case 4:
        shootedSquares4->append(makeId(squareNumberWidth, squareNumberHeight));
        break;
    case 3:
        shootedSquares3->append(makeId(squareNumberWidth, squareNumberHeight));
        break;
    case 2:
        shootedSquares2->append(makeId(squareNumberWidth, squareNumberHeight));
        break;
    }
    return true;

}

void SquareShootStrategy::clearList()
{
    //shootedSquares->clear();

}
bool DiagonalShoot::fourSquareShooted(int squareNumberWidth, int squareNumberHeight)
{

    return hasNext(squareNumberWidth, squareNumberHeight, 4);
}


int DiagonalShoot::nextCell(int squareNumberWidth, int squareNumberHeight, int shipSize)
{
    int x = squareNumberWidth * shipSize;
    int y = squareNumberHeight * shipSize;
    int d = -1;
    int squaresize = squareSize(squareNumberWidth, squareNumberWidth, shipSize);
    y += squaresize - 1;
    x += squaresize - 1;

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

bool DoubleDiagonalShoot::hasNext(int squareNumberWidth, int squareNumberHeight, int shipSize)
{
    switch (shipSize)
    {
    case 4:
        if(shootedSquares4->contains(makeId(squareNumberWidth, squareNumberHeight)))
            return true;
        break;
    case 3:
        if (shootedSquares3->contains(makeId(squareNumberWidth, squareNumberHeight)))
            return true;
        break;
    case 2:
        if(shootedSquares2->contains(makeId(squareNumberWidth, squareNumberHeight)))
            return true;
        break;
    }
    int size = squareSize(squareNumberWidth, squareNumberHeight, shipSize);
    int x = squareNumberWidth * shipSize;
    int y = squareNumberHeight * shipSize;
    for (int i = 0; i < size/2; i++)
    {
        id = y * 10 + x;
        if (enemyField->attackable(id))
            return false;
        x++;
        y++;
    }

    x = squareNumberWidth * shipSize;
    y = squareNumberHeight * shipSize;
    if (size < 3)
    {
        if (size != 1)
        {
            x++;
            y++;
        }
        id = y * 10 + x;
        if (enemyField->attackable(id))
            return false;

    }
    else
    {
        x = squareNumberWidth * shipSize + size - 1;
        y = squareNumberHeight * shipSize + size - 2;
        id = y * 10 + x;
        if (enemyField->attackable(id))
            return false;
        x--;
        y++;
        id = y * 10 + x;
        if (enemyField->attackable(id))
            return false;
    }
    int sqr = makeId(squareNumberWidth, squareNumberHeight);
    return true;

}

int DoubleDiagonalShoot::nextCell(int squareNumberWidth, int squareNumberHeight, int shipSize)
{
    int size = squareSize(squareNumberWidth, squareNumberHeight, shipSize);
    int x = squareNumberWidth * shipSize;
    int y = squareNumberHeight * shipSize;
    for (int i = 0; i < size/2; i++)
    {
        id = y * 10 + x;
        if (enemyField->attackable(id))
            return id;
        x++;
        y++;
    }
    x = squareNumberWidth * shipSize;
    y = squareNumberHeight * shipSize;
    if (size < 3)
    {
        if (size > 1)
        {
            x++;
            y++;
        }
        id = y * 10 + x;
        if (enemyField->attackable(id))
            return id;

    }
    else
    {
        x = squareNumberWidth * shipSize + size - 1;
        y = squareNumberHeight * shipSize + size - 2;
        id = y * 10 + x;
        if (enemyField->attackable(id))
            return id;
        x--;
        y++;
        id = y * 10 + x;
        if (enemyField->attackable(id))
            return id;
    }
    int sqr = makeId(squareNumberWidth, squareNumberHeight);
    switch (shipSize)
    {
    case 4:
        shootedSquares4->append(makeId(squareNumberWidth, squareNumberHeight));
        break;
    case 3:
        shootedSquares3->append(makeId(squareNumberWidth, squareNumberHeight));
        break;
    case 2:
        shootedSquares2->append(makeId(squareNumberWidth, squareNumberHeight));
        break;
    }
    return true;

}

bool DoubleDiagonalShoot::fourSquareShooted(int squareNumberWidth, int squareNumberHeight)
{
    return hasNext(squareNumberWidth, squareNumberHeight, 4);
}
int DoubleDiagonalShoot::fourSquare(int squareNumberWidth, int squareNumberHeight)
{
    return nextCell(squareNumberWidth, squareNumberHeight, 4);
}
bool DoubleDiagonalShoot::threeSquareShooted(int squareNumberWidth, int squareNumberHeight)
{
    return hasNext(squareNumberWidth, squareNumberHeight, 3);
}
int DoubleDiagonalShoot::threeSquare(int squareNumberWidth, int squareNumberHeight)
{
    return nextCell(squareNumberWidth, squareNumberHeight, 3);
}
bool DoubleDiagonalShoot::twoSquareShooted(int squareNumberWidth, int squareNumberHeight)
{
    int shipSize = 2;
    int id = makeId(squareNumberWidth, squareNumberHeight);
    if (shootedSquares2->contains(id))
    {
        return true;
    }
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
    shootedSquares2->append(makeId(squareNumberWidth, squareNumberHeight));
    return true;
}
int DoubleDiagonalShoot::twoSquare(int squareNumberWidth, int squareNumberHeight)
{
    int shipSize = 2;
    int x = squareNumberWidth * shipSize;
    int y = squareNumberHeight * shipSize;
    int squaresize = squareSize(squareNumberWidth, squareNumberWidth, shipSize);
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
