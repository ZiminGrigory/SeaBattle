#include "field.h"
#include "ui_field.h"

Field::Field(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::Field)
{
	ui->setupUi(this);
	this->setMaximumSize(sizeOfCube + 40, sizeOfCube + 40);
	this->setMinimumSize(sizeOfCube + 40, sizeOfCube + 40);
	ui->graphicsView->setMaximumSize(sizeOfCube + 10, sizeOfCube+ 10);
	ui->graphicsView->setMinimumSize(sizeOfCube + 10, sizeOfCube + 10);
	mScene = new QGraphicsScene;
	mScene->setSceneRect(0, 0, sizeOfCube, sizeOfCube);
	int x = sizeOfCube / 10;
	int y = sizeOfCube / 10;
	for (int i = 1; i <= 10; i++){
		for (int j = 1; j <= 10; j++){
			Cell *item = new Cell(x, y);
			item->setData((i - 1) * 10 + j, QVariant());
			item->setPos((j - 1) * x, (i - 1) * y);
			mScene->addItem(item);
		}
	}
	ui->graphicsView->setScene(mScene);
}

Field::~Field()
{
	delete ui;
	mScene->clear();
	delete mScene;
}
