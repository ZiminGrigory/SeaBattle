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
    explicit ClientState(Client* _client, QObject *parent = 0);

    virtual ~ClientState() {}
    
signals:
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
      * Connection with host (if it possible in current state).
      *
      * Base implementation throws AlredyConnected() exception.
      */
    virtual inline void connect(const QString & hostName, quint16 port) throw(Protocol::AlreadyConnected);
    /**
      * Abort all current connections.
      *
      * Base implementation just do nothing.
      */
    virtual inline void abort();
    /**
      * Sends bytes to the remote server/client if it possible at current moment.
      * Sending side should be confident in compliance bytes to the application protocol.
      *
      * Heirs of the class should verify possibility of sending and request type.
      *
      * Base implementation throws SendingForbidden exception.
      */
    virtual void send(Protocol::RequestType type, const QByteArray& bytes)
        throw (Protocol::SendingForbidden, Protocol::RequestTypeForbidden);
protected:
    /**
      * Sends request to the remote server/client.
      */
    void writeToSocket(Protocol::RequestType type, const QByteArray& bytes);
    /**
      * This slot is called when client recieve some request from remote server/client.
      * It should handle request and do something (for example emit recieved() signal if the request allowed).
      *
      * Base implementation jest do nothing.
      */
    virtual inline void handleRecievedRequest(Protocol::RequestType type, const QByteArray& bytes);
    /**
      * This method calls after client moves into state and before all other actions of this state will be execute.
      *
      * Base implementation just do nothing.
      */
    virtual inline void init();
    /**
      *
      */
    QSharedPointer<StateCollection> getStateCollection() const;
    /**
      *
      */
    void moveIntoState(const QSharedPointer<ClientState>& newState);

    Client* client;
    QSharedPointer<QTcpSocket> socket;
private:
    /**
      * This slot connected to readeRead signal of socket.
      * It recieves request from socket and calls handleRecievedRequest() method of concrete subclass to handle request.
      */
    void readyReadHandler();

    quint16 blockSize;
};

inline void ClientState::connect(const QString &hostName, quint16 port) throw (Protocol::AlreadyConnected)
{
    Q_UNUSED(hostName);
    Q_UNUSED(port);
    throw Protocol::AlreadyConnected();
}

inline void ClientState::abort()
{
}

inline void ClientState::send(Protocol::RequestType type, const QByteArray& bytes)
    throw(Protocol::SendingForbidden, Protocol::RequestTypeForbidden)
{
    Q_UNUSED(type);
    Q_UNUSED(bytes);
    throw Protocol::SendingForbidden();
}

inline void ClientState::handleRecievedRequest(Protocol::RequestType type, const QByteArray &bytes)
{
    Q_UNUSED(type);
    Q_UNUSED(bytes);
}

inline void ClientState::init()
{
}

#endif // CLIENTSTATE_H
