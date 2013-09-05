#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QSharedPointer>

#include "ship.h"
#include "playerField.h"
#include "enemyField.h"
#include "fleetFactory.h"
#include "fleetInstaller.h"

/**
  * Player is a inherited class for all implementation of players (human, AI etc).
  */
class Player : public QObject
{
    Q_OBJECT
public:
    explicit inline Player(QObject* parent = 0);
    virtual ~Player() {}

    /**
      * Check does player lose or his fleet still alive.
      */
    inline bool lose();
    /**
      * Create fleet using FleetFactory object.
      */
    inline void createFleet(const FleetFactory& factory);
    /**
      * Slot intall player fleet on field.
      */
    virtual void installFleet() = 0;
signals:
    /**
      * This signal must be emitted when player chose a cell to attack (id is an identifeir of a cell).
      * Player can emit this signal only after turn() slot was called,
      * and after this wait until turn() will called again.
      * (otherwise game will crash and we all gonna die!!!).
      */
    void turnMade(int id);
    /**
      * After player recieves information about enemy turn, he emits this signal with result of attack.
      */
    void attackResult(AttackStatus res);
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
      * GameMaster expects to get result of attack from attackResult() signal.
      */
    inline void enemyTurn(int id);
protected:
    PlayerField myField;
    EnemyField enemyField;

    QScopedPointer<FleetInstaller> fleetInstaller;

    typedef QSharedPointer<Ship> ptrShip;
    QVector<ptrShip> fleet;
    /**
      * Summary health of fleet, defines the number of hits after which player will lose.
      */
    int fleetHealth;

};

inline Player::Player(QObject *parent) :
    QObject(parent),
    fleetHealth(0),
    fleetInstaller(NULL)
{
    fleetInstaller.reset(new FleetInstaller(fleet, &myField));
}

inline bool Player::lose()
{
    return (fleetHealth == 0);
}

void Player::createFleet(const FleetFactory& factory)
{
    fleet = factory.createFleet();
    fleetHealth = 0;
    for (int i = 0; i < fleet.size(); i++)
    {
        fleetHealth += fleet[i]->health();
    }
}

inline void Player::turnResult(AttackStatus attackResult)
{
    enemyField.attackResult(attackResult);
}

inline void Player::enemyTurn(int id)
{
    AttackStatus status = myField.attack(id);
    if ((status == WOUNDED) || (status == KILLED))
    {
        --fleetHealth;
    }
    emit attackResult(status);
}


#endif // PLAYER_H
