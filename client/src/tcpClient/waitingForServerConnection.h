#ifndef WAITINGFORSERVERCONNECTION_H
#define WAITINGFORSERVERCONNECTION_H

#include <QTimer>
#include <QTcpSocket>

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
    explicit WaitingForServerConnectionState(const QWeakPointer<Client> _client, QObject *parent = 0);
    
public slots:
    /**
      * Abort connection with server
      */
    void abort();
signals:
    void connectedWithServer();
protected:
    void init();
private slots:
    void connectedHandler();
    void errorHandler(QAbstractSocket::SocketError err);
};

#endif // WAITINGFORSERVERCONNECTION_H
