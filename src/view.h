#pragma once

#include "mainwindow.h"
#include "cell.h"

class View : public QObject
{
	Q_OBJECT
public:
	View();
	~View();
	void paintMainWindowWithStartDialog();
	void paintCell(Players player, int id, Textures texture);

public slots:
	void changeTurn(int player);
	void changeCounter(NameOfShips ship, int difference);

signals:
	void deleteShip(int id);
	void createShip(int firstId, int secondId);
	void attackOnCell(int id);
	void readyToFight();

private slots:
	void deleteShipOnCell(int id);
	void cellWasAttacked(int id);
	void fieldHasReady();
	void createShipOnCells(int firstId, int secondId);
private:
	MainWindow *mMainWindow;
};
