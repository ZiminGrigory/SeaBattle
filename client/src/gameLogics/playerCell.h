#pragma once
#include <QObject>
#include <QSharedPointer>

#include "types.h"
#include "ship.h"
#include "cell.h"

/**
  * PlayerCell is a class of cells belong to player.
  * These cells can be attacked by enemy player.
  */
class PlayerCell : public QObject
{
    Q_OBJECT
public:
    explicit PlayerCell(QObject* parent = 0);
    
    /**
      * Attack cell and return the result.
      */
    AttackStatus attack();
    /**
      * Return ship placed on this cell.
      */
    QSharedPointer<Ship> getShip();
    /**
      * Set ship to this cell.
      */
    void setShip(const QSharedPointer<Ship>& _ship);
    /**
      * Mark this cell depending on result of attack.
      */
    void mark(AttackStatus res);
    /**
      *
      */
    void setView(Cell* _cellView);

	void deleteShip();

private:
    /**
      * Pointer to the ship placed on this cell.
      */
    QSharedPointer<Ship> ship;
    /**
      *
      */
    Cell* cellView;
};
