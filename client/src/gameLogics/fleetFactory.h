#ifndef FLEETFACTORY_H
#define FLEETFACTORY_H

#include <QVector>
#include <QSharedPointer>

#include "ship.h"
#include "cellShip.h"

/**
  * FleetFactory create a new fleet (exactly, QVector of shared pointers to Ship) for a player.
  */
class FleetFactory
{
public:
    typedef QSharedPointer<Ship> ptrShip;
    inline static QVector<ptrShip> createFleet();
};

inline QVector<FleetFactory::ptrShip> FleetFactory::createFleet()
{
    // create a standart set of ships
    QVector<ptrShip> fleet(0);
    // add 4 one-cell ships
    fleet.append(ptrShip(new CellShip<1>()));
    fleet.append(ptrShip(new CellShip<1>()));
    fleet.append(ptrShip(new CellShip<1>()));
    fleet.append(ptrShip(new CellShip<1>()));
    // add 3 two-cell ships
    fleet.append(ptrShip(new CellShip<2>()));
    fleet.append(ptrShip(new CellShip<2>()));
    fleet.append(ptrShip(new CellShip<2>()));
    // add 2 three-cell ships
    fleet.append(ptrShip(new CellShip<3>()));
    fleet.append(ptrShip(new CellShip<3>()));
    // add 1 four-cell ship
    fleet.append(ptrShip(new CellShip<4>()));

    return fleet;
}

#endif // FLEETFACTORY_H
