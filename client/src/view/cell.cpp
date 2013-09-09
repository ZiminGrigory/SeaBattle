#include "cell.h"
#include <QDebug>
#include <QCursor>
#include <QGraphicsSceneMouseEvent>
#include <QPixmap>

Cell::Cell(int x, int y): y(y), x(x), mTexture(":/pictures/sea.jpg")
{
}


void Cell::changeStatusOfCell(Textures texture)
{
	//расширить
	switch (texture) {
	case EMPTY: mTexture = ":/pictures/sea.jpg";
		break;
    case SHIP_DAMAGED: mTexture = ":/pictures/smoke.jpg";
		break;
    case SHIP_KILLED: mTexture = ":/pictures/wreck.jpg";
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
	}
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
	painter->setBrush(QBrush(QPixmap(mTexture)));
	painter->drawRect(boundingRect());
}

void Cell::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
	if (event->button() == Qt::LeftButton){
		emit attacked(this->data(x).toInt());
	}
}

void Cell::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	if (event->button() == Qt::RightButton){
		emit deleteShip(this->data(x).toInt());
	} else if (event->button() == Qt::LeftButton){
		first = event->scenePos();
	}
}

void Cell::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
	if (event->button() == Qt::LeftButton){
		QPointF second = event->scenePos();
		emit getCoordinate(first, second);
	}
}
