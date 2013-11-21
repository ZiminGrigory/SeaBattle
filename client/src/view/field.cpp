#include "field.h"
#include "ui_field.h"
#include <QDebug>
#include <QPixmap>


Field::Field() :
	QWidget(),
	ui(new Ui::Field)
{
	ui->setupUi(this);
	this->setMaximumSize(sizeOfCube + 40, sizeOfCube + 40);
	this->setMinimumSize(sizeOfCube + 40, sizeOfCube + 40);
	ui->graphicsView->setMaximumSize(sizeOfCube + 3, sizeOfCube + 3);
	ui->graphicsView->setMinimumSize(sizeOfCube + 3, sizeOfCube + 3);
	mScene = new QGraphicsScene;
	mScene->setSceneRect(0, 0, sizeOfCube, sizeOfCube);
	int x = sizeOfCube / 10;
	int y = sizeOfCube / 10;
	field.resize(100);
	for (int i = 1; i <= 10; i++){
		for (int j = 1; j <= 10; j++){
			Cell *item = new Cell(x, y);
			field[(i - 1) * 10 + j - 1] = item;
			item->setData(DATA_KEY, (i - 1) * 10 + j - 1);
			item->setData(DATA_KEY_NAME, "cell");
			item->setPos((j - 1) * x, (i - 1) * y);
			connect(item, SIGNAL(attacked(int)), SIGNAL(attack(int)));\
			connect(item, SIGNAL(getCoordinate(QPointF,QPointF)), this, SLOT(getCoordinate(QPointF,QPointF)));
			connect(item, SIGNAL(deleteShip(int)), this, SLOT(deleteShipOnCell(int)));
			connect(item, SIGNAL(setArrows(int)), this, SIGNAL(setFirstArrows(int)));
			connect(item, SIGNAL(coordinatesOfMouseNow(int)), this, SIGNAL(setNextArrow(int)));
			mScene->addItem(item);
		}
	}
	ui->graphicsView->setViewportUpdateMode(QGraphicsView::MinimalViewportUpdate);
	ui->graphicsView->setCacheMode(QGraphicsView::CacheNone);
	ui->graphicsView->setScene(mScene);
	backgroundBrush = QSharedPointer<QMovie>(new QMovie(":/pictures/sea_animation.gif"));
	backgroundBrush->start();
	ui->graphicsView->setBackgroundBrush(QBrush(backgroundBrush->currentPixmap()));
	connect(backgroundBrush.data(), SIGNAL(updated(QRect)), SLOT(updateBackground(QRect)));
	itemForMessage = NULL;
	attackStatus = NULL;
}

void Field::paintCell(int id, Textures texture)
{
	field.at(id)->changeStatusOfCell(texture);
}

void Field::showAttackStatus(AttackStatus status)
{
	if (itemForMessage != NULL){
		deleteMessage();
	}
	switch (int(status)) {
	case MISS:
		attackStatus = new QMovie(":/pictures/miss.gif");
		break;
	case WOUNDED:
		attackStatus = new QMovie(":/pictures/wounded.gif");
		break;
	case KILLED:
		attackStatus = new QMovie(":/pictures/killed.gif");
		break;
	}
	itemForMessage = mScene->addPixmap(attackStatus->currentPixmap());
	itemForMessage->update();
	timer.start(950); //связано с длительностью гифки
	connect(&timer, SIGNAL(timeout()), this, SLOT (deleteMessage()));
	attackStatus->start();
	connect(attackStatus, SIGNAL(updated(QRect)), SLOT(updateAttackStatus(QRect)));
}

void Field::showResult(Players player)
{
	QPixmap message;
	switch (int(player)) {
	case YOU:
		message = QPixmap(":/pictures/LOSER.jpeg");
		break;
	case ENEMY:
		message = QPixmap(":/pictures/WINNER.jpeg");
		break;
	}
	itemForEndMessage = QSharedPointer<QGraphicsItem>(mScene->addPixmap(message));
}

Cell* Field::getCellView(int id)
{
	return field[id];
}

void Field::addImage(int id, ImageID iD)
{
	QSharedPointer<QGraphicsItem> pictureForCell;
	QPixmap arrow = QPixmap(":/pictures/arrow.png");
	QPixmap firstPoint = QPixmap(":/pictures/first point.png");
	QPixmap arrowCircle = QPixmap(":/pictures/cirle arrow.png");
	switch (iD) {
	case ARROW_DOWN:
		arrow = arrow.transformed(QTransform().rotate(qreal(180),Qt::ZAxis), Qt::FastTransformation);
		pictureForCell = QSharedPointer<QGraphicsItem>(mScene->addPixmap(arrow));
		pictureForCell->setPos(getQPointFByID(id));
		break;
	case ARROW_IN_ITSELF:
		pictureForCell = QSharedPointer<QGraphicsItem>(mScene->addPixmap(arrowCircle));
		pictureForCell->setPos(getQPointFByID(id));
		break;
	case ARROW_L:
		arrow = arrow.transformed(QTransform().rotate(qreal(270),Qt::ZAxis), Qt::FastTransformation);
		pictureForCell = QSharedPointer<QGraphicsItem>(mScene->addPixmap(arrow));
		pictureForCell->setPos(getQPointFByID(id));
		break;
	case ARROW_R:
		arrow = arrow.transformed(QTransform().rotate(qreal(90),Qt::ZAxis), Qt::FastTransformation);
		pictureForCell = QSharedPointer<QGraphicsItem>(mScene->addPixmap(arrow));
		pictureForCell->setPos(getQPointFByID(id));
		break;
	case ARROW_UP:
		pictureForCell = QSharedPointer<QGraphicsItem>(mScene->addPixmap(arrow));
		pictureForCell->setPos(getQPointFByID(id));
		break;
	case FIRT_POINT:
		pictureForCell = QSharedPointer<QGraphicsItem>(mScene->addPixmap(firstPoint));
		pictureForCell->setPos(getQPointFByID(id));
		break;
	}

	picturesUnderCell[id] = pictureForCell;
}

void Field::removeImageFromCell(int id)
{
	mScene->removeItem(picturesUnderCell[id].data());
}

void Field::clearItself()
{
	for (int i = 0; i < field.size(); i++){
		field[i]->changeStatusOfCell();
		field[i]->update();
	}
	mScene->removeItem(itemForEndMessage.data());
	itemForEndMessage.clear();
	itemForEndMessage.reset();
}

void Field::setAttackable(bool attackable)
{
	setEnabled(attackable);
}

Field::~Field()
{
	for(int i = 0;i < field.size(); i++){
		delete field[i];
	}
	mScene->clear();
	delete mScene;
	delete ui;
}

void Field::setEnabledItself(bool switcher)
{
	this->setEnabled(switcher);
}

void Field::repaint(int id, Textures texture)
{
	paintCell(id, texture);
}

void Field::getCoordinate(QPointF first, QPointF second)
{
	QList<QGraphicsItem*> list = mScene->items(first);
	QList<QGraphicsItem*> list2 = mScene->items(second);
	QGraphicsItem *firstCell;
	QGraphicsItem *secondCell;
	int i = 0;
	bool condition = false;
	do{
		qDebug() << list.at(i)->data(DATA_KEY).toInt();
		if (list.at(i)->data(DATA_KEY_NAME).toString() == "cell"){
			condition = true;
		}
		i++;
	}while (!condition && i < list.size());
	condition = false;
	firstCell = list.at(i - 1);
	i = 0;
	do{
		qDebug() << list2.at(i)->data(DATA_KEY).toInt();
		if (list2.at(i)->data(DATA_KEY_NAME).toString() == "cell"){
			condition = true;
		}
		i++;
	}while (!condition && i < list2.size());
	secondCell = list2.at(i - 1);
	emit placeShip(firstCell->data(DATA_KEY).toInt(), secondCell->data(DATA_KEY).toInt());
}

void Field::deleteShipOnCell(int id)
{
	emit deleteShip(id);
}

void Field::deleteMessage()
{
	if (itemForMessage != NULL && attackStatus != NULL){
		disconnect(&timer, SIGNAL(timeout()), this, SLOT (deleteMessage()));
		timer.stop();
		mScene->removeItem(itemForMessage);
		delete itemForMessage;
		delete attackStatus;
		itemForMessage = NULL;
		attackStatus = NULL;
	}
}

void Field::updateBackground(QRect)
{
	ui->graphicsView->setBackgroundBrush(QBrush(backgroundBrush->currentPixmap()));
}

void Field::updateAttackStatus(QRect)
{
	mScene->removeItem(itemForMessage);
	delete itemForMessage;
	itemForMessage = mScene->addPixmap(attackStatus->currentPixmap());
}
