#include "fleetInstaller.h"

FleetInstaller::FleetInstaller(QVector<ptrShip> playerFleet,
							   const QSharedPointer<GameField> &playerField,
							   const QSharedPointer<InterfaceInfoTab> &_fleetInfoTab):
    fleet(playerFleet),
	field(playerField),
    fleetInfoTab(_fleetInfoTab)
{
    qRegisterMetaType<PlacementStatus>("PlacementStatus");

    if (fleetInfoTab != NULL)
    {
        connect(fleetInfoTab.data(), SIGNAL(readyToFight()), this, SLOT(checkIsFleetReady()));
    }
}

QVector<FleetInstaller::ptrShip> FleetInstaller::getFleet() const
{
	return fleet;
}

void FleetInstaller::clear()
{
	if (existingFleet.size() != 0){
		while(existingFleet.size() != 0){
			deleteShip(existingFleet.first()->getCoordinate().first());
		}
	}
}

FleetInstaller::Orientation FleetInstaller::orientation(CellPair cells)
{
    QPair<int, int> point1 = coordinates(cells.first);
    QPair<int, int> point2 = coordinates(cells.second);

    if (point1.first == point2.first)
    {
        return HORIZONTAL;
    }
    else if (point1.second == point2.second)
    {
        return VERTICAL;
    }
    else
    {
        return CURVE;
    }
}

FleetInstaller::ptrShip FleetInstaller::pickShip(int size)
{
    for (QVector<ptrShip>::iterator itr = fleet.begin(); itr < fleet.end(); itr++)
    {
        if ((**itr).health() == size)
        {
            ptrShip ship = *itr;
            fleet.erase(itr);
            return ship;
        }
    }
	return QSharedPointer<Ship>();
}

int FleetInstaller::positionOfShip(QVector<QSharedPointer<Ship> > vector, const QSharedPointer<Ship> ship)
{
	for (int i = 0; i < vector.size(); i++){
		if (vector.at(i) == ship){
			return i;
		}
	}
	return vector.size();
}

FleetInstaller::PlacementStatus FleetInstaller::shipPlaced(int firstId, int secondId)
{
    // we suppose, that firstId left and up than secondId,
    // but it may be otherwise, so we swap ids.
    if (firstId > secondId)
    {
        int tmp = firstId;
        firstId = secondId;
        secondId = tmp;
    }

	QPair<int, int> point1 = coordinates(firstId);
	QPair<int, int> point2 = coordinates(secondId);
    if (!checkCoord(point1.first, point1.second) || !(checkCoord(point2.first, point2.second)))
    {
        emit placementResult(UNCORRECT_COORDINATES);
        return UNCORRECT_COORDINATES;
    }

	QPair<int, int> cells(firstId, secondId);
    Orientation orn = orientation(cells);
    if (orn == CURVE)
    {
        emit placementResult(NOT_LINE);
        return NOT_LINE;
    }
    int size = 0;
    if (orn == VERTICAL)
    {
        size = qAbs(point1.first - point2.first) + 1;
    }
    else if (orn == HORIZONTAL)
    {
        size = qAbs(point1.second - point2.second) + 1;
    }

    bool _orn = true;
    if (orn == VERTICAL)
    {
        _orn = false;
    }

    return shipPlaced(firstId, size, _orn);
}

FleetInstaller::PlacementStatus FleetInstaller::shipPlaced(int id, int size, bool orientation)
{
    ptrShip ship = pickShip(size);
    if (!ship)
    {
        emit placementResult(HAVE_NOT_SHIP);
        return HAVE_NOT_SHIP;
    }

    QPair<int, int> point1 = coordinates(id);
    QPair<int, int> point2 = coordinates(id);
    if (orientation)
    {
        point2.second += size - 1;
    }
    else
    {
        point2.first += size - 1;
    }
    // check surrounding cells is there ships
    int startRow = point1.first - 1;
    int startCol = point1.second - 1;

    if (orientation)
    {
        int endCol = point2.second + 1;

        // check surrounding cells
        for (int i = startCol; i <= endCol; i++)
        {
            for (int j = startRow; j < startRow + 3; j++)
            {
                if (field->getShip(j * FIELD_ROW_NUM + i))
                {
                    fleet.append(ship);
                    emit placementResult(CELL_OCCUPIED);
                    return CELL_OCCUPIED;
                }
            }
        }
    }
    else
    {
        int endRow = point2.first + 1;

        // check surrounding cells
        for (int i = startRow; i <= endRow; i++)
        {
            for (int j = startCol; j < startCol + 3; j++)
            {
                if (field->getShip(i * FIELD_ROW_NUM + j))
                {
                    fleet.append(ship);
                    emit placementResult(CELL_OCCUPIED);
                    return CELL_OCCUPIED;
                }
            }
        }
    }

    NameOfShips shipType;

    switch (size) {
    case 1:
        shipType = BOAT_SCOUT;
        break;
    case 2:
        shipType = DESTROYER;
        break;
    case 3:
        shipType = CRUISER;
        break;
    case 4:
        shipType = AEROCARRIER;
        break;
    }
    if (fleetInfoTab != NULL)
    {
        fleetInfoTab->changeCounter(shipType, -1);
    }
    field->setShip(point1.first * FIELD_ROW_NUM + point1.second, orientation, ship);
    existingFleet.append(ship);
    emit placementResult(OK);
    return OK;
}

void FleetInstaller::deleteShip(int id)
{
    if (field->getShip(id) != NULL)
    {
        NameOfShips shipType = NameOfShips(field->getShip(id)->size() - 1);
        fleetInfoTab->changeCounter(shipType, 1);
        fleet.append(field->getShip(id));
		if (existingFleet.size() != 0){
			existingFleet.remove(positionOfShip(existingFleet, field->getShip(id)));
		}
        field->removeShip(id);
    }

}

bool FleetInstaller::checkIsFleetReady()
{
    if (fleet.size() == 0)
    {
        emit fleetInstalled(existingFleet);
        return true;
    }
    return false;
}
