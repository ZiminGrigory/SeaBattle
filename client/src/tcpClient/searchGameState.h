#ifndef SEARCHGAMESTATE_H
#define SEARCHGAMESTATE_H

#include <QTimer>
#include <QTcpServer>

#include "clientstate.h"
#include "protocol.h"

class SearchGameState : public ClientState
{
    Q_OBJECT
public:
    explicit SearchGameState(Client* _client, QObject* parent = 0);
    
public slots:
    /**
      *
      */
    void connect(const QString & hostName, quint16 port) throw(Protocol::AlreadyConnected);
    /**
      * Abort connection with server.
      */
    void abort();
signals:
    /**
     * Emits when this client is waiting for connection from another (using tmpServer) and getting the new one.
     */
    void connected();
protected:
    /**
      * Handle two types of requests - check state & game found.
      * For CHECK_STATE request object sends response SEEKING_GAME to the server.
      * For GAME_FOUND request object moved to waiting for player state.
      */
    void handleRecievedRequest(Protocol::RequestType type, const QByteArray &bytes);
    /**
      * Send to server request of game searching.
      */
    void init();
private slots:
    /**
     * This slot runs when the socket of this client connects to the remote client app.
     */
    void connectedHandler();
    /**
     * This slot runs when the remote socket connects to the temprorary server on this client app.
     */
    void connectionHandler();
    void connectionTimeoutHandler();
private:
    QTcpServer tmpServer;
    QTimer timer;
    bool connectionLock;

    static const int connectionTimeout;
};

#endif // SEARCHGAMESTATE_H
