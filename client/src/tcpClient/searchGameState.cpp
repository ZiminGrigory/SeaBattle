#include "client.h"
#include "stateCollection.h"
#include "searchGameState.h"

const int SearchGameState::connectionTimeout = 10 * 1000;

SearchGameState::SearchGameState(const QWeakPointer<Client> _client, QObject* parent):
    ClientState(_client, parent),
    connectionLock(true)
{
    timer.setSingleShot(true);
    QObject::connect(&timer, SIGNAL(timeout()), this, SLOT(connectionTimeoutHandler()));
    QObject::connect(client.data(), SIGNAL(connectedWithPlayer()), this, SLOT(connectedHandler()));
}

void SearchGameState::connect(const QString& hostName, quint16 port) throw(Protocol::AlreadyConnected)
{
    if (connectionLock)
    {
        Q_UNUSED(hostName);
        Q_UNUSED(port);
        throw Protocol::AlreadyConnected();
    }
    else
    {
        socket->connectToHost(hostName, port);
        timer.start(connectionTimeout);
        connectionLock = true;
        moveIntoState(getStateCollection()->getWaitingForPlayerConnectionState());
    }
}

void SearchGameState::abort()
{
    socket->abort();
    moveIntoState(getStateCollection()->getNoConnectionState());
}

void SearchGameState::send(Protocol::RequestType type, const QByteArray& bytes)
    throw(Protocol::SendingForbidden, Protocol::RequestTypeForbidden)
{
    Q_UNUSED(type);
    Q_UNUSED(bytes);
    throw Protocol::SendingForbidden();
}

void SearchGameState::handleRecievedRequest(Protocol::RequestType type, const QByteArray& bytes)
{
    if (type == Protocol::CHECK_STATE)
    {
        ClientState::send(Protocol::SEEKING_GAME, QByteArray());
    }
    else if (type == Protocol::GAME_FOUND)
    {
        // to do: some code which is exstract host & port from bytes
        QString hostName;
        quint16 port;
        connectionLock = false;
        connect(hostName, port);
    }
}

void SearchGameState::init()
{
    connectionLock = true;
    ClientState::send(Protocol::SEARCH_GAME, QByteArray());
}

void SearchGameState::connectedHandler()
{
    timer.stop();
}

void SearchGameState::connectionTimeoutHandler()
{
    client.toStrongRef()->abort();
    emit error(QString("Player response time elapsed"));
}

