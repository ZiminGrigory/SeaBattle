#include "client.h"
#include "stateCollection.h"
#include "searchGameState.h"

const int SearchGameState::connectionTimeout = 10 * 1000;

SearchGameState::SearchGameState(Client* _client, QObject* parent):
    ClientState(_client, parent),
    connectionLock(true)
{
    timer.setSingleShot(true);
    QObject::connect(&timer, SIGNAL(timeout()), this, SLOT(connectionTimeoutHandler()));
    QObject::connect(client, SIGNAL(connectedWithPlayer()), this, SLOT(connectedHandler()));
}

void SearchGameState::connect(const QString& hostName, quint16 port) throw(Protocol::AlreadyConnected)
{
    if (connectionLock)
    {
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

void SearchGameState::handleRecievedRequest(Protocol::RequestType type, const QByteArray& bytes)
{
    if (type == Protocol::CHECK_STATE)
    {
        writeToSocket(Protocol::SEEKING_GAME, QByteArray());
    }
    else if (type == Protocol::GAME_FOUND)
    {
        QDataStream request(bytes);
        request.setVersion(Protocol::QDataStreamVersion);

        quint16 port;
        request >> port;

        QString hostName = QString::fromUtf8(bytes.mid(5).data(), bytes.size() - 5);

        connectionLock = false;
        connect(hostName, port);
    }
}

void SearchGameState::init()
{
    connectionLock = true;
    ClientState::writeToSocket(Protocol::SEARCH_GAME, QByteArray());
}

void SearchGameState::connectedHandler()
{
    timer.stop();
}

void SearchGameState::connectionTimeoutHandler()
{
    client->abort();
    emit error(QString("Player response time elapsed"));
}

