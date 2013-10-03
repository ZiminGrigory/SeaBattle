#ifndef STATECOLLECTION_H
#define STATECOLLECTION_H

#include <QWeakPointer>
#include <QSharedPointer>

#include "noConnectionState.h"
#include "waitingForServerConnectionState.h"
#include "searchGameState.h"
#include "waitingForPlayerConnectionState.h"
#include "gameState.h"

class StateCollection
{
public:
    StateCollection(Client* _client):
        client(_client),
        noConnectionState(new NoConnectionState(_client)),
        waitingForServerConnectionState(new WaitingForServerConnectionState(_client)),
        searchGameState(QSharedPointer<ClientState>(new SearchGameState(_client))),
        waitingForPlayerConnectionState(QSharedPointer<ClientState>(new WaitingForPlayerConnectionState(_client)))
    {}

    inline QSharedPointer<ClientState> getNoConnectionState() const;
    inline QSharedPointer<ClientState> getWaitingForServerConnectionState() const;
    inline QSharedPointer<ClientState> getSearchGameState() const;
    inline QSharedPointer<ClientState> getWaitingForPlayerConnectionState() const;
    inline QSharedPointer<ClientState> getGameState() const;
private:
    Client* client;

    QSharedPointer<ClientState> noConnectionState;
    QSharedPointer<ClientState> waitingForServerConnectionState;
    QSharedPointer<ClientState> searchGameState;
    QSharedPointer<ClientState> waitingForPlayerConnectionState;
    QSharedPointer<ClientState> gameState;
};

inline QSharedPointer<ClientState> StateCollection::getNoConnectionState() const
{
    return noConnectionState;
}

inline QSharedPointer<ClientState> StateCollection::getWaitingForServerConnectionState() const
{
    return waitingForServerConnectionState;
}

inline QSharedPointer<ClientState> StateCollection::getSearchGameState() const
{
    return searchGameState;
}

inline QSharedPointer<ClientState> StateCollection::getWaitingForPlayerConnectionState() const
{
    return waitingForPlayerConnectionState;
}

inline QSharedPointer<ClientState> StateCollection::getGameState() const
{
    return gameState;
}


#endif // STATECOLLECTION_H
