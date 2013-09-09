#ifndef GAMECELL_H
#define GAMECELL_H

#include "types.h"
#include "ship.h"

class GameCell
{
public:
    GameCell();

    /**
      * Attack cell and return the result.
      */
    AttackStatus attack();
    /**
      * Return true if this cell could be attack, false otherwise.
      */
    bool attackable();
    /**
      * Return ship placed on this cell.
      */
    QSharedPointer<Ship> getShip();
    /**
      * Set ship to this cell.
      */
    void setShip(const QSharedPointer<Ship>& _ship);
private:
    /**
      * Pointer to the ship placed on this cell.
      */
    QSharedPointer<Ship> ship;
    enum State
    {
        WAS_NOT_ATTACKED,
        WAS_ATTACKED
    };
    State state;
    AttackStatus attackStatus;
};

#endif // GAMECELL_H
