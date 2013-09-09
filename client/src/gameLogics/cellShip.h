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
        _health(cells)
    {}
    inline int damage();
    inline int health() const;
    inline int size() const;
private:
    int _health;
};

template <int cells>
inline int CellShip<cells>::damage()
{
    return --_health;
}

template <int cells>
inline int CellShip<cells>::health() const
{
    return _health;
}

template <int cells>
inline int CellShip<cells>::size() const
{
    return cells;
}

#endif // CELLSHIP_H
