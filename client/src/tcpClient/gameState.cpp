#include "client.h"
#include "stateCollection.h"
#include "gameState.h"

GameState::GameState(const QWeakPointer<Client>& _client, QObject* parent):
    ClientState(_client, parent)
{
}

void GameState::abort()
{
}

void GameState::send(Protocol::RequestType type, const QByteArray &bytes)
    throw (Protocol::SendingForbidden, Protocol::RequestTypeForbidden)
{

}
