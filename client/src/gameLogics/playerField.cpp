#include "playerField.h"
using namespace Orientation;

PlayerField::PlayerField(const QSharedPointer<InterfaceField> &fieldView):
    GameField(fieldView),
    mArrowAnalyzer(QSharedPointer<ArrowAnalyzer>(
                       new ArrowAnalyzer(QSharedPointer<PlayerField>(this), this->view)))
{

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

QVector<int> PlayerField::getFleet()
{
	return fleet;
}
