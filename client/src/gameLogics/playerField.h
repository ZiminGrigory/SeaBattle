#pragma once
#include "gameField.h"

class PlayerField : public GameField
{
Q_OBJECT
public:
	PlayerField(const QSharedPointer<FieldView> &fieldView);
	virtual AttackStatus attack(int id);
	virtual void repaintCell(int row, int column, int partOfShip, int shipSize, bool orientation);
};

