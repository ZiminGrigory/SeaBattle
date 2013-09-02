#pragma once
#include <QWidget>
#include <QGraphicsScene>

#include "cell.h"
namespace Ui {
class Field;
}

class Field : public QWidget
{
	Q_OBJECT
	
public:
	explicit Field(QWidget *parent = 0);
	QVector<Cell *> getField();
	~Field();
private slots:
	void cellWasAttacked(Cell *item);
	void getCoordinate(QPointF first, QPointF second);
signals:
	void playerAttackCell(Cell *item);
	void shipOnCells(int x, int y);
private:
	Ui::Field *ui;
	QVector<Cell *> field;
	QGraphicsScene *mScene;
};

