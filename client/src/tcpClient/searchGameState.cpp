#include "client.h"
#include "stateCollection.h"
#include "searchGameState.h"

const int SearchGameState::connectionTimeout = 20 * 1000;

SearchGameState::SearchGameState(Client* _client, QObject* parent):
    ClientState(_client, parent),
    connectionLock(true)
{
    timer.setSingleShot(true);
    QObject::connect(&timer, SIGNAL(timeout()), this, SLOT(connectionTimeoutHandler()));
    QObject::connect(client, SIGNAL(connectedWithPlayer()), this, SLOT(connectedHandler()));


    QObject::connect(this, SIGNAL(connected()), client, SIGNAL(connectedWithPlayer()));
}

void SearchGameState::connect(const QString& hostName, quint16 port) throw(Protocol::AlreadyConnected)
{
    throw Protocol::AlreadyConnected();
}

void SearchGameState::abort()
{
    tmpServer.close();
    disconnect(&tmpServer, SIGNAL(newConnection()), this, SLOT(connectionHandler()));
    getSocket()->abort();
    moveIntoState(getStateCollection()->getNoConnectionState());
}

void SearchGameState::init()
{
    QObject::connect(getSocket().data(), SIGNAL(readyRead()), this, SLOT(readyReadHandler()));
    QObject::connect(&tmpServer, SIGNAL(newConnection()), SLOT(connectionHandler()));
    tmpServer.listen(QHostAddress::Any, 0);

    QByteArray bytes;
    QDataStream stream(&bytes, QIODevice::ReadWrite);
    stream.setVersion(Protocol::QDataStreamVersion);

    stream << tmpServer.serverPort();

    ClientState::writeToSocket(Protocol::SEARCH_GAME, bytes);
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

        // serverFlag == true means that this client is waiting for connection from another,
        // serverFlag == false - then this client connects with another.
        bool serverFlag;
        request >> serverFlag;

        quint16 port;
        request >> port;

        QString hostName = QString::fromLatin1(bytes.mid(7));

        if (serverFlag)
        {
            timer.start(connectionTimeout);
            disconnect(getSocket().data(), SIGNAL(readyRead()), this, SLOT(readyReadHandler()));
            moveIntoState(getStateCollection()->getWaitingForPlayerConnectionState());
        }
        else
        {
            tmpServer.close();
            getSocket()->abort();
            getSocket()->connectToHost(hostName, port);
            disconnect(getSocket().data(), SIGNAL(readyRead()), this, SLOT(readyReadHandler()));
            moveIntoState(getStateCollection()->getWaitingForPlayerConnectionState());
        }
    }
}


void SearchGameState::connectedHandler()
{
    tmpServer.close();
    timer.stop();
}

void SearchGameState::connectionTimeoutHandler()
{
    tmpServer.close();
    client->abort();
    emit error(QString("Player response time elapsed"));
}

void SearchGameState::connectionHandler()
{
    timer.stop();
    setSocket(QSharedPointer<QTcpSocket>(tmpServer.nextPendingConnection()));
    tmpServer.close();
    disconnect(&tmpServer, SIGNAL(newConnection()), this, SLOT(connectionHandler()));
    moveIntoState(getStateCollection()->getGameState());
    emit connected();
}
