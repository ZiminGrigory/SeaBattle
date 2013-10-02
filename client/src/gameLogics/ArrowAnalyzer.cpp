#include "ArrowAnalyzer.h"
#include "playerField.h"

ArrowAnalyzer::ArrowAnalyzer(PlayerField* field,
                             QSharedPointer<InterfaceField> fieldView):
	mFieldView(fieldView), mField(field), firstId(0)
{
	connect(mFieldView.data(), SIGNAL(setFirstArrows(int)), SLOT(setFirstArrows(int)));
	connect(mFieldView.data(), SIGNAL(setNextArrow(int)), SLOT(setNextArrow(int)));
	connect(mFieldView.data(), SIGNAL(placeShip(int,int)), SLOT(deleteAllArrows(int,int)));
}
bool ArrowAnalyzer::isEmptyAround(QPair<int, int> ID)
{
	for (int i = ID.first - 1; i <= ID.first + 1; i++){
		for (int j = ID.second - 1; j <= ID.second + 1; j++){
			if (checkCoord(i, j)){
                if (mField->getShip(getIdByCoordinates(QPair<int, int>(i, j))) != NULL){
					return false;
				}
			}
		}
	}
	return true;
}

void ArrowAnalyzer::setFirstArrows(int id)
{
	firstId = id;
	previousIm = ARROW_UP;
	deleteAllArrows(id, id);
	orientation.clear();
	orientation << true << true << true << true << true;
	QPair<int, int> point = coordinates(id);
    if (mField->getFleet().first() != 0 ||
            (mField->getFleet().first() != 0
             && (mField->getFleet().at(1) != 0 || mField->getFleet().at(2) != 0
                 || mField->getFleet().at(3) != 0))){
		orientation.last() = isEmptyAround(point);
		if (orientation.last()){
			mFieldView->addImage(getIdByCoordinates(point), ARROW_IN_ITSELF);
			previousIm = ARROW_IN_ITSELF;
			cellsWithArrow.append(getIdByCoordinates(point));
		}
	}

    if((mField->getFleet().at(1) != 0 || mField->getFleet().at(2) != 0
        || mField->getFleet().at(3) != 0) && orientation.last()){
		setArrow(id, ARROW_UP, -1, Orientation::UP);
		setArrow(id, ARROW_DOWN, 1, Orientation::DOWN);
		setArrow(id, ARROW_L, -1, Orientation::LEFT);
		setArrow(id, ARROW_R, + 1, Orientation::RIGHT);
	}

    if(mField->getFleet().at(1) == 0 && (mField->getFleet().at(2) != 0
                                         || mField->getFleet().at(3) != 0) && orientation.last()
		&& (orientation.at(0) || orientation.at(1) || orientation.at(2) || orientation.at(3))){
		setArrow(id, ARROW_UP, -2, Orientation::UP);
		setArrow(id, ARROW_DOWN, + 2, Orientation::DOWN);
		setArrow(id, ARROW_L, -2, Orientation::LEFT);
		setArrow(id, ARROW_R, +2, Orientation::RIGHT);
	}

    if(mField->getFleet().at(1) == 0 && mField->getFleet().at(2) == 0
            && mField->getFleet().at(3) != 0 && orientation.last()
			&& (orientation.at(0) || orientation.at(1) || orientation.at(2) || orientation.at(3) )){
		setArrow(id, ARROW_UP, -3, Orientation::UP);
		setArrow(id, ARROW_DOWN, +3, Orientation::DOWN);
		setArrow(id, ARROW_L, -3, Orientation::LEFT);
		setArrow(id, ARROW_R, +3, Orientation::RIGHT);
	}
}

void ArrowAnalyzer::setNextArrow(int id)
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

void ArrowAnalyzer::deleteAllArrows(int firstID, int secondID)
{
	Q_UNUSED(firstID);
	Q_UNUSED(secondID);
	while(cellsWithArrow.size() != 0){
		mFieldView->removeImageFromCell(cellsWithArrow.first());
		cellsWithArrow.remove(0);
	}
}


void ArrowAnalyzer::analyzeNextArrow(Orientation::Orient orient, ImageID iD, int id)
{
	if (previousIm == ARROW_IN_ITSELF){
		deleteAllArrows(id, id);
		return;
	}
	int switcher = id - firstId;
	int coefficient = 1;
	bool isLeftOrRight = true;
	//prepare param-s
	if (orient != Orientation::LEFT && orient != Orientation::RIGHT){
		isLeftOrRight = false;
	}
	if (orient != Orientation::DOWN && orient != Orientation::RIGHT){
		coefficient = -1;
	}
	if (orient == Orientation::LEFT){
		switcher *= -1;
	}else if (orient == Orientation::DOWN){
		switcher = switcher / FIELD_COL_NUM;
	} else if (orient == Orientation::UP){
		switcher = switcher / FIELD_COL_NUM * -1;
	}
	QPair<int, int> point = coordinates(id);
	deleteAllArrows(id, id);
	switch (switcher) {
	case 1:
		mFieldView->addImage(firstId, FIRT_POINT);
		cellsWithArrow.append(firstId);
        if (mField->getFleet().at(1) != 0 && isEmptyAround(point) && orientation.at(int(orient))){
			mFieldView->addImage(id, ARROW_IN_ITSELF);
			cellsWithArrow.append(id);
		}
        if (((mField->getFleet().at(2) != 0) || (mField->getFleet().at(3) != 0))
				&& isEmptyAround(point) && orientation.at(int(orient))){
            if (mField->getFleet().at(2) != 0){
				if (isLeftOrRight && orientation.at(int(orient))
						&& (point.second != 0 && point.second != 9)){
					point.second = point.second + coefficient;
				} else if (!isLeftOrRight && orientation.at(int(orient))
						   && (point.first != 0 && point.first != 9)){
					point.first = point.first + coefficient;
				}
            }else if (mField->getFleet().at(3) != 0){
				if (isLeftOrRight && orientation.at(int(orient))
						&& (point.second > 1 && point.second < 8)){
					point.second = point.second + 2 * coefficient;
				} else if (!isLeftOrRight && orientation.at(int(orient))
						   && (point.first > 1 && point.first < 8)){
					point.first = point.first + 2 * coefficient;
				}
			}
			if (isEmptyAround(point) && point != coordinates(id)
					&& checkCoord(point.first, point.second)){
				point = coordinates(id);
				if (isLeftOrRight && orientation.at(int(orient))
						&& (point.second != 0 && point.second != 9)){
					point.second = point.second + coefficient;
				} else if (!isLeftOrRight && orientation.at(int(orient))
						   && (point.first != 0 && point.first != 9)){
					point.first = point.first + coefficient;
				}
				mFieldView->addImage(getIdByCoordinates(point), iD);
				cellsWithArrow.append(getIdByCoordinates(point));
			}
		}
		break;
	case 2:
		mFieldView->addImage(firstId, FIRT_POINT);
		cellsWithArrow.append(firstId);
        if (mField->getFleet().at(2) != 0 && isEmptyAround(point) && orientation.at(int(orient))){
			mFieldView->addImage(id, ARROW_IN_ITSELF);
			cellsWithArrow.append(id);
		}
        if (mField->getFleet().at(3) != 0 && isEmptyAround(point) && orientation.at(int(orient))){
			point = coordinates(id);
			if (isLeftOrRight && orientation.at(int(orient))
					&& (point.second < FIELD_COL_NUM - 1 || point.second > 1)){
				point.second = point.second + coefficient;
			} else if (!isLeftOrRight && orientation.at(int(orient))
					   && (point.first < FIELD_ROW_NUM - 1 || point.first > 1)){
				point.first = point.first + coefficient;
			}
			if (isEmptyAround(point) && point != coordinates(id)){
				mFieldView->addImage(getIdByCoordinates(point), iD);
				cellsWithArrow.append(getIdByCoordinates(point));
			}
		}
		break;
	case 3:
		mFieldView->addImage(firstId, FIRT_POINT);
		cellsWithArrow.append(firstId);
        if (isEmptyAround(point) && mField->getFleet().at(3) != 0 && orientation.at(int(orient))){
			mFieldView->addImage(id, ARROW_IN_ITSELF);
			cellsWithArrow.append(id);
		}
		break;
	}
}


void ArrowAnalyzer::setArrow(int id, ImageID iD, int difference, Orientation::Orient orient)
{
	QPair<int, int> point = coordinates(id);
	if (orient == Orientation::UP || orient == Orientation::DOWN){
		point.first = point.first + difference;
	} else if (orient != Orientation::UP || orient != Orientation::DOWN){
		point.second = point.second + difference;
	}
	if (orientation[int(orient)]){
		orientation[int(orient)] = isEmptyAround(point);
        if (mField->getFleet().at(qAbs(difference)) != 0 && checkCoord(point.first, point.second) && orientation[int(orient)]){
			int coefficient = 1;
			point = coordinates(id);
			if (iD == ARROW_UP || iD == ARROW_L){
				coefficient *= -1;
			}
			if (iD == ARROW_R || iD == ARROW_L){
				point.second = point.second + coefficient;
			}else if (iD == ARROW_UP || iD == ARROW_DOWN){
				point.first = point.first + coefficient;
			}
			mFieldView->addImage(getIdByCoordinates(point), iD);
			previousIm = iD;
			cellsWithArrow.append(getIdByCoordinates(point));
		}
	}
}
