#ifndef PLAYERFIELD_H
#define PLAYERFIELD_H

#include <QObject>
#include <QSharedPointer>

#include "types.h"
#include "playerCell.h"
#include "view.h"

/**
  * Class of game field of player.
  * PlayerField holds player cells and manages the state of field.
  */
class PlayerField : public QObject
{
    Q_OBJECT
public:
    explicit PlayerField(View* _view, QObject* parent = 0);

    /**
      * Attack cell with id given by argument. Return the result of attack.
      */
    AttackStatus attack(int id);
    /**
      * Return pointer to ship placed on cell with passed id.
      */
    QSharedPointer<Ship> getShip(int id);
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
      *
      */
    void setPlr(Players _plr);

private:
    PlayerCell field[FIELD_ROW_NUM][FIELD_COL_NUM];
    View* view;
    Players plr;
};

#endif // PLAYERFIELD_H
