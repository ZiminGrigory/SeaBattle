#ifndef AIPLAYER_H
#define AIPLAYER_H

#include <QObject>
#include <QTime>

#include "types.h"
#include "player.h"


enum Direction {     //paste it to types.h
    LEFT,
    DOWN,
    RIGHT,
    HIGH
};

/**
  * Abstract class for two types of AIplayer - smart and simple.
  */
class AIPlayer : public Player
{
    Q_OBJECT
public:
	explicit AIPlayer(View *view, QObject* parent = 0);

    virtual void installFleet() = 0;
protected:
    int tryToKill(int id);
    int attackedCells[3];
    Direction direction;
    AttackStatus lastAttackResult;
    // I still have no idea how and where from to get it
    //bool successShot;
    bool isWounded;
    int lastAttackedCell;

public slots:

    virtual void turn() = 0;
};

#endif // AIPLAYER_H
