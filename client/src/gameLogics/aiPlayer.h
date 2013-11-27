#pragma once
#ifndef AIPLAYER_H
#define AIPLAYER_H

#include <QObject>
#include <QTime>
#include <QDebug>
#include "types.h"
#include "player.h"


/**
  * Abstract class for two types of AIplayer - smart and simple.
  */
class AIPlayer : public Player
{
    Q_OBJECT
public:
	explicit AIPlayer(const QSharedPointer<GameField> &plrField,
					  const QSharedPointer<GameField>& enmField,
					  QObject *parent = 0);

    virtual void installFleet() = 0;
    virtual ~AIPlayer()
    {}
protected:
    static const int delay;
    virtual void decreaseFleet(int currentShip) = 0;
    virtual int chooseCell() = 0;
private:
    void changeDirection();
    int lastAttackedCell;
    int tryToKill(int id);
    int attackedCells[3];
    void clear();
    Direction direction;
    AttackStatus lastAttackResult;
    bool isWounded;
    int cnt;
    bool directionChanged;
    int currentShip;
public slots:

    virtual void turn() = 0;
protected slots:
    void delayTurn();
};

#endif // AIPLAYER_H
