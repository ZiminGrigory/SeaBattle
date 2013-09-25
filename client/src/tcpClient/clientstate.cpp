#include "client.h"
#include "clientstate.h"

ClientState::ClientState(const QSharedPointer<Client>& _client,
                             QObject *parent):
        QObject(parent),
        client(_client),
        socket(_client->socket)
    {
    }

void ClientState::moveIntoState(const QSharedPointer<ClientState> &newState)
{
    client.toStrongRef()->setState(newState);
}
