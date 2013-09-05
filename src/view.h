#pragma once
#include "mainwindow.h"

class View : public QObject
{
	Q_OBJECT
public:
	View();
	~View();
	void paintMainWindowWithStartDialog();
	void changeCounter(int ship, int count);
	void paintCell(int player, int id, int texture);

public slots:
	void changeTurn(int player);

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
