#ifndef ENEMYFIELD_H
#define ENEMYFIELD_H

#include <QObject>
#include <QSignalMapper>

#include "types.h"
#include "enemyCell.h"

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
    void attackResult(AttackResult res);
signals:
    /**
      * Emits when the cell being attack.
      */
    attacked(int id);
private:
    EnemyCell field[FIELD_ROW_NUM][FIELD_COL_NUM];
    /**
      * Bundles signals from cells.
      */
    QSignalMapper mapper;

};

#endif // ENEMYFIELD_H
