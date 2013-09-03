#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	fieldFirst = new Field;
	fieldSecond = new Field;
	infoTab = new TabOfInformation;
	ui->horizontalLayout->addWidget(fieldFirst);
	ui->horizontalLayout->addWidget(infoTab);
	test(fieldFirst->getField());
	connect(fieldFirst, SIGNAL(playerAttackCell(Cell*)), this, SLOT(testAttack(Cell*)));
	connect(fieldFirst, SIGNAL(shipOnCells(int,int)), this, SLOT(testBuildShip(int, int)));
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::test(QVector<Cell *> vector)
{
	//vector[12]->changeStatusOfCell(WOUNDED);
}

void MainWindow::testAttack(Cell *item)
{
	item->changeStatusOfCell(2);
}

void MainWindow::testBuildShip(int x, int y)
{
	qDebug() << x << " " << y;
	QVector<Cell *> field = fieldFirst->getField();
	if (qAbs(x-y) < 10){
		for (int i = x; i <= y; i++){
			field.at(i)->changeStatusOfCell(KILLED);
		}
	}else{
		for (int i = x; i <= y; i += 10){
			field.at(i)->changeStatusOfCell(KILLED);
		}
	}
}
