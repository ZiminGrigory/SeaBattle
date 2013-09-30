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
    void abort();
protected:
    /**
      *
      */
    void init();
private slots:
    void connectedHandler();
};


#endif // WAITINGFORPLAYERCONNECTIONSTATE_H
