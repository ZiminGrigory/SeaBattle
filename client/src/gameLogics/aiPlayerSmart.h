#ifndef AIPLAYERSMART_H
#define AIPLAYERSMART_H
#include "aiPlayer.h"

class AIPlayerSmart :  public AIPlayer
{
public:
    explicit AIPlayerSmart(const QSharedPointer<GameField>& plrField,
                      const QSharedPointer<GameField>& enmField,
                      QObject *parent = 0);
     void installFleet(const QSharedPointer<FleetInstaller> &fleetInstaller);
     // same then aiSimple function
public slots:
    void turn();
private slots:
    void delayTurn();

};

#endif // AIPLAYERSMART_H
