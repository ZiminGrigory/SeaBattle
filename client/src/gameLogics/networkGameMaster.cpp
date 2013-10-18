#include "networkGameMaster.h"


const int NetworkGameMaster::playerTurnTimeout = 30 * 1000;
const int NetworkGameMaster::enemyTurnTimeout = NetworkGameMaster::playerTurnTimeout + 5 * 1000;

NetworkGameMaster::NetworkGameMaster(const QSharedPointer<InterfaceBattleWidget> &_view,
                                     const QSharedPointer<AudioPlayer> audioPlayer,
                                     const QSharedPointer<Client> _client,
                                     QObject *parent) :
    GameMaster(_view, audioPlayer, parent),
    client(_client)
{
    player = QSharedPointer<Player>(new NetworkHumanPlayer(playerField, enemyField, view, client));
    enemy = QSharedPointer<Player>(new RemotePlayer(enemyField
                                                    , playerField
                                                    , client));
    initConnections();

    turnTimer.setSingleShot(true);

    connect(enemy.data(), SIGNAL(quit()), SLOT(enemyQuitHandler()));
    connect(view.data(), SIGNAL(gameBreakDialogOkPressed()), this, SIGNAL(gameInterrupted()));
}

void NetworkGameMaster::quitHandler()
{
    client->send(Protocol::PLAYER_QUIT, QByteArray());
    emit gameInterrupted();
}

void NetworkGameMaster::enemyQuitHandler()
{
    view->showGameBreakDialog("Враг покинул игру");
}

void NetworkGameMaster::playerTimeoutHandler()
{
    disconnect(&turnTimer, SIGNAL(timeout()), 0, 0);
    mChat->gameMasterMessage("Время на ход истекло, выбор случайной клетки");
    player->randomTurn();
}

void NetworkGameMaster::enemyTimeoutHandler()
{
    disconnect(&turnTimer, SIGNAL(timeout()), 0, 0);
    view->showGameBreakDialog("Противник не отвечает");
}

void NetworkGameMaster::offerTurnHook()
{
    if (turnedPlayer == player)
    {
        connect(&turnTimer, SIGNAL(timeout()), this, SLOT(playerTimeoutHandler()));
        turnTimer.start(playerTurnTimeout);
    }
    else if (turnedPlayer == enemy)
    {
        connect(&turnTimer, SIGNAL(timeout()), this, SLOT(enemyTimeoutHandler()));
        turnTimer.start(enemyTurnTimeout);
    }
    view->setTime(playerTurnTimeout / 1000);
}

void NetworkGameMaster::informOpponentHook()
{
    turnTimer.stop();
    disconnect(&turnTimer, SIGNAL(timeout()), 0, 0);
}

