#include "humanPlayer.h"

HumanPlayer::HumanPlayer(const QSharedPointer<GameField>& plrField,
                         const QSharedPointer<GameField>& enmField,
                         const QSharedPointer<Field>& _fieldView,
                         QObject* parent):
    Player(plrField, enmField, parent),
    fieldView(_fieldView)
{
    connect(fieldView, SIGNAL(attackOnCell(int)), this, SLOT(cellWasAttacked(int)));
}

void HumanPlayer::installFleet(const FleetInstaller& fleetInstaller)
{


    connect(fieldView, SIGNAL(createShip(int,int)), &fleetInstaller, SLOT(shipPlaced(int,int)));
    connect(fieldView, SIGNAL(deleteShip(int)), &fleetInstaller, SLOT(deleteShip(int)));
    connect(&fleetInstaller, SIGNAL(fleeInstalled()), this, SIGNAL(fleetInstalled()));
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

