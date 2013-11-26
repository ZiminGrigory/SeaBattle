#ifndef AIGAMEMASTER_H
#define AIGAMEMASTER_H

#include "gameMaster.h"

class AiGameMaster : public GameMaster
{
    Q_OBJECT
public:
    enum AIType
    {
        EASY,
        HARD
    };

    AiGameMaster(AIType type,
                 const QSharedPointer<InterfaceBattleWidget>& _view,
                 const QSharedPointer<AudioPlayer> _audioPlayer,
                 QObject* parent = 0);

protected:
	void playerReadyToBattleHook();
};

#endif // AIGAMEMASTER_H
