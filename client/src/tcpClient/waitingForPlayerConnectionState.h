#ifndef WAITINGFORPLAYERCONNECTIONSTATE_H
#define WAITINGFORPLAYERCONNECTIONSTATE_H

#include "protocol.h"
#include "clientstate.h"

class WaitingForPlayerConnectionState : public ClientState
{
    Q_OBJECT
public:
    explicit WaitingForPlayerConnectionState(const QWeakPointer<Client> _client, QObject *parent = 0);
signals:
    void connectedWithPlayer();
public slots:
    /**
      *
      */
    void connect(const QString& hostName, quint16 port) throw(Protocol::AlreadyConnected);
    /**
      *
      */
    void abort();
    /**
      *
      */
    inline void send(Protocol::RequestType type, const QByteArray& bytes)
        throw(Protocol::SendingForbidden, Protocol::RequestTypeForbidden);
protected:
    /**
      *
      */
    void init();
private slots:
    void connectedHandler();
};

inline void WaitingForPlayerConnectionState::send(Protocol::RequestType type, const QByteArray& bytes)
    throw(Protocol::SendingForbidden, Protocol::RequestTypeForbidden)
{
    Q_UNUSED(type);
    Q_UNUSED(bytes);
    throw Protocol::SendingForbidden();
}


#endif // WAITINGFORPLAYERCONNECTIONSTATE_H
