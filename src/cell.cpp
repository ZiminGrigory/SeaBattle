#include "cell.h"

Cell::Cell(int x, int y): y(y), x(x)
{
}


void Cell::changeStatusOfCell(const int &status)
{
	QPainter *painter = new QPainter;
	//для теста, потом здесь будут картинки, а мб и не будет картинок
	switch (status) {
		case MISS: painter->setBrush(QBrush(Qt::blue));
		break;
		case WOUNDED: painter->setBrush(QBrush(Qt::red));
		break;
		case KILLED: painter->setBrush(QBrush(Qt::black));
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
	painter->drawRect(boundingRect());
}

void Cell::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
}
