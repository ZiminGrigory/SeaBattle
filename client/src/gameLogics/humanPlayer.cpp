#include "humanPlayer.h"

HumanPlayer::HumanPlayer(const QSharedPointer<GameField>& plrField,
                         const QSharedPointer<GameField>& enmField,
                         const QSharedPointer<FieldView>& _fieldView,
                         QObject* parent):
    Player(plrField, enmField, parent),
    fieldView(_fieldView),
    fleetInst(NULL)
{
    connect(fieldView.data(), SIGNAL(attack(int)), this, SLOT(cellWasAttacked(int)));
}

void HumanPlayer::installFleet(const QSharedPointer<FleetInstaller> &fleetInstaller)
{
    fleetInst = fleetInstaller;
    connect(fieldView.data(), SIGNAL(placeShip(int,int)), fleetInst.data(), SLOT(shipPlaced(int,int)));
    connect(fieldView.data(), SIGNAL(deleteShip(int)), fleetInst.data(), SLOT(deleteShip(int)));
    connect(fleetInst.data(), SIGNAL(fleetInstalled()), this, SIGNAL(fleetInstalled()));
    /*
    connect(fleetInstaller, SIGNAL(shipPlacedSuccesfully(NameOfShips, int))
            , view, SLOT(changeCounter(NameOfShips,int)));
    */

}

void HumanPlayer::turn()
{

}

void HumanPlayer::cellWasAttacked(int id)
{
    attack(id);
}

