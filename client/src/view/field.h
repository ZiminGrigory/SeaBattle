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
    void paintCell(int id, Textures texture);

    Cell* getCellView(int id);

	~Field();
private slots:
	void cellWasAttacked(int id);
	void getCoordinate(QPointF first, QPointF second);
	void deleteShipOnCell(int id);
signals:
	void playerAttackCell(int id);
	void shipOnCells(int firstId, int secondId);
	void deleteShip(int id);
private:
	Ui::Field *ui;
	QVector<Cell *> field;
	QGraphicsScene *mScene;
};

