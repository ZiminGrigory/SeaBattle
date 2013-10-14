#include "humanPlayer.h"

HumanPlayer::HumanPlayer(const QSharedPointer<GameField>& plrField
						, const QSharedPointer<GameField>& enmField
						, const QSharedPointer<InterfaceField>& _plrFieldView
						, const QSharedPointer<InterfaceField>& _enmFieldView
						, const QSharedPointer<InterfaceInfoTab> &_infoTab
						, const QSharedPointer<InterfaceChatAndStatus> &_chat
						, QObject* parent):
    Player(plrField, enmField, parent),
    plrFieldView(_plrFieldView),
    enmFieldView(_enmFieldView),
	infoTab(_infoTab),
	myTurn(false),
	mChat(_chat)
{
    connect(enmFieldView.data(), SIGNAL(attack(int)), this, SLOT(cellWasAttacked(int)));
	connect(infoTab.data(), SIGNAL(needAutoSetting()), this, SLOT(needAutoInstallFleet()));
    connect(mChat.data(), SIGNAL(getNewMessage(QString)), SIGNAL(chat(QString)));
}

void HumanPlayer::installFleet()
{
    setFleetHealth(myField->getFleet());
    connect(plrFieldView.data(), SIGNAL(placeShip(int,int)), myField.data(), SLOT(setShip(int,int)));
    connect(plrFieldView.data(), SIGNAL(deleteShip(int)), myField.data(), SLOT(deleteShip(int)));
    connect(infoTab.data(), SIGNAL(readyToFight()), myField.data(), SLOT(checkIsFleetReady()));

    connect(myField.data(), SIGNAL(fleetInstalled()), this, SLOT(reEmitFleetInstalled()));
    /*
    connect(fleetInstaller, SIGNAL(shipPlacedSuccesfully(NameOfShips, int))
            , view, SLOT(changeCounter(NameOfShips,int)));
    */

}

void HumanPlayer::turn()
{
    myTurn = true;
}

void HumanPlayer::cellWasAttacked(int id)
{
    if (myTurn && enemyField->attackable(id))
    {
        myTurn = false;
        attack(id);
    }
}

void HumanPlayer::reEmitFleetInstalled()
{
	emit fleetInstalled(this);
}

void HumanPlayer::needAutoInstallFleet()
{
    myField->removeInstalledFleet();
    autoInstallFleet();
}
