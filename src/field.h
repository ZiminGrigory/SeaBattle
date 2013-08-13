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
	~Field();
	
private:
	Ui::Field *ui;
	QGraphicsScene *mScene;
};

