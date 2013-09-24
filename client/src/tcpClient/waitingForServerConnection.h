#ifndef WAITINGFORSERVERCONNECTION_H
#define WAITINGFORSERVERCONNECTION_H

#include <QTimer>

#include "clientstate.h"

/**
  * This state is active when a client tries to connect to the server.
  */
class WaitingForServerConnection : public ClientState
{
    Q_OBJECT
public:
    explicit WaitingForServerConnection(const QSharedPointer<Client> _client,
                                        const QSharedPointer<QTcpSocket> _socket,
                                        QObject *parent = 0):
        ClientState(_client, _socket, parent)
    {
    }

    
public slots:
    /**
      * Try to set connection with server.
      * If connection fails or waiting times out object will emit error signal.
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
    
private slots:
    void connectionTimeoutHandler();
    void errorHandler(QAbstractSocket::SocketError err);
private:
    static const int connectionTimeout;
};

inline void WaitingForServerConnection::abort()
{

}

inline bool WaitingForServerConnection::send(const QByteArray& bytes)
{
    Q_UNUSED(bytes);
}

#endif // WAITINGFORSERVERCONNECTION_H
