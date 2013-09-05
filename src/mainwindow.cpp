#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	ui->label->setText("SHIP BUILDING");
}

void MainWindow::paintStartDialog()
{
	fieldFirst = new Field;
	infoTab = new TabOfInformation;
	ui->horizontalLayout_2->addWidget(fieldFirst);
	ui->horizontalLayout_2->addWidget(infoTab);
	connect(infoTab, SIGNAL(fieldIsReady()), this, SLOT(paintEnemyField()));
	connect(fieldFirst, SIGNAL(playerAttackCell(int)), this, SLOT(attackOnCell(int)));
	connect(fieldFirst, SIGNAL(shipOnCells(int,int)), this, SLOT(buildShip(int, int)));
	connect(fieldFirst, SIGNAL(deleteShip(int)), this, SLOT(deleteShipOnCell(int)));
}

void MainWindow::changeCounter(int ship, int count)
{
	infoTab->changeCountOfShip(ship, count);
}

void MainWindow::paintCell(int player, int id, int texture)
{
	if (player == 0){
		fieldFirst->paintCell(id, texture);
	}
	else{
		fieldSecond->paintCell(id, texture);
	}
}

void MainWindow::changeTurn(int player)
{
	if (player == 0){
		ui->label->setText("YOU TURN");
		fieldSecond->setEnabled(true);
	}
	else{
		ui->label->setText("ENEMY TURNS");
		fieldSecond->setEnabled(false);
	}
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::attackOnCell(int id)
{
	emit attackCell(id);
}

void MainWindow::buildShip(int firstId, int secondId)
{
	emit createShip(firstId, secondId);
}


void MainWindow::paintEnemyField()
{
	fieldSecond = new Field;
	fieldFirst->setEnabled(false);
	infoTab->~TabOfInformation();
	ui->horizontalLayout_2->addWidget(fieldSecond);
	fieldSecond->setEnabled(false);
}

void MainWindow::deleteShipOnCell(int id)
{
	emit deleteShip(id);
}
