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
		view->paintCell(YOU, id, MISS_CELL);
	}
	else if (status == WOUNDED)
	{
		view->paintCell(YOU, id, SHIP_DAMAGED);
	}
	else if (status == KILLED)
	{
		view->paintCell(YOU, id, SHIP_KILLED);
	}
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
