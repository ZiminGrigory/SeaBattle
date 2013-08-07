#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>

#include "playerField.h"
#include "enemyField.h"

/**
  * Player is a inherited class for all implementation of players (human, AI etc).
  */
class Player : public QObject
{
    Q_OBJECT
public:
    explicit Player(QObject* parent = 0) :
        QObject(parent)
    {}
    virtual ~Player() {}
signals:
    /**
      * This signal must be emitted when player chose a cell to attack (id is an identifier of a cell).
      */
    void turnMade(int id);
public slots:
    /**
      * This slot called by GameMaster to offer player make his choise (choose a cell for attack).
      */
    virtual void turn() = 0;
    /**
      * This slot called by GameMaster to inform player about results of his turn.
      */
    inline void turnResult(AttackStatus attackResult);
    /**
      * This slot called by GameMaster to inform player about enemy turn
      * (actually, about what cell being attacked).
      * GameMaster expects to get result of attack.
      */
    inline AttackStatus enemyTurn(int id);
protected:
    PlayerField myField;
    EnemyField enemyField;
};

inline void Player::turnResult(AttackStatus attackResult)
{
    enemyField.attackResult(attackResult);
}

AttackStatus Player::enemyTurn(int id)
{
    return myField.attack(id);
}

#endif // PLAYER_H
