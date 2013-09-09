#include "humanPlayer.h"

HumanPlayer::HumanPlayer(View* _view, QObject *parent):
    Player(_view)
{
    myField.setPlr(YOU);
    enemyField.setPlr(ENEMY);

	connect(view, SIGNAL(attackOnCell(int)), this, SLOT(cellWasAttacked(int)));
	connect(view, SIGNAL(deleteShip(int)), this, SLOT(deleteShip(int)));
}

void HumanPlayer::installFleet()
{
    connect(view, SIGNAL(createShip(int,int)), fleetInstaller.data(), SLOT(shipPlaced(int,int)));
	connect(fleetInstaller.data(), SIGNAL(shipPlacedSuccesfully(NameOfShips, int))
			, view, SLOT(changeCounter(NameOfShips,int)));
	connect(view, SIGNAL(deleteShip(int)), fleetInstaller.data(), SLOT(deleteShip(int)));
}

void HumanPlayer::turn()
{

}

void HumanPlayer::cellWasAttacked(int id)
{
	emit turnMade(id);
}

void HumanPlayer::deleteShip(int id)
{
}

