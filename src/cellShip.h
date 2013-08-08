#ifndef CELLSHIP_H
#define CELLSHIP_H

#include "ship.h"

/**
  * Implementation of ships which consists of several cells.
  * Template parameter is a number of cells of ship.
  */
template <int cells> class CellShip : public Ship
{
public:
    CellShip():
        health(cells)
    {}
    int damage();
    int size() const;
private:
    int health;
};

template <int cells>
int CellShip::damage()
{
    return health--;
}

template <int cells>
int CellShip::size() const
{
    return cells;
}

#endif // CELLSHIP_H
