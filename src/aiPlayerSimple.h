#ifndef AIPLAYERSIMPLE_H
#define AIPLAYERSIMPLE_H

#include "aiPlayer.h"
/**
  * Simple computer player, random choose and correctness check.
  */

class AIPlayerSimple : public AIPlayer
{
public:
    Q_OBJECT
public:
    explicit AIPlayerSimple(View *view, QObject* parent = 0);
    void installFleet();
private:
    int chooseRandomCell();
public slots:
    /**
      * Nothing to thing about it, choose the random cell!
      */
    void turn();
};

#endif // AIPLAYERSIMPLE_H
