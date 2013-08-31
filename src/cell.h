#pragma once
#include <QGraphicsItem>
#include <QPainter>
#include "types.h"

class Cell: public QObject, public QGraphicsItem
{
	Q_OBJECT
public:
	Cell(int x, int y);
	QRectF boundingRect() const;
	QPainterPath shape() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
	void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
	void mousePressEvent(QGraphicsSceneMouseEvent *event);
	void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
	void changeStatusOfCell(int const &status = NOT_ATTACKED);
signals:
	void attacked(Cell *item);
	void getCoordinate(QPointF first, QPointF second);
private:
	int x;
	int y;
	QPointF difference;
	QColor color;
};
