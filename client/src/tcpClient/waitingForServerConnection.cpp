#include "client.h"
#include "stateCollection.h"
#include "waitingForServerConnection.h"

WaitingForServerConnectionState::WaitingForServerConnectionState(const QWeakPointer<Client> _client, QObject *parent):
    ClientState(_client, parent)
{}


void WaitingForServerConnectionState::connect(const QString &serverName, quint16 port) throw(Protocol::AlreadyConnected)
{
    Q_UNUSED(serverName);
    Q_UNUSED(port);
}

void WaitingForServerConnectionState::abort()
{
    disconnect(socket.data(), SIGNAL(connected()), this, SIGNAL(connectedHandler()));
    socket->abort();
    moveIntoState(getStateCollection()->getNoConnectionState());
}

void WaitingForServerConnectionState::init()
{
    QObject::connect(this, SIGNAL(connectedWithServer()), client.data(), SIGNAL(connectedWithServer()));
}

void WaitingForServerConnectionState::connectedHandler()
{
    moveIntoState(QSharedPointer<ClientState>(getStateCollection()->getSearchGameState()));
    emit connectedWithServer();
}

void WaitingForServerConnectionState::errorHandler(QAbstractSocket::SocketError err)
{
}



