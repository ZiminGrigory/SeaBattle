#ifndef GAMEMASTER_H
#define GAMEMASTER_H

#include <QObject>
#include <QSharedPointer>

#include "player.h"

class GameMaster : public QObject
{
    Q_OBJECT
public:
    explicit GameMaster(Player* plr1, Player* plr2, const FleetFactory &fleetCreator, QObject* parent = 0);

public slots:
    /**
      * Offer to made turn to turned player.
      */
    void offerTurn();
    /**
      * Inform waited player that player attacked the cell with passed id.
      */
    void informOpponent(int id);
    /**
      * Inform turned player about the result of attack.
      */
    void informPlayer(AttackStatus attackResult);
    /**
      * This slot ends current turn and start the new one.
      */
    void nextTurn(AttackStatus turnResult);
private:
    typedef QSharedPointer<Player> ptrPlayer;
    ptrPlayer player1;
    ptrPlayer player2;

    ptrPlayer turnedPlayer;
    ptrPlayer waitingPlayer;
};

#endif // GAMEMASTER_H
