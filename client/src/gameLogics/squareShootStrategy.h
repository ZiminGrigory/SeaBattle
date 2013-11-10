#ifndef SQUARESHOOTSTRATEGY_H
#define SQUARESHOOTSTRATEGY_H
#include "GameField.h"
#include <QTime>

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
protected:
    QSharedPointer<GameField>  enemyField;
    int id;
    virtual int nextCell(int squareNumberWidth, int squareNumberHeight, int shipSize) = 0;
    int squareSize(int squareNumberWidth, int squareNumberHeight, int size);
    virtual bool hasNext(int squareNumberWidth, int squareNumberHeight, int shipSize) = 0;
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
