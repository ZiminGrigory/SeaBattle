#ifndef WAITINGFORSERVERCONNECTION_H
#define WAITINGFORSERVERCONNECTION_H

#include <QTimer>

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
    explicit WaitingForServerConnectionState(const QSharedPointer<Client> _client, QObject *parent = 0);

    
public slots:
    /**
      * Reconnection.
      */
    bool connection(const QString& serverName, quint16 port);
    /**
      * Do nothing.
      */
    inline void abort();
    /**
      * We can't send message untill we not connected with server.
      *
      * @return always false.
      */
    inline bool send(const QByteArray& bytes);

signals:
    void connectedWithServer();
private slots:
    void connectedHandler();
    void connectionTimeoutHandler();
    void errorHandler(QAbstractSocket::SocketError err);
private:
    QTimer timer;

    static const int connectionTimeout;
};

inline void WaitingForServerConnectionState::abort()
{

}

inline bool WaitingForServerConnectionState::send(const QByteArray& bytes)
{
    Q_UNUSED(bytes);
}

#endif // WAITINGFORSERVERCONNECTION_H
