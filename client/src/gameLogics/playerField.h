#pragma once
#include "gameField.h"
#include "ArrowAnalyzer.h"

class ArrowAnalyzer;

class PlayerField : public GameField
{
Q_OBJECT
public:
	PlayerField(const QSharedPointer<InterfaceField> &fieldView);
	virtual AttackStatus attack(int id);
	virtual void repaintCell(int row, int column, int partOfShip, int shipSize, bool orientation);
	QVector<int> getFleet();
private:
    ArrowAnalyzer mArrowAnalyzer;
};

