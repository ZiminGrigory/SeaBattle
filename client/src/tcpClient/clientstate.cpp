#include "client.h"
#include "clientstate.h"
#include "stateCollection.h"

ClientState::ClientState(const QWeakPointer<Client>& _client,
                             QObject *parent):
    QObject(parent),
    client(_client),
    socket(_client.toStrongRef()->socket),
    blockSize(0)
{}

void ClientState::moveIntoState(const QSharedPointer<ClientState> &newState)
{
    client.toStrongRef()->setState(newState);
    newState->init();
}

QSharedPointer<StateCollection> ClientState::getStateCollection() const
{
    return client.toStrongRef()->stateCollection;
}

void ClientState::readyReadHandler()
{
    QDataStream in(socket.data());
    in.setVersion(Protocol::QDataStreamVersion);

    if (blockSize == 0)
    {
        // first two bytes are the size of the rest message
        // so wait until we recive the size of message
        if (socket->bytesAvailable() < (int)sizeof(quint16))
            return;
        in >> blockSize;
    }

    if (socket->bytesAvailable() < blockSize)
        return;

    quint8 _type;
    Protocol::RequestType type;
    in >> _type;
    type = Protocol::RequestType(_type);
    QByteArray bytes = socket->read(blockSize - 3);

    blockSize = 0;

    handleRecievedRequest(type, bytes);
}

void ClientState::writeToSocket(Protocol::RequestType type, const QByteArray &bytes)
{
    QByteArray byteArray;
    QDataStream out(&byteArray, QIODevice::WriteOnly);
    out.setVersion(Protocol::QDataStreamVersion);
    // send size of request, type and finally information
    out << quint16(3 + bytes.size()) << quint8(type);
    byteArray.append(bytes);
    socket->write(byteArray);
}
