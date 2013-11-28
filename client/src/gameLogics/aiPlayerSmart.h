#ifndef AIPLAYERSMART_H
#define AIPLAYERSMART_H
#include "aiPlayer.h"
#include "squareShootStrategy.h"
#include "fleetInstallStrategy.h"
#include <QObject>

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

protected:
    int chooseCell();
    void decreaseFleet(int currentShip);
private:
    QPair<int, int> currentSquare;
    int aerocarrier;
    int cruiser;
    int destroyer;
    int smallship;
	QSharedPointer<SquareShootStrategy>  strategy;
    void changeStrategy();
	QSharedPointer<SquareShootStrategy>  strategy1;
	QSharedPointer<SquareShootStrategy>  strategy2;
	QSharedPointer<FleetInstallStrategy>  fleetInstaller;
};

#endif // AIPLAYERSMART_H
