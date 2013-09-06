#include "tabOfInformation.h"
#include "ui_tabOfInformation.h"

TabOfInformation::TabOfInformation(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::TabOfInformation)
{
	ui->setupUi(this);
	this->setMaximumSize(sizeOfCube + 40, sizeOfCube + 40);
	this->setMinimumSize(sizeOfCube + 40, sizeOfCube + 40);
	connect(ui->toolButton, SIGNAL(clicked()), this, SLOT(pushButtonReadyToFight()));
}

TabOfInformation::~TabOfInformation()
{
	delete ui;
}

void TabOfInformation::changeCountOfShip(NameOfShips ship, int count)
{
	switch (ship){
	case AEROCARRIER:{
		ui->lcdNumber_4->display(ui->lcdNumber_4->value() + count);
		break;
	}
	case CRUISER:{
		ui->lcdNumber_3->display(ui->lcdNumber_3->value() + count);
		break;
	}
	case DESTROYER:{
		ui->lcdNumber_2->display(ui->lcdNumber_2->value() + count);
		break;
	}
	case BOAT_SCOUT:{
		ui->lcdNumber->display(ui->lcdNumber->value() + count);
		break;
	}
	}
}


void TabOfInformation::pushButtonReadyToFight()
{
	if (isReady()){
		emit fieldIsReady();
	}
}

bool TabOfInformation::isReady()
{
	return (ui->lcdNumber->value() == 0.0) && (ui->lcdNumber_2->value() == 0.0)
			&& (ui->lcdNumber_3->value() == 0.0) && (ui->lcdNumber_4->value() == 0.0);
}
