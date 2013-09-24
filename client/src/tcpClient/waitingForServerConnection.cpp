#include "waitingForServerConnection.h"

const int WaitingForServerConnection::connectionTimeout = 10 * 1000;

bool WaitingForServerConnection::connection(const QString &serverName, quint16 port)
{
    connect(socket.data(), SIGNAL(connected()), client.data(), SIGNAL(connectedWithServer()));
    connect(socket.data(), SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(errorHandler(QAbstractSocket::SocketError)));
    socket->connectToHost(serverName, port);
    QTimer::singleShot(connectionTimeout, this, SLOT(connectionTimeoutHandler()));
}

void WaitingForServerConnection::connectionTimeoutHandler()
{
    disconnect(socket.data(), SIGNAL(connected()), client.data(), SIGNAL(connectedWithServer()));
    emit error(QString("Server response time elapsed"));
}

void WaitingForServerConnection::errorHandler(QAbstractSocket::SocketError err)
{

}
