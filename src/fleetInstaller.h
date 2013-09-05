#ifndef FLEETINSTALLER_H
#define FLEETINSTALLER_H

#include <QObject>
#include <QSharedPointer>
#include <QPair>
#include <QVector>
#include <QMetaType>

#include "types.h"
#include "ship.h"
#include "playerField.h"


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
    Q_ENUMS(PlacementStatus);
    enum PlacementStatus
    {
        OK,
        UNCORRECT_COORDINATES,
        NOT_LINE,
        HAVE_NOT_SHIP,
        CELL_OCCUPIED
    };

    typedef QPair<int, int> CellPair;

    FleetInstaller(QVector<ptrShip> playerFleet, PlayerField* playerField);
signals:
    /**
      * Signal emitted after shipPlaced() slot ended work.
      * Signal contains result of last try to place ship on cells.
      */
    void placementResult(PlacementStatus res);
public slots:
    /**
      * This slot informs object about a try to place ship on cells kept in QVector.
      * It might connect to view object for human player or to other method for generate fleet for ai.
      * Slot emits signal placementResult() with status of this try to place ship.
      */
    PlacementStatus shipPlaced(CellPair cells);
    
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
      */
    ptrShip pickShip(CellPair cells, Orientation orn);

    QVector<ptrShip> fleet;
    PlayerField* field;
};

Q_DECLARE_METATYPE(FleetInstaller::PlacementStatus);



#endif // FLEETINSTALLER_H
