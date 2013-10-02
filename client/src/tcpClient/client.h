#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QByteArray>
#include <QTcpSocket>
#include <QSharedPointer>
#include <QWeakPointer>

#include "protocol.h"

class ClientState;
class StateCollection;

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
      * Emits after client was succesfully connected with enemy player.
      */
    void connectedWithPlayer();
    /**
      * Some error occurs during the process.
      */
    void error(const QString& message);
    /**
      * Emits when the client recieves bytes from server/client.
      */
    void received(Protocol::RequestType type, const QByteArray& bytes);
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
      * Sends request to the remote server/client if it possible at current moment.
      * Sending side should be confident in compliance bytes to the application protocol.
      *
      * @var type Type of the request
      / @var bytes bytes of the request (without service information like a size & type)
      * @return true if bytes was sending, false if it is impossible now.
      */
    void send(Protocol::RequestType type, const QByteArray& bytes)
        throw(Protocol::SendingForbidden, Protocol::RequestTypeForbidden);
    
private:
    /**
      *
      */
    void setState(const QSharedPointer<ClientState>& newState);

    QSharedPointer<ClientState> state;
    QSharedPointer<QTcpSocket> socket;
    QSharedPointer<StateCollection> stateCollection;
};

#endif // CLIENT_H
