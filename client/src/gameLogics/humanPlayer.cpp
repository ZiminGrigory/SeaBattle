#include "humanPlayer.h"

HumanPlayer::HumanPlayer(const QSharedPointer<PlayerField>& plrField
						, const QSharedPointer<GameField>& enmField
                        , const QSharedPointer<InterfaceBattleWidget>& battleWidget
                         /*
						, const QSharedPointer<InterfaceField>& _plrFieldView
						, const QSharedPointer<InterfaceField>& _enmFieldView
						, const QSharedPointer<InterfaceInfoTab> &_infoTab
						, const QSharedPointer<InterfaceChatAndStatus> &_chat
                                                 */
						, QObject* parent):
    Player(plrField, enmField, parent),
    plrFieldView(battleWidget->getPlayerFieldView()),
    enmFieldView(battleWidget->getEnemyFieldView()),
    infoTab(battleWidget->getInfoTabView()),
	myTurn(false),
    mChat(battleWidget->getChatAndStatus())
{
    connect(battleWidget.data(), SIGNAL(buttonBackPressed()), this, SIGNAL(quit()));
    connect(enmFieldView.data(), SIGNAL(attack(int)), this, SLOT(cellWasAttacked(int)));
    connect(this, SIGNAL(turnMade(int,AttackStatus)), this, SLOT(cellWasAttacked(int)));
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
    // another piece of dirty code :(
    GameField* tmp = myField.data();
    PlayerField* plrField = dynamic_cast<PlayerField*>(tmp);
    qDebug() << "plrField is null: " << (plrField == NULL);

    myField->removeInstalledFleet();
    plrField->muteShipSetSound(true);
    autoInstallFleet();
    plrField->muteShipSetSound(false);
}
