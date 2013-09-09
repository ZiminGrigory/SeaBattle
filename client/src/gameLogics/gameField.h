#ifndef GAMEFIELD_H
#define GAMEFIELD_H

#include <QObject>
#include <QSharedPointer>
#include <QStack>

#include "ship.h"
#include "types.h"
#include "gameCell.h"

/**
  * Abstract class for enemy & player field.
  * It defines the interface for access to fields.
  */
class GameField : public QObject
{
    Q_OBJECT
public:
    //virtual ~AbstractField();
    /**
      *
      */
    void setShip(int id, bool orientation, QSharedPointer<Ship> ship);
    /**
      *
      */
    QSharedPointer<Ship> getShip(int id);
    /**
      *
      */
    void removeShip(int id);
    /**
      *
      */
    AttackStatus attack(int id);
    /**
      * Check could this cell being attack.
      */
    bool attackable();
private:
    typedef QPair<int, int> Coord;
    void markKilled(int i, int j, QStack<Coord>* markedCells);

    GameCell field[FIELD_ROW_NUM][FIELD_COL_NUM];
};


#endif // GAMEFIELD_H
