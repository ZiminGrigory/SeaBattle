#pragma once
#include <QGraphicsItem>
#include <QPainter>
#include "types.h"

class Cell: public QGraphicsItem
{
public:
	Cell(int x, int y);
	QRectF boundingRect() const;
	QPainterPath shape() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
	void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
	void changeStatusOfCell(int const &status = NOT_ATTACKED);
private:
	int x;
	int y;
};
