#include "field.h"
#include "ui_field.h"
#include <QDebug>
#include <QPixmap>


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
			connect(item, SIGNAL(attacked(int)), this, SLOT(cellWasAttacked(int)));\
			connect(item, SIGNAL(getCoordinate(QPointF,QPointF)), this, SLOT(getCoordinate(QPointF,QPointF)));
			connect(item, SIGNAL(deleteShip(int)), this, SLOT(deleteShipOnCell(int)));
			mScene->addItem(item);
		}
	}
	ui->graphicsView->setScene(mScene);
}

void Field::paintCell(int id, Textures texture)
{
	field.at(id)->changeStatusOfCell(texture);
}

void Field::showAttackStatus(AttackStatus status)
{
	QPixmap message;
	switch (status) {
	case MISS:
		message = QPixmap(":/pictures/MISS.png");
		break;
	case WOUNDED:
		message = QPixmap(":/pictures/WOUNDED.png");
		break;
	case KILLED:
		message = QPixmap(":/pictures/KILLED.png");
		break;
	}
	item = QSharedPointer<QGraphicsItem>(mScene->addPixmap(message));
	ui->graphicsView->update();
	timer.start(2400);
	connect(&timer, SIGNAL(timeout()), this, SLOT (deleteMessage()));
}

Cell* Field::getCellView(int id)
{
	return field[id];
}

Field::~Field()
{
	delete ui;
	mScene->clear();
	delete mScene;
}

void Field::cellWasAttacked(int id)
{
	emit playerAttackCell(id);
}

void Field::getCoordinate(QPointF first, QPointF second)
{
	QList<QGraphicsItem*> list = mScene->items(first);
	QList<QGraphicsItem*> list2 = mScene->items(second);
	Cell *firstCell = dynamic_cast<Cell *>(list.at(0));
	Cell *secondCell = dynamic_cast<Cell *>(list2.at(0));
	emit shipOnCells(firstCell->data(sizeOfCube / 10).toInt(), secondCell->data(sizeOfCube / 10).toInt());
}

void Field::deleteShipOnCell(int id)
{
	emit deleteShip(id);
}

void Field::deleteMessage()
{
	disconnect(&timer, SIGNAL(timeout()), this, SLOT (deleteMessage()));
	timer.stop();
	mScene->removeItem(item.data());
	ui->graphicsView->update();
}
