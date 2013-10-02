#ifndef NOCONNECTIONSTATE_H
#define NOCONNECTIONSTATE_H

#include <QTimer>

#include "clientstate.h"

class NoConnectionState : public ClientState
{
    Q_OBJECT
public:
    explicit NoConnectionState(const QWeakPointer<Client>& _client, QObject* parent = 0);
        
public slots:
    /**
      * Try to set connection with server and move to the Waiting for server connection state.
      * If connection fails or waiting times out object will emit error signal.
      */
    void connect(const QString & hostName, quint16 port) throw(Protocol::AlreadyConnected);
private slots:
    void connectedHandler();
    void connectionTimeoutHandler();
private:
    QTimer timer;
    static const int connectionTimeout;
};

#endif // NOCONNECTIONSTATE_H
