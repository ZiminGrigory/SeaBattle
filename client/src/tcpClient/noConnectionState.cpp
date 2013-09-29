#include "client.h"
#include "stateCollection.h"
#include "noConnectionState.h"

const int NoConnectionState::connectionTimeout = 10 * 1000;

NoConnectionState::NoConnectionState(const QWeakPointer<Client> &_client, QObject *parent):
    ClientState(_client, parent)
{
    timer.setSingleShot(true);
    QObject::connect(&timer, SIGNAL(timeout()), this, SLOT(connectionTimeoutHandler()));
    QObject::connect(client.data(), SIGNAL(connectedWithServer()), this, SLOT(connectedHandler()));
}

void NoConnectionState::connect(const QString & hostName, quint16 port) throw(Protocol::AlreadyConnected)
{
    socket->connectToHost(Protocol::ServerName, port);
    timer.start(connectionTimeout);
    moveIntoState(getStateCollection()->getWaitingForServerConnectionState());
}

void NoConnectionState::send(Protocol::RequestType type, const QByteArray &bytes)
    throw(Protocol::SendingForbidden, Protocol::RequestTypeForbidden)
{
    Q_UNUSED(type);
    Q_UNUSED(bytes);
    throw Protocol::SendingForbidden();
}

void NoConnectionState::connectedHandler()
{
    timer.stop();
}

void NoConnectionState::connectionTimeoutHandler()
{
    client.toStrongRef()->abort();
    emit error(QString("Server response time elapsed"));
}

