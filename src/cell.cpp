#include "cell.h"
#include <QDebug>
#include <QCursor>

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
	this->setEnabled(false);
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
	emit attacked(this);
}

void Cell::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	difference = mapToParent(QCursor::pos());
}


void Cell::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
	QPointF first = mapToParent(this->pos());
	QPointF cursor = mapToParent(QCursor::pos());
	QPointF secondTmp = first + cursor - difference;
	QPointF second = mapFromScene(secondTmp.toPoint());
	second.setX(qAbs(second.x()));
	second.setY(qAbs(second.y()));
	emit getCoordinate(mapFromScene(first), second);
}
