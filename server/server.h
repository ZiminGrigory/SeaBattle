#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include <QQueue>
#include <QSharedPointer>

#include "protocol.h"
#include "playerSocket.h"

class PlayerSocket;

class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject* parent = 0);

signals:

public slots:
    void findGame(PlayerSocket* newPlayer);

private slots:
    void newConnectionHandler();
private:
    QTcpServer server;

    QMap<QString, QSharedPointer<PlayerSocket> > players;
    QQueue< QSharedPointer<PlayerSocket> > playersQueue;
};

#endif // SERVER_H
