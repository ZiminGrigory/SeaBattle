#include "clientstate.h"

ClientState::ClientState(QObject *parent) :
    QObject(parent)
{
}

ClientState::ClientState(const QSharedPointer<Client> _client,
                         const QSharedPointer<QTcpSocket> _socket,
                         QObject *parent):
    QObject(parent),
    client(_client),
    socket(_client->socket)
{
}
