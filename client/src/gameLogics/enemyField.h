#ifndef ENEMYFIELD_H
#define ENEMYFIELD_H

#include <QObject>
#include <QSignalMapper>
#include <QPair>
#include <QStack>

#include "types.h"
#include "enemyCell.h"
#include "view.h"

// for test purpose
class EnemyFieldTest;

/**
  * Class of enemy player field.
  * Enemy field emits signals when player tries to attack enemy cell and manages the state of field.
  */
class EnemyField : public QObject
{
    Q_OBJECT
public:
    explicit EnemyField(View* _view, QObject *parent = 0);
    
    /**
      * This method called to inform field about result of last attack.
      */
    void attackResult(AttackStatus res);
    /**
      * Method should be called by player to inform field about chosen cell on enemy field that will attacked.
      *
      * @return true if chosen cell could be attacked, false otherwise.
      */
    bool attack(int id);

    // for test purpose
    friend class EnemyFieldTest;
private:
    typedef QPair<int, int> Coord;
    /**
      * Method used when ship destroyed by player and it need to marked neighboor cells.
      */
    void markKilled(int i, int j, QStack<Coord>* markedCell);

    EnemyCell field[FIELD_ROW_NUM][FIELD_COL_NUM];
    int lastAttackedCellId;
    Players plr;
    View* view;
};

#endif // ENEMYFIELD_H
