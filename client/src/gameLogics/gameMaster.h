#ifndef GAMEMASTER_H
#define GAMEMASTER_H

#include <QObject>
#include <QSharedPointer>
#include "view.h"
#include "player.h"
#include "humanPlayer.h"
#include "aiPlayer.h"

class GameMaster : public QObject
{
    Q_OBJECT
public:
    GameMaster(const QSharedPointer<View>& view,
                        QObject* parent = 0);

    /**
      * Method start the game.
      */
    void startGame();
private slots:
    /**
      *
      */
    void playerReadyToBattle();
    /**
      * Offer to make turn to turned player.
      */
    void offerTurn();
    /**
      * Inform waited player that player attacked the cell with passed id.
      */
    void informOpponent(int id);
    /**
      * Inform turned player about the result of attack.
      */
    //void informPlayer(AttackStatus attackResult);
    /**
      * This slot ends current turn and start the new one.
      */
    void nextTurn(AttackStatus turnResult);
private:
    typedef QSharedPointer<Player> ptrPlayer;
    ptrPlayer player;
    ptrPlayer enemy;

    ptrPlayer turnedPlayer;
    ptrPlayer waitingPlayer;

    QSharedPointer<GameField> playerField;
    QSharedPointer<GameField> enemyField;

    QSharedPointer<View> view;
};

#endif // GAMEMASTER_H
