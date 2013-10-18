#include "aiGameMaster.h"


AiGameMaster::AiGameMaster(AIType type,
                           const QSharedPointer<InterfaceBattleWidget> &_view,
                           const QSharedPointer<AudioPlayer> _audioPlayer,
                           QObject *parent) :
    GameMaster(_view, _audioPlayer, parent)
{
    if (type == EASY)
    {
        player = QSharedPointer<Player>(new HumanPlayer(playerField, enemyField, view));
        enemy = QSharedPointer<Player>(new AIPlayerSimple(enemyField, playerField));
    }
    else if (type == HARD)
    {
        player = QSharedPointer<Player>(new HumanPlayer(playerField, enemyField, view));
        // ai hard not implemented yet
        enemy = QSharedPointer<Player>(new AIPlayerSimple(enemyField, playerField));
    }

    initConnections();

    turnedPlayer = player;
    waitingPlayer = enemy;
}
