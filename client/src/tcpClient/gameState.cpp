#include "client.h"
#include "stateCollection.h"
#include "gameState.h"

GameState::GameState(Client* _client, QObject* parent):
    ClientState(_client, parent)
{
}

void GameState::abort()
{
    socket->disconnectFromHost();
    moveIntoState(getStateCollection()->getNoConnectionState());
}

void GameState::send(Protocol::RequestType type, const QByteArray& bytes)
    throw (Protocol::SendingForbidden, Protocol::RequestTypeForbidden)
{
    if ((type != Protocol::FLEET_INSTALLED) || (type != Protocol::TURN_MADE))
    {
        throw Protocol::RequestTypeForbidden();
    }
    writeToSocket(type, bytes);
}

void GameState::handleRecievedRequest(Protocol::RequestType type, const QByteArray& bytes)
{
    if ((type == Protocol::FLEET_INSTALLED) || (type == Protocol::TURN_MADE))
    {
        emit received(type, bytes);
    }
}


