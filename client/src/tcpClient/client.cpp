#include "client.h"
#include "clientstate.h"
#include "stateCollection.h"

Client::Client(QObject *parent) :
    QObject(parent),
    stateCollection(new StateCollection(QWeakPointer<Client>(this)))
{
    connect(state.data(), SIGNAL(error(const QString&)), this, SIGNAL(received(const QString&)));
    connect(state.data(), SIGNAL(recieved(const QByteArray&)), this, SIGNAL(received(const QByteArray&)));
}

void Client::connectToServer()
{
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
