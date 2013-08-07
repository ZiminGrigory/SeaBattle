#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include <QObject>

#include "player.h"

// for test purpose
class HumanPlayerTest;

class HumanPlayer : public Player
{
    Q_OBJECT
public:
    explicit HumanPlayer(QObject *parent = 0);
    
    // for test purpose
    friend class HumanPlayerTest;
public slots:
    /**
      * This slot do nothing because it need to wait until player made a choise.
      */
    void turn();
private slots:
};

#endif // HUMANPLAYER_H
