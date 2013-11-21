#ifndef NETWORKGAMEMASTER_H
#define NETWORKGAMEMASTER_H

#include <QTimer>

#include "gameMaster.h"
#include "client.h"

class NetworkGameMaster : public GameMaster
{
    Q_OBJECT
public:
    NetworkGameMaster(const QSharedPointer<InterfaceBattleWidget>& _view,
                      const QSharedPointer<AudioPlayer> audioPlayer,
                      const QSharedPointer<Client> _client,
                      QObject* parent = 0);

private slots:
    void quitHandler();
    void enemyQuitHandler();
    void playerTimeoutHandler();
    void enemyTimeoutHandler();
private:
    void offerTurnHook();
    void informOpponentHook();

    QTimer turnTimer;
    QSharedPointer<Client> client;

    static const int playerTurnTimeout;
    static const int enemyTurnTimeout;
};

#endif // NETWORKGAMEMASTER_H
