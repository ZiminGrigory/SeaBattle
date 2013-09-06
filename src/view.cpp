#include "view.h"
#include <QDebug>
View::View()
{
}

View::~View()
{
	delete mMainWindow;
}

void View::paintMainWindowWithStartDialog()
{
	mMainWindow = new MainWindow;
	mMainWindow->show();
	connect(mMainWindow, SIGNAL(deleteShip(int)), this, SLOT(deleteShipOnCell(int)));
	connect(mMainWindow, SIGNAL(attackCell(int)), this, SLOT(cellWasAttacked(int)));
	connect(mMainWindow, SIGNAL(createShip(int,int)), this, SLOT(createShipOnCells(int,int)));
	connect(mMainWindow, SIGNAL(readyToFight()), this, SLOT(fieldHasReady()));
	mMainWindow->paintStartDialog();
}

void View::changeCounter(NameOfShips ship, int difference)
{
	mMainWindow->changeCounter(ship, difference);
}


void View::changeTurn(int player)
{
	mMainWindow->changeTurn(player);
}


void View::paintCell(Players player, int id, Textures texture)
{
    if (player == NONE)
        return;
    mMainWindow->paintCell(player, id, texture);
}

void View::createShipOnCells(int firstId, int secondId)
{
	qDebug() << firstId << ' ' << secondId;
	emit createShip(firstId, secondId);
}


void View::fieldHasReady()
{
	qDebug() << "ready";
	emit readyToFight();
}


void View::cellWasAttacked(int id)
{
	qDebug() << id;
	emit attackOnCell(id);
}


void View::deleteShipOnCell(int id)
{
	qDebug() << id;
	emit deleteShip(id);
}
