#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "clientstate.h"

class GameState : public ClientState
{
    Q_OBJECT
public:
    explicit GameState(Client* _client, QObject *parent = 0);
    
public slots:
    /**
      *
      */
    void abort();
    /**
      *
      */
    virtual void send(Protocol::RequestType type, const QByteArray& bytes)
        throw (Protocol::SendingForbidden, Protocol::RequestTypeForbidden);
protected:
    void init();
    void handleRecievedRequest(Protocol::RequestType type, const QByteArray &bytes);
};


#endif // GAMESTATE_H
