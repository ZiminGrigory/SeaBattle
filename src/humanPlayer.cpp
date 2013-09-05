#include "humanPlayer.h"

HumanPlayer::HumanPlayer(View *view, QObject *parent): view(view)
{
	connect(view, SIGNAL(createShip(int,int)), fleetInstaller.data(), SLOT(shipPlaced(int,int)));
	connect(view, SIGNAL(attackOnCell(int)), this, SLOT(cellWasAttacked(int)));
	connect(view, SIGNAL(deleteShip(int)), this, SLOT(deleteShip(int)));
}

void HumanPlayer::installFleet()
{

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

