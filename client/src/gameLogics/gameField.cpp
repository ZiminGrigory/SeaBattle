#include "gameField.h"

GameField::GameField(const QSharedPointer<FieldView> &fieldView):
    view(fieldView)
{
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
            view->repaint(getIdByCoordinates(row, col + i), textureOfCell(i + 1, shipSize, orientation));
        }
    }
    // otherwise - vertical orientation
    else
    {
        for (int i = 0; i < shipSize; i++)
        {
            field[row + i][col].setShip(ship);
			ship.data()->appedIdOfPart(getIdByCoordinates(row + i, col));
            view->repaint(getIdByCoordinates(row + i, col), textureOfCell(i + 1, shipSize, orientation));
        }
    }
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

void GameField::removeShip(int id)
{
	QPair<int, int> coordinateOfShip = coordinates(id);
	QSharedPointer<Ship> ship = field[coordinateOfShip.first][coordinateOfShip.second].getShip();
	int size = ship->size();
	view->repaint(id, EMPTY);
	if (size != 1){
		QVector<int> vectorOfId = ship->getCoordinate();
		for(int i = 1; i <= size; i++){
			QPair<int, int> coordinateOfShip = coordinates(vectorOfId.at(i - 1));
			field[coordinateOfShip.first][coordinateOfShip.second].removeShip();
			view->repaint(vectorOfId.at(i - 1), EMPTY);
		}
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
    }
    else if (res == WOUNDED)
    {
        view->repaint(getIdByCoordinates(x, y), SHIP_DAMAGED);
    }
    else if (res == KILLED)
	{
		QSharedPointer<Ship> ship = field[coordinates(id).first][coordinates(id).second].getShip();
		QVector<int> coordinates = ship->getCoordinate();
		int size = coordinates.size();
		int idFirst = coordinates.at(0);
		int idSecond = coordinates.at(size - 1);
		if ((idSecond - idFirst) >= 10){
			for (int i = idFirst % FIELD_COL_NUM - 1; i <= idFirst % FIELD_COL_NUM + 1; i++){
				for (int j = idFirst / FIELD_ROW_NUM - 1; j <= idSecond / FIELD_ROW_NUM + 1; j++){
					markKilled(j, i);
				}
			}
		} else{
			for (int i = idFirst % FIELD_COL_NUM - 1; i <= idSecond % FIELD_COL_NUM + 1; i++){
				for (int j = idFirst / FIELD_ROW_NUM - 1; j <= idFirst / FIELD_ROW_NUM + 1; j++){
					markKilled(j, i);
				}
			}
		}
    }

    return res;
}


void GameField::markKilled(int i, int j)
{
	if (checkCoord(i, j)){
		if (field[i][j].getAttackStatus() == KILLED || field[i][j].getAttackStatus() == WOUNDED){
			view->repaint(getIdByCoordinates(i, j), SHIP_KILLED);
		}
		else if(field[i][j].getAttackStatus() == MISS || field[i][j].getAttackStatus() == NOT_ATTACKED){
			view->repaint(getIdByCoordinates(i, j), MISS_CELL);
			if (field[i][j].getAttackStatus() == NOT_ATTACKED){
				field[i][j].attack();
			}
		}
	}
}

bool GameField::attackable(int id)
{
    int i = id / FIELD_ROW_NUM;
    int j = id % FIELD_COL_NUM;
    if (!checkCoord(i, j) || !field[i][j].attackable())
    {
        return false;
    }
    else
    {
        return true;
    }
}

Textures GameField::textureOfCell(int i, int shipSize, bool orientation)
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

