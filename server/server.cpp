#include <QTcpServer>
#include <QTcpSocket>
#include <QByteArray>
#include <QDataStream>
#include <QDebug>
#include "../client/src/gameLogics/types.h"
#include "server.h"
#include "playerSocket.h"

Server::Server(QObject* parent) :
    QObject(parent)
{
    connect(&server, SIGNAL(newConnection()), SLOT(newConnectionHandler()));
	quint16 port = Protocol::ServerPort;

	if (settings.contains(SettingsKey::PORT_KEY)){
		port = quint16(settings.value(SettingsKey::PORT_KEY).toInt());
	}
	bool res = server.listen(QHostAddress::Any, port);
    qDebug() << "is listening = " << res;
}

void Server::newConnectionHandler()
{
    qDebug() << "New connection!";

    QSharedPointer<PlayerSocket> newPlayer(new PlayerSocket(QSharedPointer<QTcpSocket>(server.nextPendingConnection()),
                                                            this));
    players.insert(newPlayer->getKey(), newPlayer);
}

void Server::findGame(PlayerSocket* _newPlayer)
{
    QSharedPointer<PlayerSocket> newPlayer = players.take(_newPlayer->getKey());
    if ((playersQueue.isEmpty()))
    {
        qDebug() << "No avilable players, add player to the queue";

        playersQueue.enqueue(newPlayer);
        return;
    }
    else
    {
        QSharedPointer<PlayerSocket> player = playersQueue.dequeue();

        qDebug() << "Find the pair of players. Let's connect them!";

        player->sendEnemyConnectionInf(newPlayer, true);
        newPlayer->sendEnemyConnectionInf(player, false);
    }
}
