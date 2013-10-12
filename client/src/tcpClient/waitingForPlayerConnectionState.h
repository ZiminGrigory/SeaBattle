#ifndef WAITINGFORPLAYERCONNECTIONSTATE_H
#define WAITINGFORPLAYERCONNECTIONSTATE_H

#include "protocol.h"
#include "clientstate.h"

class WaitingForPlayerConnectionState : public ClientState
{
    Q_OBJECT
public:
    explicit WaitingForPlayerConnectionState(Client* _client, QObject *parent = 0);
signals:
    void connectedWithPlayer();
public slots:
    /**
      * Do nothing, because object is already tried to set connection at current moment.
      */
    void connect(const QString &hostName, quint16 port) throw (Protocol::AlreadyConnected);
    /**
      *
      */
    void abort();
protected:
    /**
      *
      */
    void init();
private slots:
    /**
      * Emit connectedWithPlayer() signal (which is connected with the same signal of clien object)
      * and move to GameState.
      */
    void connectedHandler();
    /**
      *
      */
    void errorHandler(QAbstractSocket::SocketError err);
};


#endif // WAITINGFORPLAYERCONNECTIONSTATE_H
