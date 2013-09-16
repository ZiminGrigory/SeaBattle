#pragma once
#include "gameField.h"

class PlayerField : public GameField
{
Q_OBJECT
public:
	PlayerField(const QSharedPointer<FieldView> &fieldView);
	virtual AttackStatus attack(int id);
	virtual void repaintCell(int row, int column, int partOfShip, int shipSize, bool orientation);

private:
	int firstId;
	int previousId;
	bool isEmptyAround(QPair<int, int> ID);
	QVector<bool> orientation; // can it go to UP RIGHT LEFT DOWN TO_ITSELF
	QVector<int> cellsWithArrow;

private slots:
	void setFirstArrows(int id);
	void setNextArrow(int id);
	void deleteAllArrows(int firstID, int secondID);
};

