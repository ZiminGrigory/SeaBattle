#ifndef WAITINGFORSERVERCONNECTION_H
#define WAITINGFORSERVERCONNECTION_H

#include <QTimer>
#include <QTcpSocket>
#include <QDebug>

#include "protocol.h"
#include "clientstate.h"
#include "searchGameState.h"
#include "noConnectionState.h"


/**
  * This state is active when a client tries to connect to the server.
  */
class WaitingForServerConnectionState : public ClientState
{
    Q_OBJECT
public:
    explicit WaitingForServerConnectionState(Client* _client, QObject *parent = 0);
    
public slots:
    /**
      * Do nothing, because object is already tried to set connection at current moment.
      */
    void connect(const QString& hostName, quint16 port) throw (Protocol::AlreadyConnected);
    /**
      * Abort connection with server
      */
    void abort();
signals:
    void connectedWithServer();
protected:
    void init();
private slots:
    /**
      * Emit connectedWithServer() signal (which is connected with the same signal of clien object)
      * and move to SearchGameState.
      */
    void connectedHandler();
    void errorHandler(QAbstractSocket::SocketError err);
};

#endif // WAITINGFORSERVERCONNECTION_H
