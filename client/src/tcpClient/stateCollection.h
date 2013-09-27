#ifndef STATECOLLECTION_H
#define STATECOLLECTION_H

#include <QWeakPointer>
#include <QSharedPointer>

#include "noConnectionState.h"
#include "waitingForServerConnection.h"
#include "searchGameState.h"

class StateCollection
{
public:
    StateCollection(const QWeakPointer<Client>& _client):
        client(_client),
        noConnectionState(new NoConnectionState(_client)),
        waitingForServerConnectionState(new WaitingForServerConnectionState(_client)),
        searchGameState(QSharedPointer<ClientState>(new SearchGameState(_client)))
    {}

    inline QSharedPointer<ClientState> getNoConnectionState() const;
    inline QSharedPointer<ClientState> getWaitingForServerConnectionState() const;
    inline QSharedPointer<ClientState> getSearchGameState() const;
    inline QSharedPointer<ClientState> getWaitingForPlayerConnectionState() const;
private:
    QWeakPointer<Client> client;

    QSharedPointer<ClientState> noConnectionState;
    QSharedPointer<ClientState> waitingForServerConnectionState;
    QSharedPointer<ClientState> searchGameState;
    QSharedPointer<ClientState> waitingForPlayerConnectionState;
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

QSharedPointer<ClientState> StateCollection::getWaitingForPlayerConnectionState() const
{
    return waitingForPlayerConnectionState;
}


#endif // STATECOLLECTION_H
