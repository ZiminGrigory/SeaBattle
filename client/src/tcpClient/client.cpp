#include "client.h"
#include "clientstate.h"
#include "stateCollection.h"

Client::Client(QObject *parent) :
    QObject(parent),
    state(NULL),
    socket(new QTcpSocket()),
    stateCollection(new StateCollection(this))
{
    state = stateCollection->getNoConnectionState();
}

void Client::connectToServer()
{
    // abort all connections and return to NoConnectionState
    abort();
    state->connect(Protocol::ServerName, Protocol::ServerPort);
}

void Client::abort()
{
    state->abort();
}

void Client::send(Protocol::RequestType type, const QByteArray &bytes)
    throw(Protocol::SendingForbidden, Protocol::RequestTypeForbidden)
{
    state->send(type, bytes);
}

void Client::setState(const QSharedPointer<ClientState> &newState)
{
    state = newState;
}
