#ifndef FLEETINSTALLER_H
#define FLEETINSTALLER_H

#include <QObject>
#include <QSharedPointer>
#include <QPair>
#include <QVector>
#include <QMetaType>

#include "types.h"
#include "ship.h"
#include "gameField.h"

class GameField;

/**
  * This class places player's fleets before battle.
  */
class FleetInstaller : public QObject
{
    Q_OBJECT
public:
    typedef QSharedPointer<Ship> ptrShip;
    /**
      * This enum contains statuses of placement of ship.
      */

    typedef QPair<int, int> CellPair;

    FleetInstaller(QVector<ptrShip> playerFleet,
                   GameField *playerField,
                   const QSharedPointer<InterfaceInfoTab>& _fleetInfoTab);

    QVector<ptrShip> getFleet() const;
    QVector< QSharedPointer<Ship> > getInstalledFleet() const;
	/**
	  * This method delete all ship on field.
	  */
	void clear();
    /**
      *
      */
    ptrShip getLastShip();
public slots:
    /**
      * This slot informs object about a try to place ship on cells kept in QVector.
      * It might connect to view object for human player or to other method for generate fleet for ai.
      * Slot emits signal placementResult() with status of this try to place ship.
      */
    PlacementStatus setShip(int firstId, int secondId);
    /**
      * The same as previous, but with different interface.
      *
      * @var id top left id of cell which on ship will placed
      * @var size size of ship
      * @var orientation true - horizontal, false - vertical
      */
    PlacementStatus setShip(int id, int size, bool orientation);
    /**
      * This slot remove the ship from field if cell with recieved id contained some ship.
      */
    void deleteShip(int id);
    /**
      * Check, was all ships in fleet installed on field.
      * Return true if it's ok and emit fleetInstalled() signal.
      */
    bool checkIsFleetReady();
private:
    enum Orientation
    {
        CURVE,
        VERTICAL,
        HORIZONTAL
    };

    /**
      * Return positioning of ship defined by pair of ids of cells.
      */
    Orientation orientation(CellPair cells);
    /**
      * Pick ship from fleet with length defined by pair of ids of cells and positioning.
      * If there isn't suited ship in fleet, it returns null pointer.
      *
      *
      *
      */
    ptrShip pickShip(int size);
	int positionOfShip(QVector<QSharedPointer<Ship> > vector, const QSharedPointer<Ship> ship);

    QVector<ptrShip> fleet;
    ptrShip lastShip;
    GameField* field;
	QSharedPointer<InterfaceInfoTab> fleetInfoTab;
	QVector<QSharedPointer<Ship> > existingFleet;
};



#endif // FLEETINSTALLER_H
