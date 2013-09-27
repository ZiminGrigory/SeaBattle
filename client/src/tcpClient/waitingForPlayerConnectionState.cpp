#include "client.h"
#include "stateCollection.h"
#include "waitingForPlayerConnectionState.h"

WaitingForPlayerConnectionState::WaitingForPlayerConnectionState(const QWeakPointer<Client> _client, QObject* parent):
    ClientState(_client, parent)
{
    //QObject::connect(this, SIGNAL(connectedWithPlayer()), client.data(), SIGNAL(connectedWithPlayer()));
}

void WaitingForPlayerConnectionState::connect(const QString &hostName, quint16 port) throw(Protocol::AlreadyConnected)
{
    Q_UNUSED(hostName);
    Q_UNUSED(port);
}

void WaitingForPlayerConnectionState::abort()
{
    disconnect(socket.data(), SIGNAL(connected()), this, SIGNAL(connectedHandler()));
    socket->abort();
    moveIntoState(getStateCollection()->getNoConnectionState());
}


void WaitingForPlayerConnectionState::init()
{
    QObject::connect(this, SIGNAL(connectedWithPlayer()), client.data(), SIGNAL(connectedWithPlayer()));
}

void WaitingForPlayerConnectionState::connectedHandler()
{
    moveIntoState(getStateCollection()->getGameState());
    emit connectedWithPlayer();
}

