#pragma once
#include <QWidget>
#include "types.h"
namespace Ui {
class TabOfInformation;
}

class TabOfInformation : public QWidget
{
	Q_OBJECT
	
public:
	explicit TabOfInformation(QWidget *parent = 0);
	~TabOfInformation();
	void changeCountOfShip(NameOfShips ship, int count);

private slots:
	void pushButtonReadyToFight();

signals:
	void fieldIsReady();
	void needAutoSetting();

private:
	Ui::TabOfInformation *ui;
	bool isReady();
};
