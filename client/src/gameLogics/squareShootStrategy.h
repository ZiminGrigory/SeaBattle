#ifndef SQUARESHOOTSTRATEGY_H
#define SQUARESHOOTSTRATEGY_H
#include "GameField.h"
#include <QTime>
#include <QList>

class SquareShootStrategy
{
public:
    /**
     * @brief SquareShootStrategy
     * @param enmField
     * Abstract class that tells smart AI next cell number to attack. Have methods for find different ships.
     */
    SquareShootStrategy(const QSharedPointer<GameField> &enmField);

    virtual int fourSquare(int squareNumberWidth, int squareNumberHeight) = 0;
    virtual bool fourSquareShooted(int squareNumberWidth, int squareNumberHeight) = 0;
    virtual int threeSquare(int squareNumberWidth, int squareNumberHeight) = 0;
    virtual bool threeSquareShooted(int squareNumberWidth, int squareNumberHeight) = 0;
    virtual int twoSquare(int squareNumberWidth, int squareNumberHeight) = 0;
    virtual bool twoSquareShooted(int squareNumberWidth, int squareNumberHeight) = 0;
    virtual void clearList();

protected:
    QSharedPointer<GameField>  enemyField;
    int id;
    virtual int nextCell(int squareNumberWidth, int squareNumberHeight, int shipSize) = 0;
    int squareSize(int squareNumberWidth, int squareNumberHeight, int size);
    virtual bool hasNext(int squareNumberWidth, int squareNumberHeight, int shipSize) = 0;
    QList<int> * shootedSquares4;
    QList<int> * shootedSquares3;
    QList<int> * shootedSquares2;
    int makeId(int, int);
};

class DiagonalShoot : public SquareShootStrategy

{
public:
    DiagonalShoot(const QSharedPointer<GameField> &enmField);
    virtual int fourSquare(int squareNumberWidth, int squareNumberHeight);
    virtual bool fourSquareShooted(int squareNumberWidth, int squareNumberHeight);
    virtual int threeSquare(int squareNumberWidth, int squareNumberHeight);
    virtual bool threeSquareShooted(int squareNumberWidth, int squareNumberHeight);
    virtual int twoSquare(int squareNumberWidth, int squareNumberHeight);
    virtual bool twoSquareShooted(int squareNumberWidth, int squareNumberHeight);
private:
    int nextCell(int squareNumberWidth, int squareNumberHeight,int shipSize);
    bool hasNext(int squareNumberWidth, int squareNumberHeight, int shipSize);
};

class DoubleDiagonalShoot : public SquareShootStrategy
{
public:
    DoubleDiagonalShoot(const QSharedPointer<GameField> &enmField);
    virtual int fourSquare(int squareNumberWidth, int squareNumberHeight);
    virtual bool fourSquareShooted(int squareNumberWidth, int squareNumberHeight);
    virtual int threeSquare(int squareNumberWidth, int squareNumberHeight);
    virtual bool threeSquareShooted(int squareNumberWidth, int squareNumberHeight);
    virtual int twoSquare(int squareNumberWidth, int squareNumberHeight);
    virtual bool twoSquareShooted(int squareNumberWidth, int squareNumberHeight);
private:
    int nextCell(int squareNumberWidth, int squareNumberHeight,int shipSize);
    bool hasNext(int squareNumberWidth, int squareNumberHeight, int shipSize);

};

#endif // SQUARESHOOTSTRATEGY_H
