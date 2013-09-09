#ifndef ENEMYCELL_H
#define ENEMYCELL_H

#include <QObject>

#include "cell.h"
#include "types.h"

/**
  * EnemyCell is a class of cells on enemy field. These cells can be attacked by player and marked depending on
  * result of attack.
  */
class EnemyCell : public QObject
{
    Q_OBJECT
public:
    explicit EnemyCell(QObject* parent = 0);

    /**
      * Mark the cell depending on result of attack.
      */
    void mark(AttackStatus res);
    AttackStatus getAttackStatus();
    /**
      * Attack this cell.
      *
      * @return true if this cell could be attacked, false otherwise.
      */
    bool attack();
    /**
      *
      */
    void setView(Cell* _cellView);
private:
    /**
      * HIDE cell is a cell that has not attacked yet,
      * VISIBLE cell is a cell that is already attacked.
      */
    enum State
    {
        WAS_NOT_ATTACKED,
        WAS_ATTACKED
    };
    State state;
    AttackStatus attackStatus;

    Cell* cellView;
};

#endif // ENEMYCELL_H
