#include "client.h"
#include "stateCollection.h"
#include "waitingForPlayerConnectionState.h"

WaitingForPlayerConnectionState::WaitingForPlayerConnectionState(Client* _client, QObject* parent):
    ClientState(_client, parent)
{
    QObject::connect(this, SIGNAL(connectedWithPlayer()), client, SIGNAL(connectedWithPlayer()));
}

void WaitingForPlayerConnectionState::connect(const QString &hostName, quint16 port) throw(Protocol::AlreadyConnected)
{
    Q_UNUSED(hostName);
    Q_UNUSED(port);
}

void WaitingForPlayerConnectionState::abort()
{
    disconnect(socket.data(), SIGNAL(connected()), this, SIGNAL(connectedHandler()));
    socket->abort();
    moveIntoState(getStateCollection()->getNoConnectionState());
}


void WaitingForPlayerConnectionState::init()
{
    QObject::connect(socket.data(), SIGNAL(connected()), this, SLOT(connectedHandler()));
    QObject::connect(socket.data(), SIGNAL((error(QAbstractSocket::SocketError))),
                     this, SLOT(errorHandler(QAbstractSocket::SocketError)));
}

void WaitingForPlayerConnectionState::connectedHandler()
{
    disconnect(socket.data(), SIGNAL(connected()), this, SIGNAL(connectedHandler()));
    disconnect(socket.data(), SIGNAL((error(QAbstractSocket::SocketError))),
                     this, SLOT(errorHandler(QAbstractSocket::SocketError)));
    moveIntoState(getStateCollection()->getGameState());
    emit connectedWithPlayer();
}

void WaitingForPlayerConnectionState::errorHandler(QAbstractSocket::SocketError err)
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
