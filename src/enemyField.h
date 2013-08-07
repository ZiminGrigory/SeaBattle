#ifndef ENEMYFIELD_H
#define ENEMYFIELD_H

#include <QObject>
#include <QSignalMapper>
#include <QPair>
#include <QStack>

#include "types.h"
#include "enemyCell.h"

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
    explicit EnemyField(QObject *parent = 0);
    
    /**
      * This method called to inform field about result of last attack.
      */
    void attackResult(AttackStatus res);

    // for test purpose
    friend class EnemyFieldTest;
signals:
    /**
      * Emits when the cell being attack.
      */
    void attacked(int id);
private slots:
    /**
      * This slot connected with signal "attack" from cells.
      */
    void attack(int id);
private:
    typedef QPair<int, int> Coord;
    /**
      * Method used when ship destroyed by player and it need to marked neighboor cells.
      */
    void markKilled(int x, int y, QStack<Coord>* markedCell);
    /**
      * Check are x & y correct coordinates.
      */
    bool checkCoord(int x, int y);

    EnemyCell field[FIELD_ROW_NUM][FIELD_COL_NUM];
    int lastAttackedCellId;
    /**
      * Bundles signals from cells.
      */
    QSignalMapper mapper;
};

#endif // ENEMYFIELD_H
