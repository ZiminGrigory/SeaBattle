#pragma once
#include "gameField.h"
#include "ArrowAnalyzer.h"
#include "audioPlayer.h"

class ArrowAnalyzer;

class PlayerField : public GameField
{
Q_OBJECT
public:
    PlayerField(const QSharedPointer<InterfaceField> &fieldView,
                const QSharedPointer<InterfaceInfoTab>& infoTabView,
                const QSharedPointer<AudioPlayer>& audioPlayer);
//	virtual AttackStatus attack(int id);

    /**
     * Returns num of ships of each type
     * at 0 - count of BOAT_SCOUT at 3 - count of AEROCARRIER
     */
    QVector<int> getShipTypesNum();

    // dirty code :(
    void muteShipSetSound(bool mute);
protected:
	virtual void repaintCell(int row, int column, int partOfShip, int shipSize, bool orientation);
	virtual void handleResWOUNDED(int x, int y);
	virtual void handleResKILLED(int j, int i);
    virtual void setShipHook(PlacementStatus status);
private:
    ArrowAnalyzer mArrowAnalyzer;
    QSharedPointer<AudioPlayer> mAudioPlayer;
    bool mMute;
};

