#ifndef SEARCHGAMESTATE_H
#define SEARCHGAMESTATE_H

#include "clientstate.h"

class SearchGameState : public ClientState
{
    Q_OBJECT
public:
    explicit SearchGameState(const QSharedPointer<Client> _client,
                                        QObject *parent = 0):
        ClientState(_client, parent)
    {
    }
    
public slots:
    /**
      * Reconnection with server.
      */
    bool connect(const QString & hostName, quint16 port);
    /**
      * Abort connection with server.
      */
    void abort();
    /**
      * It will be possible to send some queries to server in the future.
      *
      * @return always false.
      */
    inline bool send(const QByteArray& bytes);
};



inline bool SearchGameState::send(const QByteArray &bytes)
{
    return false;
}

#endif // SEARCHGAMESTATE_H
