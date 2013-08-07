#ifndef PLAYERCELL_H
#define PLAYERCELL_H

#include <QObject>
#include <QSharedPointer>

#include "types.h"
#include "ship.h"

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
      * Mark this cell depending on result of attack.
      */
    void mark(AttackStatus res);
private:
    /**
      * Pointer to the ship placed on this cell.
      */
    QSharedPointer<Ship> ship;
};

#endif // PLAYERCELL_H
