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
    void changeStatusOfCell(Textures texture = EMPTY);
signals:
	void attacked(int id);
	void getCoordinate(QPointF first, QPointF second);
	void deleteShip(int id);
private:
	int x;
	int y;
	QPointF first;
	QColor color;
};
