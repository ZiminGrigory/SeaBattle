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
	case EMPTY: mTexture = ":/pictures/small ship.jpg";
		break;
	case SHIP_DAMAGED: mTexture = ":/pictures/small ship.jpg";
		break;
	case SHIP_KILLED: mTexture = ":/pictures/small ship.jpg";
		break;
	case MISS_CELL: mTexture = "Qt::gray";
		break;
	default: mTexture = ":/pictures/small ship.jpg";
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
