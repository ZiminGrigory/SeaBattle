#ifndef NOCONNECTIONSTATE_H
#define NOCONNECTIONSTATE_H

#include "clientstate.h"

class NoConnectionState : public ClientState
{
    Q_OBJECT
public:
    explicit NoConnectionState(const QSharedPointer<Client>& _client, QObject* parent = 0):
        ClientState(_client, parent)
    {}
        
public slots:
    /**
      * Try to set connection with server and move to the Waiting for server connection state.
      * If connection fails or waiting times out object will emit error signal.
      */
    bool connect(const QString & hostName, quint16 port);
    /**
      * Do nothing.
      */
    void abort();
    /**
      * Throw
      */
    bool send(const QByteArray& bytes);
};

#endif // NOCONNECTIONSTATE_H
