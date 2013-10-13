#include "cell.h"
#include <QDebug>
#include <QCursor>
#include <QGraphicsSceneMouseEvent>
#include <QPixmap>
#include <QMovie>

Cell::Cell(int x, int y): y(y), x(x), mTexture("empty"), gifMovie(NULL)
{
}

Cell::~Cell()
{
	if (gifMovie != NULL){
		delete gifMovie;
	}
}


void Cell::changeStatusOfCell(Textures texture)
{
	//расширить
	if (gifMovie != NULL){
		gifMovie->stop();
	}
	switch (texture) {
	case EMPTY: mTexture = "empty";
		break;
	case SHIP_DAMAGED: mTexture = "gif";
		handleGif(SHIP_DAMAGED);
		break;
	case MISS_CELL: mTexture = ":/pictures/splash.jpg";
		break;
	case SHIP_POOP_VERTICAL: mTexture = ":/pictures/bottom.jpg";
		break;
	case SHIP_BOW_VERTICAL: mTexture = ":/pictures/head.jpg";
		break;
	case SHIP_DECK_VERTICAL: mTexture = ":/pictures/middle part.jpg";
		break;
	case SHIP_POOP_HORIZONTAL: mTexture = ":/pictures/bottom_hor.jpg";
		break;
	case SHIP_BOW_HORIZONTAL: mTexture = ":/pictures/head_hor.jpg";
		break;
	case SHIP_DECK_HORIZONTAL: mTexture = ":/pictures/middle part_hor.jpg";
		break;
	case SHIP_SINGLE: mTexture = ":/pictures/small ship.jpg";
		break;
	case SHIP_POOP_VERTICAL_BURN: mTexture = "gif";
		handleGif(SHIP_POOP_VERTICAL_BURN);
		break;
	case SHIP_BOW_VERTICAL_BURN: mTexture = "gif";
		handleGif(SHIP_BOW_VERTICAL_BURN);
		break;
	case SHIP_DECK_VERTICAL_BURN: mTexture = "gif";
		handleGif(SHIP_DECK_VERTICAL_BURN);
		break;
	case SHIP_POOP_HORIZONTAL_BURN: mTexture = "gif";
		handleGif(SHIP_POOP_HORIZONTAL_BURN);
		break;
	case SHIP_BOW_HORIZONTAL_BURN: mTexture = "gif";
		handleGif(SHIP_BOW_HORIZONTAL_BURN);
		break;
	case SHIP_DECK_HORIZONTAL_BURN: mTexture = "gif";
		handleGif(SHIP_DECK_HORIZONTAL_BURN);
		break;
	case SHIP_SINGLE_BURN: mTexture = "gif";
		handleGif(SHIP_SINGLE_BURN);
		break;
	case WRECK: mTexture = ":/pictures/wreck.jpg";
		break;
	}
	this->update();
}

void Cell::handleGif(Textures texture)
{
	if (gifMovie != NULL){
		gifMovie->stop();
		delete gifMovie;
	}
	switch (texture) {
	case SHIP_DAMAGED: gifMovie = new QMovie(":/pictures/smoke_animation.gif");
		break;
	case SHIP_POOP_VERTICAL_BURN: gifMovie = new QMovie(":/pictures/bottom_burning.gif");
		break;
	case SHIP_BOW_VERTICAL_BURN: gifMovie = new QMovie(":/pictures/head_burning.gif");
		break;
	case SHIP_DECK_VERTICAL_BURN: gifMovie = new QMovie(":/pictures/middle-part-burning-animation.gif");
		break;
	case SHIP_POOP_HORIZONTAL_BURN: gifMovie = new QMovie(":/pictures/head-burning-animation_hor.gif");
		break;
	case SHIP_BOW_HORIZONTAL_BURN: gifMovie = new QMovie(":/pictures/bottom-burning-animation_hor.gif");
		break;
	case SHIP_DECK_HORIZONTAL_BURN: gifMovie = new QMovie(":/pictures/middle-part-burning-animation_hor.gif");
		break;
	case SHIP_SINGLE_BURN: gifMovie = new QMovie(":/pictures/small-ship-burning-animation.gif");
		break;
	}
	gifMovie->start();
	connect(gifMovie, SIGNAL(updated(QRect)),this, SLOT(handleGifSignal(QRect)));
}

void Cell::handleGifSignal(QRect)
{
	mCurrentTexture = gifMovie->currentPixmap();
	this->update();
}

QRectF Cell::boundingRect() const
{
	return QRectF(0,0,x,y);
}

QPainterPath Cell::shape() const
{
	QPainterPath path;
	path.addRect(boundingRect());
	return path;
}

void Cell::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	Q_UNUSED(option);
	Q_UNUSED(widget);
	if (mTexture != "empty" && mTexture != "gif" ){
		painter->setBrush(QBrush(QPixmap(mTexture)));
	} else if (mTexture == "gif"){
		painter->setBrush(QBrush(QPixmap(mCurrentTexture)));
	}
	painter->drawRect(boundingRect());
}

void Cell::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
	if (event->button() == Qt::LeftButton){
		emit attacked(this->data(DATA_KEY).toInt());
	}
}

void Cell::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	if (event->button() == Qt::RightButton){
		emit deleteShip(this->data(DATA_KEY).toInt());
	} else if (event->button() == Qt::LeftButton){
		first = event->scenePos();
		emit setArrows(this->data(DATA_KEY).toInt());
	}
}

void Cell::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
	if (event->button() == Qt::LeftButton){
		QPointF second = event->scenePos();
		emit getCoordinate(first, second);
	}
}

void Cell::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
	int x = event->scenePos().toPoint().x() / sizeOfCubeDivTen;
	int y = event->scenePos().toPoint().y() / sizeOfCubeDivTen;
	emit coordinatesOfMouseNow(getIdByCoordinates(y, x));
}
