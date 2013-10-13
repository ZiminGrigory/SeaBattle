#ifndef GAMEFIELD_H
#define GAMEFIELD_H

#include <QObject>
#include <QSharedPointer>
#include <QStack>

#include "ship.h"
#include "types.h"
#include "gameCell.h"
#include "textureAnalyzer.h"
#include "BattleWidget.h"

/**
  * Abstract class for enemy & player field.
  * It defines the interface for access to fields.
  */
class GameField : public QObject
{
    Q_OBJECT
public:
	GameField(const QSharedPointer<InterfaceField>& fieldView);

    virtual ~GameField()
    {}

    /**
      * Set ship.
      *
      * @param id id of cell where ship will placed (if ship occupied few cells, it cell will be top or left,
      *     depend on orientation.
      * @param orientation orientation of ship (for multicell ships).
      *     true - horizontal,
      *     false - vertical
      * @param ship ship for placement.
      */
    void setShip(int id, bool orientation, QSharedPointer<Ship> ship);
    /**
      * Return pointer to ship placed on cell with passed id.
      */
    QSharedPointer<Ship> getShip(int id);
    /**
      * Remove ship placed on cell with recieved id.
      */
    void removeShip(int id);
    /**
      * Attack cell with id given by argument. Return the result of attack.
      */
	virtual AttackStatus attack(int id);
    /**
      * Check could this cell being attack.
      */
    bool attackable(int id);
signals:
    /**
      * This is emited when the ship placed on field.
      * RemotePlayer class uses it to know about placement of human player's fleet
      * (to send it then to another game client).
      */
    //void shipPlaced(int size, int id, bool orientation);
    /**
      *
      **/
    void shipSet();
protected:
	int position(QVector<int> vector, int id);
	void markKilled(int i, int j);
    virtual void repaintCell(int row, int column, int partOfShip, int shipSize, bool orientation);

    typedef QPair<int, int> Coord;
	QSharedPointer<InterfaceField> view;
    QSharedPointer<TextureAnalyzer> textureAnalyzer;

	GameCell field[FIELD_ROW_NUM][FIELD_COL_NUM];
	QVector<int> fleet;// at 0 - count of BOAT_SCOUT at 3 - count of AEROCARRIER

};


#endif // GAMEFIELD_H
