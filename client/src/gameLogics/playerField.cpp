#include "playerField.h"

PlayerField::PlayerField(View* _view, QObject *parent) :
	QObject(parent),
	view(_view)
{
}

AttackStatus PlayerField::attack(int id)
{
	int x = id / FIELD_ROW_NUM;
	int y = id % FIELD_COL_NUM;
	AttackStatus status =  field[x][y].attack();

    if (status == MISS)
    {
        view->paintCell(plr, id, MISS_CELL);
    }
    else if (status == WOUNDED)
    {
        view->paintCell(plr, id, SHIP_DAMAGED);
    }
    else if (status == KILLED)
    {
        view->paintCell(plr, id, SHIP_KILLED);
    }
	return status;
}

QSharedPointer<Ship> PlayerField::getShip(int id)
{
	int x = id / FIELD_ROW_NUM;
	int y = id - x * FIELD_ROW_NUM;
	if (!checkCoord(x, y))
	{
		return QSharedPointer<Ship>();
	}
	return field[x][y].getShip();
}

void PlayerField::setShip(int id, bool orientation, QSharedPointer<Ship> ship)
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
			view->paintCell(plr, getIdByCoordinates(row, col + i), textureOfCell(i + 1, shipSize, orientation));
		}
	}
	// otherwise - vertical orientation
	else
	{
		for (int i = 0; i < shipSize; i++)
		{
			field[row + i][col].setShip(ship);
			view->paintCell(plr, getIdByCoordinates(row + i, col), textureOfCell(i + 1, shipSize, orientation));
		}
	}
}

void PlayerField::deleteShip(int id)
{
	QPair<int, int> coordinateOfShip = coordinates(id);
	int row = coordinateOfShip.first;
	int column = coordinateOfShip.second;
	QSharedPointer<Ship> ship = field[row][column].getShip();
	if (ship == NULL){
		return;
	}
	int size = ship.data()->size();
	view->changeCounter(NameOfShips(size - 1), 1);
	view->paintCell(plr, id, EMPTY);
	bool isAll = true;
	if (size != 1){
		do{
			row++;
			if (row <= 9){
				QSharedPointer<Ship> shipTmp = field[row][column].getShip();
				if (shipTmp != NULL){
					view->paintCell(plr, getIdByCoordinates(row, column), EMPTY);
					field[row][column].deleteShip();
				} else {
					isAll = false;
				}
			}
		} while (row <= 9 && isAll);
		row = coordinateOfShip.first;
		isAll = true;
		do{
			row--;
			if (row >= 0){
				QSharedPointer<Ship> shipTmp = field[row][column].getShip();
				if (shipTmp != NULL){
					view->paintCell(plr, getIdByCoordinates(row, column), EMPTY);
					field[row][column].deleteShip();
				} else {
					isAll = false;
				}
			}
		} while (row >= 0 && isAll);
		row = coordinateOfShip.first;
		isAll = true;
		do{
			column++;
			if (column <= 9){
				QSharedPointer<Ship> shipTmp = field[row][column].getShip();
				if (shipTmp != NULL){
					view->paintCell(plr, getIdByCoordinates(row, column), EMPTY);
					field[row][column].deleteShip();
				} else {
					isAll = false;
				}
			}
		}while (column <= 9 && isAll);
		column = coordinateOfShip.second;
		isAll = true;
		do{
			column--;
			if (column <= 9){
				QSharedPointer<Ship> shipTmp = field[row][column].getShip();
				if (shipTmp != NULL){
					view->paintCell(plr, getIdByCoordinates(row, column), EMPTY);
					field[row][column].deleteShip();
				} else {
					isAll = false;
				}
			}
		} while (column >= 0 && isAll);
	}
	field[coordinateOfShip.first][coordinateOfShip.second].deleteShip();
}
<<<<<<< HEAD:client/src/gameLogics/playerField.cpp
=======

void PlayerField::setPlr(Players _plr)
{
	plr = _plr;
}

Textures PlayerField::textureOfCell(int i, int shipSize, bool orientation)
{
	switch (shipSize) {
	case 1:
		return SHIP_SINGLE;
		break;
	case 2:{
		if (orientation) { //horizontally
			if (i == 1) {
				return SHIP_BOW_HORIZONTAL;
			}else {
				return SHIP_POOP_HORIZONTAL;
			}
		} else {
			if (i == 1) {
				return SHIP_BOW_VERTICAL;
			}else {
				return SHIP_POOP_VERTICAL;
			}
		}
	}
	break;
	case 3:{
		if (orientation) { //horizontally
			switch (i) {
			case 1:
				return SHIP_BOW_HORIZONTAL;
				break;
			case 2:
				return SHIP_DECK_HORIZONTAL;
				break;
			case 3:
				return SHIP_POOP_HORIZONTAL;
				break;
			}
		} else {
			switch (i) {
			case 1:
				return SHIP_BOW_VERTICAL;
				break;
			case 2:
				return SHIP_DECK_VERTICAL;
				break;
			case 3:
				return SHIP_POOP_VERTICAL;
				break;
			}
		}
	}
	break;
	case 4:{
		if (orientation) { //horizontally
			switch (i) {
			case 1:
				return SHIP_BOW_HORIZONTAL;
				break;
			case 2:
				return SHIP_DECK_HORIZONTAL;
				break;
			case 3:
				return SHIP_DECK_HORIZONTAL;
				break;
			case 4:
				return SHIP_POOP_HORIZONTAL;
				break;
			}
		} else {
			switch (i) {
			case 1:
				return SHIP_BOW_VERTICAL;
				break;
			case 2:
				return SHIP_DECK_VERTICAL;
				break;
			case 3:
				return SHIP_DECK_VERTICAL;
				break;
			case 4:
				return SHIP_POOP_VERTICAL;
				break;
			}
		}
	}
	break;
	}
}
>>>>>>> 2c64a389178deec969a85a3157cedf0359422e32:src/playerField.cpp
