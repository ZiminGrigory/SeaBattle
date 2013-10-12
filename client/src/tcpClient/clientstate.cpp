#include "client.h"
#include "clientstate.h"
#include "stateCollection.h"

ClientState::ClientState(Client *_client,
                             QObject *parent):
    QObject(parent),
    client(_client),
    blockSize(0)
{
    QObject::connect(this, SIGNAL(error(QString)), client, SIGNAL(error(QString)));
    QObject::connect(this, SIGNAL(received(Protocol::RequestType,QByteArray)),
            client, SIGNAL(received(Protocol::RequestType,QByteArray)));
}

void ClientState::moveIntoState(const QSharedPointer<ClientState> &newState)
{
    client->setState(newState);
    newState->init();
}

QSharedPointer<StateCollection> ClientState::getStateCollection() const
{
    return client->stateCollection;
}

void ClientState::readyReadHandler()
{
    QAbstractSocket::SocketState test = getSocket()->state();

    QDataStream in(getSocket().data());
    in.setVersion(Protocol::QDataStreamVersion);

    if (blockSize == 0)
    {
        // first two bytes are the size of the rest message
        // so wait until we recive the size of message
        if (getSocket()->bytesAvailable() < (int)sizeof(quint16))
            return;
        in >> blockSize;
    }

    if (getSocket()->bytesAvailable() < blockSize - 2)
        return;

    quint8 _type;
    Protocol::RequestType type;
    in >> _type;
    type = Protocol::RequestType(_type);
    QByteArray bytes = getSocket()->readAll();

    blockSize = 0;

    handleRecievedRequest(type, bytes);
}

void ClientState::writeToSocket(Protocol::RequestType type, const QByteArray &bytes)
{
    QAbstractSocket::SocketState test = getSocket()->state();

    QByteArray byteArray;
    QDataStream out(&byteArray, QIODevice::WriteOnly);
    out.setVersion(Protocol::QDataStreamVersion);
    // send size of request, type and finally information
    out << quint16(3 + bytes.size()) << quint8(type);
    byteArray.append(bytes);
    getSocket()->write(byteArray);
}


QSharedPointer<QTcpSocket> ClientState::getSocket()
{
    return client->socket;
}

void ClientState::setSocket(const QSharedPointer<QTcpSocket>& socket)
{
    client->socket = socket;
}
