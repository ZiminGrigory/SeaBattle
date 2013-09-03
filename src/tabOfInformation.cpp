#include "tabOfInformation.h"
#include "ui_tabOfInformation.h"

TabOfInformation::TabOfInformation(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::TabOfInformation)
{
	ui->setupUi(this);
	this->setMaximumSize(sizeOfCube + 40, sizeOfCube + 40);
	this->setMinimumSize(sizeOfCube + 40, sizeOfCube + 40);
}

TabOfInformation::~TabOfInformation()
{
	delete ui;
}
