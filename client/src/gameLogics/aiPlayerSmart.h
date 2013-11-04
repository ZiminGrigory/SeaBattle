#ifndef AIPLAYERSMART_H
#define AIPLAYERSMART_H
#include "aiPlayer.h"
#include "squareShootStrategy.h"



class AIPlayerSmart :  public AIPlayer
{
public:
    explicit AIPlayerSmart(const QSharedPointer<GameField>& plrField,
                      const QSharedPointer<GameField>& enmField,
                      QObject *parent = 0);
     void installFleet();

     // same then aiSimple function
public slots:
    void turn();

private slots:
  //  void delayTurn();

private:
    int chooseCell();
    QPair<int, int> currentSquare;
    int aerocarrier;
    int cruiser;
    int destroyer;
    int smallship;
    void decreaseFleet(int currentShip);
    SquareShootStrategy * strategy;

};

#endif // AIPLAYERSMART_H
