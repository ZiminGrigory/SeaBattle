#include "waitingForServerConnection.h"

const int WaitingForServerConnectionState::connectionTimeout = 10 * 1000;

WaitingForServerConnectionState::WaitingForServerConnectionState(const QSharedPointer<Client> _client, QObject *parent):
    ClientState(_client, parent)
{
    timer.setSingleShot(true);
    QObject::connect(&timer, SIGNAL(timeout()), this, SLOT(connectionTimeoutHandler()));

    QObject::connect(this, SIGNAL(connectedWithServer()), client.data(), SIGNAL(connectedWithServer()));
}

bool WaitingForServerConnectionState::connection(const QString &serverName, quint16 port)
{
    disconnect(socket.data(), SIGNAL(error(QAbstractSocket::SocketError)),
                this, SLOT(errorHandler(QAbstractSocket::SocketError)));
    disconnect(socket.data(), SIGNAL(connected()), client.data(), SIGNAL(connectedWithServer()));
    socket->abort();

    QObject::connect(socket.data(), SIGNAL(connected()), this, SIGNAL(connectedHandler()));
    QObject::connect(socket.data(), SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(errorHandler(QAbstractSocket::SocketError)));
    socket->connectToHost(serverName, port);
    timer.start(connectionTimeout);
}


void WaitingForServerConnectionState::connectedHandler()
{
    moveIntoState(QSharedPointer<ClientState>(new SearchGameState(client)));
    emit connectedWithServer();
}

void WaitingForServerConnectionState::connectionTimeoutHandler()
{
    disconnect(socket.data(), SIGNAL(connected()), client.data(), SIGNAL(connectedWithServer()));
    disconnect(socket.data(), SIGNAL(error(QAbstractSocket::SocketError)),
                this, SLOT(errorHandler(QAbstractSocket::SocketError)));
    emit error(QString("Server response time elapsed"));
    moveIntoState(QSharedPointer<ClientState>(new NoConnectionState(client)));
}

void WaitingForServerConnectionState::errorHandler(QAbstractSocket::SocketError err)
{

}

