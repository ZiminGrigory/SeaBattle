#pragma once
#include "gameField.h"
#include "ArrowAnalyzer.h"

class ArrowAnalyzer;

class PlayerField : public GameField
{
Q_OBJECT
public:
    PlayerField(const QSharedPointer<InterfaceField> &fieldView, const QSharedPointer<InterfaceInfoTab>& infoTabView);
	virtual AttackStatus attack(int id);
	virtual void repaintCell(int row, int column, int partOfShip, int shipSize, bool orientation);

    /**
     * Returns num of ships of each type
     * at 0 - count of BOAT_SCOUT at 3 - count of AEROCARRIER
     */
    QVector<int> getShipTypesNum();
private:
    ArrowAnalyzer mArrowAnalyzer;
};

