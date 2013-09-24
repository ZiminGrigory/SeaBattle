#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QByteArray>
#include <QTcpSocket>
#include <QSharedPointer>

#include "clientstate.h"

class ClientState;

/**
  * Class of Client object which is used to connect to server or another client.
  */
class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject *parent = 0);
    
    friend class ClientState;
signals:
    /**
      * Emits after client was succesfully connected with server.
      */
    void connectedWithServer();
    /**
      * Some error occurs during the process.
      */
    void error(const QString& message);
    /**
      * Emits when the client recieves bytes from server/client.
      */
    void received(const QByteArray& bytes);
public slots:
    /**
      * Sets connection with server.
      */
    void connectToServer();
    /**
      * Abort all current connections.
      */
    void abort();
    /**
      * Sends bytes to the remote server/client if it possible at current moment.
      * Sending side should be confident in compliance bytes to the application protocol.
      *
      * @return true if bytes was sending, false if it is impossible now.
      */
    bool send(const QByteArray& bytes);
    
private:
    QSharedPointer<ClientState> state;
    QSharedPointer<QTcpSocket> socket;


};

#endif // CLIENT_H
