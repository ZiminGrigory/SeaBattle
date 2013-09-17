#include "playerField.h"

PlayerField::PlayerField(const QSharedPointer<FieldView> &fieldView):
	GameField(fieldView), firstId(0)
{
	connect(fieldView.data(), SIGNAL(setFirstArrows(int)), SLOT(setFirstArrows(int)));
	connect(fieldView.data(), SIGNAL(setNextArrow(int)), SLOT(setNextArrow(int)));
	connect(fieldView.data(), SIGNAL(placeShip(int,int)), SLOT(deleteAllArrows(int,int)));
}

AttackStatus PlayerField::attack(int id)
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
		QSharedPointer<Ship> ship = field[x][y].getShip();
		QVector<int> coordinates = ship->getCoordinate();
		int size = coordinates.size();
		bool orientation = false;
		if ((coordinates.last() - coordinates.first()) < FIELD_COL_NUM){
			orientation = true;
		}
		view->repaint(id, textureAnalyzer->shipDamagedTexture(position(coordinates, id), size, orientation));
		view->showAttackStatus(WOUNDED);
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
				}
			}
		} else{
			for (int i = idFirst % FIELD_COL_NUM - 1; i <= idSecond % FIELD_COL_NUM + 1; i++){
				for (int j = idFirst / FIELD_ROW_NUM - 1; j <= idFirst / FIELD_ROW_NUM + 1; j++){
					markKilled(j, i);
				}
			}
		}
	view->showAttackStatus(KILLED);
	}
	return res;
}

void PlayerField::repaintCell(int row, int column, int partOfShip, int shipSize, bool orientation)
{
	view->repaint(getIdByCoordinates(row, column), textureAnalyzer->shipTexture(partOfShip, shipSize, orientation));
}

bool PlayerField::isEmptyAround(QPair<int, int> ID)
{
	for (int i = ID.first - 1; i <= ID.first + 1; i++){
		for (int j = ID.second - 1; j <= ID.second + 1; j++){
			if (checkCoord(i, j)){
				if (field[i][j].getShip() != NULL){
					return false;
				}
			}
		}
	}
	return true;
}

// to do reduce copy-past
void PlayerField::setFirstArrows(int id)
{
	firstId = id;
	previousIm = ARROW_UP;
	cellsWithArrow.clear();
	orientation.clear();
	orientation << true << true << true << true << true;
	QPair<int, int> point = coordinates(id);
	if (fleet.first() != 0 ||
			(fleet.first() != 0 && (fleet.at(1) != 0 || fleet.at(2) != 0 || fleet.at(3) != 0))){
		orientation.last() = isEmptyAround(point);
		if (orientation.last()){
			view->addImage(id, ARROW_IN_ITSELF);
			previousIm = ARROW_IN_ITSELF;
			cellsWithArrow.append(id);
		}
	}

	if((fleet.at(1) != 0 || fleet.at(2) != 0 || fleet.at(3) != 0) && orientation.last()){
		point.first = point.first - 1;
		orientation[int(Orientation::UP)] = isEmptyAround(point);
		if (fleet.at(1) != 0 && checkCoord(point.first, point.second) && orientation[int(Orientation::UP)]){
			view->addImage(getIdByCoordinates(point), ARROW_UP);
			cellsWithArrow.append(getIdByCoordinates(point));
			previousIm = ARROW_UP;
		}

		point.first = point.first + 2;
		orientation[int(Orientation::DOWN)] = isEmptyAround(point);
		if (fleet.at(1) != 0 && checkCoord(point.first, point.second) && orientation[int(Orientation::DOWN)]){
			view->addImage(getIdByCoordinates(point), ARROW_DOWN);
			previousIm = ARROW_DOWN;
			cellsWithArrow.append(getIdByCoordinates(point));
		}

		point = coordinates(id);
		point.second = point.second - 1;
		orientation[int(Orientation::LEFT)] = isEmptyAround(point);
		if (fleet.at(1) != 0 && checkCoord(point.first, point.second) && orientation[int(Orientation::LEFT)]){
			view->addImage(getIdByCoordinates(point), ARROW_L);
			previousIm = ARROW_L;
			cellsWithArrow.append(getIdByCoordinates(point));
		}

		point.second = point.second + 2;
		orientation[int(Orientation::RIGHT)] = isEmptyAround(point);
		if (fleet.at(1) != 0 && checkCoord(point.first, point.second) && orientation[int(Orientation::RIGHT)]){
			view->addImage(getIdByCoordinates(point), ARROW_R);
			previousIm = ARROW_R;
			cellsWithArrow.append(getIdByCoordinates(point));
		}
	}

	if(fleet.at(1) == 0 && (fleet.at(2) != 0 || fleet.at(3) != 0) && orientation.last()
			&& (orientation.at(0) || orientation.at(1) || orientation.at(2) || orientation.at(3))){
		point = coordinates(id);
		point.first = point.first - 2;
		if (orientation[int(Orientation::UP)]){
			orientation[int(Orientation::UP)] = isEmptyAround(point);
			if (fleet.at(2) != 0 && checkCoord(point.first, point.second) && orientation[int(Orientation::UP)]){
				point = coordinates(id);
				point.first = point.first - 1;
				view->addImage(getIdByCoordinates(point), ARROW_UP);
				previousIm = ARROW_UP;
				cellsWithArrow.append(getIdByCoordinates(point));
			}
		}

		point.first = point.first + 2;
		if (orientation[int(Orientation::DOWN)]){
		orientation[int(Orientation::DOWN)] = isEmptyAround(point);
			if (fleet.at(2) != 0 && checkCoord(point.first, point.second) && orientation[int(Orientation::DOWN)]){
				point = coordinates(id);
				point.first = point.first + 1;
				view->addImage(getIdByCoordinates(point), ARROW_DOWN);
				previousIm = ARROW_DOWN;
				cellsWithArrow.append(getIdByCoordinates(point));
			}
		}

		point = coordinates(id);
		point.second = point.second - 2;
		if (orientation[int(Orientation::LEFT)]){
			orientation[int(Orientation::LEFT)] = isEmptyAround(point);
			if (fleet.at(2) != 0 && checkCoord(point.first, point.second) && orientation[int(Orientation::LEFT)]){
				point = coordinates(id);
				point.second = point.second - 1;
				view->addImage(getIdByCoordinates(point), ARROW_L);
				previousIm = ARROW_L;
				cellsWithArrow.append(getIdByCoordinates(point));
			}
		}

		point = coordinates(id);
		point.second = point.second + 2;
		if (orientation[int(Orientation::RIGHT)]){
		orientation[int(Orientation::RIGHT)] = isEmptyAround(point);
			if (fleet.at(2) != 0 && checkCoord(point.first, point.second) && orientation[int(Orientation::RIGHT)]){
				point = coordinates(id);
				point.second = point.second + 1;
				view->addImage(getIdByCoordinates(point), ARROW_R);
				previousIm = ARROW_R;
				cellsWithArrow.append(getIdByCoordinates(point));
			}
		}
	}
	if(fleet.at(1) == 0 && fleet.at(2) == 0 && fleet.at(3) != 0 && orientation.last()
			&& (orientation.at(0) || orientation.at(1) || orientation.at(2) || orientation.at(3) )){
		point = coordinates(id);
		point.first = point.first - 3;
		if (orientation[int(Orientation::UP)]){
			orientation[int(Orientation::UP)] = isEmptyAround(point);
			if (fleet.at(3) != 0 && checkCoord(point.first, point.second) && orientation[int(Orientation::UP)]){
				point = coordinates(id);
				point.first = point.first - 1;
				view->addImage(getIdByCoordinates(point), ARROW_UP);
				previousIm = ARROW_UP;
				cellsWithArrow.append(getIdByCoordinates(point));
			}
		}

		point = coordinates(id);
		point.first = point.first + 3;
		if (orientation[int(Orientation::DOWN)]){
			orientation[int(Orientation::DOWN)] = isEmptyAround(point);
			if (fleet.at(3) != 0 && checkCoord(point.first, point.second) && orientation[int(Orientation::DOWN)]){
				point = coordinates(id);
				point.first = point.first + 1;
				view->addImage(getIdByCoordinates(point), ARROW_DOWN);
				previousIm = ARROW_DOWN;
				cellsWithArrow.append(getIdByCoordinates(point));
			}
		}

		point = coordinates(id);
		point.second = point.second - 3;
		if (orientation[int(Orientation::LEFT)]){
			orientation[int(Orientation::LEFT)] = isEmptyAround(point);
			if (fleet.at(3) != 0 && checkCoord(point.first, point.second) && orientation[int(Orientation::LEFT)]){
				point = coordinates(id);
				point.second = point.second - 1;
				view->addImage(getIdByCoordinates(point), ARROW_L);
				previousIm = ARROW_L;
				cellsWithArrow.append(getIdByCoordinates(point));
			}
		}

		point = coordinates(id);
		point.second = point.second + 3;
		if (orientation[int(Orientation::RIGHT)]){
			orientation[int(Orientation::RIGHT)] = isEmptyAround(point);
			if (fleet.at(3) != 0 && checkCoord(point.first, point.second) && orientation[int(Orientation::RIGHT)]){
				point = coordinates(id);
				point.second = point.second + 1;
				view->addImage(getIdByCoordinates(point), ARROW_R);
				previousIm = ARROW_R;
				cellsWithArrow.append(getIdByCoordinates(point));
			}
		}
	}

}

void PlayerField::setNextArrow(int id)
{
	if (id == firstId){
		return;
	}
	if (id - firstId < 10 && id - firstId > 0){//right
		analyzeNextArrow(Orientation::RIGHT, ARROW_R, id);
	}else if (firstId - id < 10 && firstId - id > 0){//left
		analyzeNextArrow(Orientation::LEFT, ARROW_L, id);
	}else if (firstId - id >= 10){//UP
		analyzeNextArrow(Orientation::UP, ARROW_UP, id);
	}else if (id - firstId >= 10){//DOWN
		analyzeNextArrow(Orientation::DOWN, ARROW_DOWN, id);
	}
}

void PlayerField::deleteAllArrows(int firstID, int secondID)
{
	Q_UNUSED(firstID);
	Q_UNUSED(secondID);
while(cellsWithArrow.size() != 0){
		view->removeImageFromCell(cellsWithArrow.first());
		cellsWithArrow.remove(0);
	}
}

void PlayerField::analyzeNextArrow(Orientation::Orient orientation, ImageID iD, int id)
{
	if (previousIm == ARROW_IN_ITSELF){
		deleteAllArrows(id, id);
		return;
	}
	int switcher = id - firstId;
	int coefficient = 1;
	bool isLeftOrRight = true;
	//prepare param-s
	if (orientation != Orientation::LEFT && orientation != Orientation::RIGHT){
		isLeftOrRight = false;
	}
	if (orientation != Orientation::DOWN && orientation != Orientation::RIGHT){
		coefficient = -1;
	}
	if (orientation == Orientation::LEFT){
		switcher *= -1;
	}else if (orientation == Orientation::DOWN){
		switcher = switcher / FIELD_COL_NUM;
	} else if (orientation == Orientation::UP){
		switcher = switcher / FIELD_COL_NUM * -1;
	}
	QPair<int, int> point = coordinates(id);
	deleteAllArrows(id, id);
	switch (switcher) {
	case 1:
		if (fleet.at(1) != 0){
			view->addImage(id, ARROW_IN_ITSELF);
			cellsWithArrow.append(id);
			if ((fleet.at(2) != 0) || (fleet.at(3) != 0)){
				if (fleet.at(2) != 0){
					if (isLeftOrRight){
						point.second = point.second + coefficient;
					} else {
						point.first = point.first + coefficient;
					}
				}else if (fleet.at(3) != 0){
					if (isLeftOrRight){
						point.second = point.second + 2 * coefficient;
					} else {
						point.first = point.first + 2 * coefficient;
					}
				}
				if (isEmptyAround(point)){
					point = coordinates(id);
					if (isLeftOrRight){
						point.second = point.second + coefficient;
					} else {
						point.first = point.first + coefficient;
					}
					view->addImage(getIdByCoordinates(point), iD);
					cellsWithArrow.append(getIdByCoordinates(point));
				}
			}
		}
		break;
	case 2:
		if (fleet.at(2) != 0){
			view->addImage(id, ARROW_IN_ITSELF);
			cellsWithArrow.append(id);
			point = coordinates(id);
			if ((fleet.at(3) != 0)){
				if (isLeftOrRight){
					point.second = point.second + coefficient;
				} else {
					point.first = point.first + coefficient;
				}
				if (isEmptyAround(point)){
					view->addImage(getIdByCoordinates(point), iD);
					cellsWithArrow.append(getIdByCoordinates(point));
				}
			}
		}
		break;
	case 3:
		if (fleet.at(3) != 0){
			view->addImage(id, ARROW_IN_ITSELF);
			cellsWithArrow.append(id);
		}
		break;
	}
}
