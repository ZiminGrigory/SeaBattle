#include "field.h"
#include "ui_field.h"

Field::Field(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::Field)
{
	ui->setupUi(this);
	mScene = new QGraphicsScene;
	Cell *item = new Cell;
	mScene->addItem(item);
	ui->graphicsView->setScene(mScene);
}

Field::~Field()
{
	delete ui;
	mScene->clear();
	delete mScene;
}
