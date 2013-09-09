#ifndef GAMEFIELD_H
#define GAMEFIELD_H

#include <QObject>
#include <QSharedPointer>
#include <QStack>

#include "ship.h"
#include "types.h"
#include "gameCell.h"
#include "fieldView.h"

/**
  * Abstract class for enemy & player field.
  * It defines the interface for access to fields.
  */
class GameField : public QObject
{
    Q_OBJECT
public:
    GameField(const QSharedPointer<FieldView>& fieldView);
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
      *
      */
    void removeShip(int id);
    /**
      * Attack cell with id given by argument. Return the result of attack.
      */
    AttackStatus attack(int id);
    /**
      * Check could this cell being attack.
      */
    bool attackable(int id);
private:
    typedef QPair<int, int> Coord;
    void markKilled(int i, int j, QStack<Coord>* markedCells);
    Textures textureOfCell(int i, int shipSize, bool orientation);

    GameCell field[FIELD_ROW_NUM][FIELD_COL_NUM];
    QSharedPointer<FieldView> view;
};


#endif // GAMEFIELD_H
