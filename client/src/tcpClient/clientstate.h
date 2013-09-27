#ifndef CLIENTSTATE_H
#define CLIENTSTATE_H

#include <QObject>
#include <QWeakPointer>
#include <QTcpSocket>

//#include "client.h"
#include "protocol.h"

class Client;
class StateCollection;

/**
  * This class inherits by all implementation of clien state.
  */
class ClientState : public QObject
{
    Q_OBJECT
public:
    explicit ClientState(const QWeakPointer<Client>& _client, QObject *parent);

    virtual ~ClientState() {}
    
signals:
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
      * Connection with host (if it possible in current state).
      *
      * @return true if connection is allowed, false otherwise.
      */
    virtual void connect(const QString & hostName, quint16 port) throw(Protocol::AlreadyConnected) = 0;
    /**
      * Abort all current connections.
      */
    virtual void abort() = 0;
    /**
      * Sends bytes to the remote server/client if it possible at current moment.
      * Sending side should be confident in compliance bytes to the application protocol.
      *
      * Base implementation just sends request to server.
      * Heirs of the class should verify possibility of sending and request type.
      */
    virtual void send(Protocol::RequestType type, const QByteArray& bytes)
        throw (Protocol::SendingForbidden, Protocol::RequestTypeForbidden);
protected slots:
    /**
      * This slot could connected to readeRead signal of socket.
      * It recieves request from socket and calls handleRecievedRequest() method of concrete subclass to handle request.
      */
    void readyReadHandler();
protected:
    /**
      *
      */
    virtual void handleRecievedRequest(Protocol::RequestType type, const QByteArray& bytes);
    /**
      * This method calls after client moves into state and before all other actions of this state will be execute.
      */
    virtual void init();
    /**
      *
      */
    QSharedPointer<StateCollection> getStateCollection() const;
    /**
      *
      */
    void moveIntoState(const QSharedPointer<ClientState>& newState);

    QWeakPointer<Client> client;
    QSharedPointer<QTcpSocket> socket;
    quint16 blockSize;
};

#endif // CLIENTSTATE_H
