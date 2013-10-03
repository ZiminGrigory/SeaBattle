#include <QTcpServer>
#include <QTcpSocket>
#include <QByteArray>
#include <QDataStream>
#include <QDebug>

#include "server.h"

Server::Server(QObject* parent) :
    QObject(parent)
{
    connect(&server, SIGNAL(newConnection()), SLOT(newConnectionHandler()));
    bool res = server.listen(QHostAddress::Any, Protocol::ServerPort);
    qDebug() << "is listening = " << res;
}

void Server::newConnectionHandler()
{
    qDebug() << "New connection!";

    QSharedPointer<QTcpSocket> newSocket(server.nextPendingConnection());
    if (clients.isEmpty())
    {
        clients.enqueue(newSocket);
    }
    else
    {
        QSharedPointer<QTcpSocket> socket(NULL);
        do
        {
            socket = clients.dequeue();
        } while ((socket->state() != QAbstractSocket::ConnectedState) || clients.isEmpty());

        if (clients.isEmpty())
        {
            clients.enqueue(newSocket);
            return;
        }

        sendEnemyConnectionInf(newSocket, socket->peerName(), socket->peerPort());
        sendEnemyConnectionInf(socket, newSocket->peerName(), newSocket->peerPort());
    }
}

void Server::sendEnemyConnectionInf(const QSharedPointer<QTcpSocket>& socket, const QString& hostName, quint16 port)
{
    QByteArray bytes;
    QDataStream request(&bytes, QIODevice::ReadOnly);
    request.setVersion(Protocol::QDataStreamVersion);

    request << quint16(0) << quint8(Protocol::GAME_FOUND) << port << hostName;
    request.device()->seek(0);
    request << quint16(bytes.size());

    socket->write(bytes);
}
