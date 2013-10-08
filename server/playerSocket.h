#ifndef PLAYERSOCKET_H
#define PLAYERSOCKET_H

#include <QSharedPointer>
#include <QTcpSocket>

#include "server.h"
#include "protocol.h"

class Server;

class PlayerSocket : public QObject
{
    Q_OBJECT
public:
    PlayerSocket(QSharedPointer<QTcpSocket> _socket, Server* _server);

    QString getHostName() const;
    quint16 getServerPort() const;
    bool seekGame() const;
    QString getKey() const;
public slots:
    void sendEnemyConnectionInf(const QSharedPointer<PlayerSocket>& enemy, bool serverFlag);
private slots:
    void readyReadHandler();
    void findGame(quint16 servPort);
private:
   Server* server;
   QSharedPointer<QTcpSocket> socket;
   quint16 serverPort;
   bool seekGameFlag;

   quint16 blockSize;
};

#endif // PLAYERSOCKET_H
