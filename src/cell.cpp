#include "cell.h"
#include <QDebug>
#include <QCursor>
#include <QGraphicsSceneMouseEvent>

Cell::Cell(int x, int y): y(y), x(x), color(Qt::white)
{
}


void Cell::changeStatusOfCell(const int &status)
{
	//для теста, потом здесь будут картинки, а мб и не будет картинок
	switch (status) {
		case MISS: color = Qt::blue;
		break;
		case WOUNDED: color = Qt::red;
		break;
		case KILLED: color = Qt::black;
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

	painter->setBrush(QBrush(color));
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
