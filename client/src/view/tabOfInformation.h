#pragma once
#include <QWidget>
#include "types.h"
#include "InterfaceInfoTab.h"

namespace Ui {
class TabOfInformation;
}

class TabOfInformation : public InterfaceInfoTab
{
	Q_OBJECT
	
public:
	explicit TabOfInformation();
	~TabOfInformation();
	void clearItself();
	void changeCountOfShip(NameOfShips ship, int count);
	void playerReady(Players player);

public slots:
	void changeCounter(NameOfShips ship, int difference);

private slots:
	void pushButtonReadyToFight();

signals:
	void readyToFight();
	void needAutoSetting();

private:
	Ui::TabOfInformation *ui;
	bool isReady();
};
