#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include <QQueue>
#include <QSharedPointer>

#include "protocol.h"

class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject* parent = 0);

signals:

public slots:

private slots:
    void newConnectionHandler();
private:
    void sendEnemyConnectionInf(const QSharedPointer<QTcpSocket>& socket, const QString& hostName, quint16 port);

    QTcpServer server;
    QQueue< QSharedPointer<QTcpSocket> > clients;
};

#endif // SERVER_H
