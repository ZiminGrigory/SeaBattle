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
      * Reconnection.
      */
    void connect(const QString& serverName, quint16 port) throw(Protocol::AlreadyConnected);
    /**
      * Do nothing.
      */
    void abort();
    /**
      * We can't send message untill we not connected with server.
      *
      * @return always false.
      */
    inline void send(Protocol::RequestType type, const QByteArray& bytes)
        throw (Protocol::SendingForbidden, Protocol::RequestTypeForbidden);

signals:
    void connectedWithServer();
protected:
    void init();
private slots:
    void connectedHandler();
    void errorHandler(QAbstractSocket::SocketError err);
};

inline void WaitingForServerConnectionState::send(Protocol::RequestType type, const QByteArray& bytes)
    throw(Protocol::SendingForbidden, Protocol::RequestTypeForbidden)
{
    Q_UNUSED(type);
    Q_UNUSED(bytes);
    throw Protocol::SendingForbidden();
}

#endif // WAITINGFORSERVERCONNECTION_H
