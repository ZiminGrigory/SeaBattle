#include "cell.h"

Cell::Cell()
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
	return QRectF(0,0,45,45); //to do make automatically
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
