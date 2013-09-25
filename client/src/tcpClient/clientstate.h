#ifndef CLIENTSTATE_H
#define CLIENTSTATE_H

#include <QObject>
#include <QWeakPointer>
#include "client.h"

/**
  * This class inherits by all implementation of clien state.
  */
class ClientState : public QObject
{
    Q_OBJECT
public:
    explicit ClientState(const QSharedPointer<Client>& _client, QObject *parent);

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
    virtual bool connect(const QString & hostName, quint16 port) = 0;
    /**
      * Abort all current connections.
      */
    virtual void abort() = 0;
    /**
      * Sends bytes to the remote server/client if it possible at current moment.
      * Sending side should be confident in compliance bytes to the application protocol.
      *
      * @return true if bytes was sending, false if it is impossible now.
      */
    virtual bool send(const QByteArray& bytes) = 0;
protected:
    /**
      *
      */
    void moveIntoState(const QSharedPointer<ClientState>& newState);

    QWeakPointer<Client> client;
    QSharedPointer<QTcpSocket> socket;
};

#endif // CLIENTSTATE_H
