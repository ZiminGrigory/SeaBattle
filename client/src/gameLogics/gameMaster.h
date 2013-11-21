#ifndef GAMEMASTER_H
#define GAMEMASTER_H

#include <QObject>
#include <QSharedPointer>

#include "player.h"
#include "humanPlayer.h"
#include "networkHumanPlayer.h"
#include "remotePlayer.h"
#include "aiPlayerSimple.h"
#include "aiPlayerSmart.h"
#include "playerField.h"
#include "audioPlayer.h"
#include "LogAndChat.h"

class GameMaster : public QObject
{
    Q_OBJECT
public:
    GameMaster(const QSharedPointer<InterfaceBattleWidget>& _view,
               const QSharedPointer<AudioPlayer> _audioPlayer,
               QObject* parent = 0);

    virtual ~GameMaster() {}

public slots:
    /**
      * Method start the game.
      */
    void startGame();
signals:
    /**
      * Signalizes about interruption of game.
      */
    void gameInterrupted();
protected slots:
    /**
      * Handler of the quit of player.
      * Calls after player confirms exit from game.
      */
    virtual void quitHandler();
private slots:
    /**
      *
      */
    void playerReadyToBattle(Player* sender);
    /**
      * Offer to make turn to turned player.
      */
    void offerTurn();
    /**
      * Inform waited player that player attacked the cell with passed id.
      * Before return, call nextTurn() slot.
      */
    void informOpponent(int id, AttackStatus turnResult);
    /**
      * This slot ends current turn and start the new one.
      */
    void nextTurn(AttackStatus turnResult);
    /**
      * Print message to chat.
      */
    void chat(const QString& message);
    /**
      *
      */
    void playShipSetSound(PlacementStatus status);
    /**
      *
      */
    void playerWantToQuit();
protected:
    void initConnections();
    virtual void offerTurnHook();
    virtual void informOpponentHook();

    typedef QSharedPointer<Player> ptrPlayer;
    QSharedPointer<GameField> playerField;
    QSharedPointer<GameField> enemyField;
	QSharedPointer<LogAndChat> mChat;
    ptrPlayer player;
    ptrPlayer enemy;

    ptrPlayer turnedPlayer;
    ptrPlayer waitingPlayer;

	QSharedPointer<InterfaceBattleWidget> view;
    QSharedPointer<AudioPlayer> audioPlayer;

	int plrFleet;
	int enemyFleet;
	bool isFirst;
};

#endif // GAMEMASTER_H
