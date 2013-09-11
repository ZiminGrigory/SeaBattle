#pragma once
#include "gameField.h"

class PlayerField : public GameField
{
Q_OBJECT
public:
	PlayerField(const QSharedPointer<FieldView> &fieldView);
	virtual AttackStatus attack(int id);
};

