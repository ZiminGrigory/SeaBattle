#ifndef PLAYERFIELD_H
#define PLAYERFIELD_H

#include <QObject>

#include "types.h"
#include "playerCell.h"

/**
  * Class of game field of player.
  * PlayerField holds player cells and manages the state of field.
  */
class PlayerField : public QObject
{
    Q_OBJECT
public:
    explicit PlayerField(QObject* parent = 0);

    /**
      * Attack cell with id given by argument. Return the result of attack.
      */
    AttackStatus attacked(int id);

private:
    PlayerCell field[FIELD_ROW_NUM][FIELD_COL_NUM];
};

#endif // PLAYERFIELD_H
