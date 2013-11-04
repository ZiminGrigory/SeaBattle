#include "client.h"
#include "stateCollection.h"
#include "gameState.h"

GameState::GameState(Client* _client, QObject* parent):
    ClientState(_client, parent)
{
}

void GameState::abort()
{
    getSocket()->disconnectFromHost();
    moveIntoState(getStateCollection()->getNoConnectionState());
}

void GameState::send(Protocol::RequestType type, const QByteArray& bytes)
    throw (Protocol::SendingForbidden, Protocol::RequestTypeForbidden)
{
    if ((type != Protocol::FLEET_INSTALLED) && (type != Protocol::TURN_MADE) &&
            (type != Protocol::CHAT_MESSAGE) && (type != Protocol::PLAYER_QUIT))
    {
        throw Protocol::RequestTypeForbidden();
    }
    writeToSocket(type, bytes);
}

void GameState::init()
{
    QAbstractSocket::SocketState state = getSocket()->state();
    QObject::connect(getSocket().data(), SIGNAL(readyRead()), this, SLOT(readyReadHandler()));

}

void GameState::handleRecievedRequest(Protocol::RequestType type, const QByteArray& bytes)
{
    if ((type == Protocol::FLEET_INSTALLED)
            || (type == Protocol::TURN_MADE)
            || (type == Protocol::CHAT_MESSAGE)
            || (type == Protocol::PLAYER_QUIT))
    {
        emit received(type, bytes);
    }
}


