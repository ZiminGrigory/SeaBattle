#include "gameField.h"
#include "fleetInstaller.h"

GameField::GameField(const QSharedPointer<InterfaceField>& fieldView,
                     const QSharedPointer<InterfaceInfoTab>& infoTabView):
    view(fieldView),
    textureAnalyzer(new TextureAnalyzer()),
    fleet(FleetFactory::createFleet()),
    flInst(new FleetInstaller(fleet, this, infoTabView))
{
    //fleet << 4 << 3 << 2 << 1; //conut of ship
	connect(this, SIGNAL(shipPlacementResult(PlacementStatus,int,int)),
			view.data(), SLOT(showPlacementStatus(PlacementStatus,int,int)));
}

QSharedPointer<Ship> GameField::getShip(int id)
{
    int x = id / FIELD_ROW_NUM;
    int y = id - x * FIELD_ROW_NUM;
    if (!checkCoord(x, y))
    {
        return QSharedPointer<Ship>();
    }
    return field[x][y].getShip();
}

QVector<QSharedPointer<Ship> > GameField::getFleet()
{
    return fleet;
}

QVector<QSharedPointer<Ship> > GameField::getInstalledFleet()
{
    return flInst->getInstalledFleet();
}

PlacementStatus GameField::setShip(int firstId, int secondId)
{
    PlacementStatus status = flInst->setShip(firstId, secondId);
    setShipHook(status);
	emit shipPlacementResult(status, firstId, secondId);
    return status;
}

PlacementStatus GameField::setShip(int id, int size, bool orientation)
{
    PlacementStatus status = flInst->setShip(id, size, orientation);
    setShipHook(status);
	emit shipPlacementResult(status, id, size, orientation);
    return status;
}

void GameField::deleteShip(int id)
{
    if (flInst->deleteShip(id))
    {
        QPair<int, int> coordinateOfShip = coordinates(id);
        QSharedPointer<Ship> ship = field[coordinateOfShip.first][coordinateOfShip.second].getShip();
        int size = ship->size();
        QVector<int> vectorOfId = ship->getCoordinate();
        ship->clearCoordinate();
        for(int i = 1; i <= size; i++) {
            QPair<int, int> coordinateOfShip = coordinates(vectorOfId.at(i - 1));
            field[coordinateOfShip.first][coordinateOfShip.second].removeShip();
            view->repaint(vectorOfId.at(i - 1), EMPTY);
        }
        //fleet[size - 1] = fleet.at(size - 1) + 1;
    }
}

void GameField::removeInstalledFleet()
{
    flInst->clear();
}

void GameField::checkIsFleetReady()
{
    if (flInst->checkIsFleetReady())
    {
        emit fleetInstalled();
    }
}

AttackStatus GameField::attack(int id)
{
    int x = id / FIELD_ROW_NUM;
    int y = id - x * FIELD_ROW_NUM;

    AttackStatus res = field[x][y].attack();

    if (res == MISS)
    {
        view->repaint(getIdByCoordinates(x, y), MISS_CELL);
		view->showAttackStatus(MISS);
    }
    else if (res == WOUNDED)
    {
		handleResWOUNDED(x, y);
    }
    else if (res == KILLED)
	{
		QSharedPointer<Ship> ship = field[coordinates(id).first][coordinates(id).second].getShip();
		QVector<int> coordinates = ship->getCoordinate();
		int idFirst = coordinates.first();
		int idSecond = coordinates.last();
		if ((idSecond - idFirst) >= 10){
			for (int i = idFirst % FIELD_COL_NUM - 1; i <= idFirst % FIELD_COL_NUM + 1; i++){
				for (int j = idFirst / FIELD_ROW_NUM - 1; j <= idSecond / FIELD_ROW_NUM + 1; j++){
					markKilled(j, i);
					handleResKILLED(j, i);
				}
			}
		} else{
			for (int i = idFirst % FIELD_COL_NUM - 1; i <= idSecond % FIELD_COL_NUM + 1; i++){
				for (int j = idFirst / FIELD_ROW_NUM - 1; j <= idFirst / FIELD_ROW_NUM + 1; j++){
					markKilled(j, i);
					handleResKILLED(j, i);
				}
			}
		}
		view->showAttackStatus(KILLED);
	}
	return res;
}


void GameField::markKilled(int i, int j)
{
	if (checkCoord(i, j)){
		if (field[i][j].getAttackStatus() == KILLED || field[i][j].getAttackStatus() == WOUNDED){
			QSharedPointer<Ship> ship = field[i][j].getShip();
			QVector<int> coordinates = ship->getCoordinate();
			int size = coordinates.size();
			bool orientation = false;
			if ((coordinates.last() - coordinates.first()) < FIELD_COL_NUM){
				orientation = true;
			}
			view->repaint(getIdByCoordinates(i, j)
						  , textureAnalyzer->shipDamagedTexture(position(coordinates, getIdByCoordinates(i, j))
																, size, orientation));
		}
		else if(field[i][j].getAttackStatus() == MISS || field[i][j].getAttackStatus() == NOT_ATTACKED){
			view->repaint(getIdByCoordinates(i, j), WRECK);
			if (field[i][j].getAttackStatus() == NOT_ATTACKED){
				field[i][j].attack();
			}
		}
    }
}

void GameField::setShipHook(PlacementStatus status)
{
    Q_UNUSED(status);
}

void GameField::setShip(int id, bool orientation, QSharedPointer<Ship> ship)
{
    QPair<int, int> coord = coordinates(id);
    int row = coord.first;
    int col = coord.second;
    int shipSize = ship->size();
    // if orientation == true, then ship has horizontal orientation
    if (orientation)
    {
        for (int i = 0; i < shipSize; i++)
        {
            field[row][col + i].setShip(ship);
            ship.data()->appedIdOfPart(getIdByCoordinates(row, col + i));
            repaintCell(row, col + i, i + 1, shipSize, orientation);
        }
    }
    // otherwise - vertical orientation
    else
    {
        for (int i = 0; i < shipSize; i++)
        {
            field[row + i][col].setShip(ship);
            ship.data()->appedIdOfPart(getIdByCoordinates(row + i, col));
            repaintCell(row + i, col, i + 1, shipSize, orientation);
        }
    }
    //fleet[shipSize - 1] = fleet.at(shipSize - 1) - 1;
}

void GameField::repaintCell(int row, int column, int partOfShip, int shipSize, bool orientation)
{
	Q_UNUSED(row);
	Q_UNUSED(column);
	Q_UNUSED(partOfShip);
	Q_UNUSED(shipSize);
	Q_UNUSED(orientation);
}

void GameField::handleResWOUNDED(int x, int y)
{
	view->repaint(getIdByCoordinates(x, y), SHIP_DAMAGED);
	view->showAttackStatus(WOUNDED);
}

void GameField::handleResKILLED(int j, int i)
{
	if(checkCoord(j,i) && !field[j][i].attackable()){
		field[j][i].attack();
	}
}

int GameField::position(QVector<int> vector, int id)
{
	int size = vector.size();
	for (int i = 0; i < size; i++){
		if (vector.at(i) == id){
			return i + 1;
		}
	}
	return FIELD_COL_NUM;
}

bool GameField::attackable(int id)
{
    int i = id / FIELD_ROW_NUM;
    int j = id % FIELD_COL_NUM;
    if (!checkCoord(i, j) || !field[i][j].attackable()){
        return false;
    }
    else{
        return true;
    }
}


