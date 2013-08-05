#ifndef ENEMYCELL_H
#define ENEMYCELL_H

#include <QObject>

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
    void mark(AttackResult res);
signals:
    /**
      * Signal emitted when the cell being attacked.
      */
    attacked();
public slots:
    /**
      * Attack this cell.
      */
    void attack();
private:
    /**
      * HIDE cell is a cell that has not attacked yet,
      * VISIBLE cell is a cell that is already attacked.
      */
    enum State
    {
        HIDE,
        VISIBLE
    };
    /**
      * state defines the visibility of the cell.
      */
    State state;
};

#endif // ENEMYCELL_H
