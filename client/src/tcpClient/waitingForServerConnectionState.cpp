#include "client.h"
#include "stateCollection.h"
#include "waitingForServerConnectionState.h"

WaitingForServerConnectionState::WaitingForServerConnectionState(const QWeakPointer<Client> _client, QObject *parent):
    ClientState(_client, parent)
{
    QObject::connect(this, SIGNAL(connectedWithServer()), client.data(), SIGNAL(connectedWithServer()));
}

void WaitingForServerConnectionState::connect(const QString &serverName, quint16 port) throw(Protocol::AlreadyConnected)
{
    Q_UNUSED(serverName);
    Q_UNUSED(port);
}

void WaitingForServerConnectionState::abort()
{
    disconnect(socket.data(), SIGNAL(connected()), this, SIGNAL(connectedHandler()));
    socket->abort();
    moveIntoState(getStateCollection()->getNoConnectionState());
}

void WaitingForServerConnectionState::init()
{
    QObject::connect(socket.data(), SIGNAL(connected()), this, SLOT(connectedHandler()));
    QObject::connect(socket.data(), SIGNAL((error(QAbstractSocket::SocketError))),
                     SLOT(errorHandler(QAbstractSocket::SocketError)));
}

void WaitingForServerConnectionState::connectedHandler()
{
    disconnect(socket.data(), SIGNAL(connected()), this, SIGNAL(connectedHandler()));
    disconnect(socket.data(), SIGNAL((error(QAbstractSocket::SocketError))),
                     this, SLOT(errorHandler(QAbstractSocket::SocketError)));

    moveIntoState(QSharedPointer<ClientState>(getStateCollection()->getSearchGameState()));
    emit connectedWithServer();
}

void WaitingForServerConnectionState::errorHandler(QAbstractSocket::SocketError err)
{
    QString msg;
    switch (err)
    {
    case QAbstractSocket::RemoteHostClosedError:
        msg = "The remote host closed the connection";
        break;
    case QAbstractSocket::HostNotFoundError:
        msg = "The host was not found. Please check the host name and port settings";
        break;
    case QAbstractSocket::ConnectionRefusedError:
        msg = "The connection was refused by the peer";
        break;
    default:
        msg = "The following error occurred: " + err;
    }

    qDebug() << msg;
    emit error(msg);
}



