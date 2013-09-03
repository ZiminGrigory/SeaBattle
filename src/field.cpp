#include "field.h"
#include "ui_field.h"
#include <QDebug>

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
	field.resize(100);
	for (int i = 1; i <= 10; i++){
		for (int j = 1; j <= 10; j++){
			Cell *item = new Cell(x, y);
			field[(i - 1) * 10 + j - 1] = item;
			item->setData(x, (i - 1) * 10 + j - 1);
			item->setPos((j - 1) * x, (i - 1) * y);
			connect(item, SIGNAL(attacked(Cell*)), this, SLOT(cellWasAttacked(Cell*)));\
			connect(item, SIGNAL(getCoordinate(QPointF,QPointF)), this, SLOT(getCoordinate(QPointF,QPointF)));
			mScene->addItem(item);
		}
	}
	ui->graphicsView->setScene(mScene);
}

QVector<Cell *> Field::getField()
{
	return field;
}

Field::~Field()
{
	delete ui;
	mScene->clear();
	delete mScene;
}

void Field::cellWasAttacked(Cell *item)
{
	emit playerAttackCell(item);
}

void Field::getCoordinate(QPointF first, QPointF second)
{
	QList<QGraphicsItem*> list = mScene->items(first);
	QList<QGraphicsItem*> list2 = mScene->items(second);
	Cell *firstCell = dynamic_cast<Cell *>(list.at(0));
	Cell *secondCell = dynamic_cast<Cell *>(list2.at(0));
	emit shipOnCells(firstCell->data(sizeOfCube / 10).toInt(), secondCell->data(sizeOfCube / 10).toInt());
}
