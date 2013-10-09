#include "playerSocket.h"
#include "server.h"

PlayerSocket::PlayerSocket(QSharedPointer<QTcpSocket> _socket, Server* _server):
    server(_server),
    socket(_socket),
    serverPort(0),
    seekGameFlag(false)
{
	blockSize = 0;
    connect(socket.data(), SIGNAL(readyRead()), SLOT(readyReadHandler()));
}

QString PlayerSocket::getHostName() const
{
    return socket->peerAddress().toString();
}

quint16 PlayerSocket::getServerPort() const
{
    if (seekGameFlag)
    {
        return serverPort;
    }
    else
    {
        return 0;
    }
}

bool PlayerSocket::seekGame() const
{
    return seekGameFlag;
}

QString PlayerSocket::getKey() const
{
    return getHostName() + QString().setNum(socket->peerPort());
}

void PlayerSocket::sendEnemyConnectionInf(const QSharedPointer<PlayerSocket>& enemy, bool serverFlag)
{
    QByteArray bytes;
    QDataStream request(&bytes, QIODevice::ReadWrite);
    request.setVersion(Protocol::QDataStreamVersion);

    request << quint16(0) << quint8(Protocol::GAME_FOUND) << serverFlag;
    request << enemy->getServerPort() << enemy->getHostName().toLatin1().data();
    request.device()->seek(0);
    request << quint16(bytes.size());

    socket->write(bytes);
    socket->flush();
}

void PlayerSocket::readyReadHandler()
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

    if (socket->bytesAvailable() < blockSize - 2)
        return;

    quint8 _type;
    Protocol::RequestType type;
    in >> _type;
    type = Protocol::RequestType(_type);

    blockSize = 0;

    if (type == Protocol::SEARCH_GAME)
    {
        quint16 servPort;
        in >> servPort;
        findGame(servPort);
    }
}

void PlayerSocket::findGame(quint16 servPort)
{
    seekGameFlag = true;
    serverPort = servPort;
    server->findGame(this);
}


