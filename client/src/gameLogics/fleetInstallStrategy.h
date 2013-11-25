#ifndef FLEETINSTALLSTRATEGY_H
#define FLEETINSTALLSTRATEGY_H
#include "gameField.h"
#include <QVector>
#include <QPair>
#include <QTime>

class FleetInstallStrategy
{
public:
    FleetInstallStrategy(const QSharedPointer<GameField>& myField);
    void installFleet();
private:
    QSharedPointer<GameField> field;
    QVector <QPair<int, int> > strategy;
    // array, ship's coordinates in different strategies
    QVector <QPair<int, int> > getStrategy();

};



#endif // FLEETINSTALLSTRATEGY_H
