#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	this->setWindowTitle(QString::fromLocal8Bit("МОРСКОЙ БОЙ"));
}

void MainWindow::paintStartDialog()
{
	ui->label->setText(QString::fromLocal8Bit("УСТАНОВКА КОРАБЛЕЙ"));
	ui->label->setAlignment(Qt::AlignHCenter);
	fieldFirst = new Field;
	infoTab = new TabOfInformation;
	ui->horizontalLayout_2->addWidget(fieldFirst);
	ui->horizontalLayout_2->addWidget(infoTab);
	connect(infoTab, SIGNAL(fieldIsReady()), this, SLOT(paintEnemyField()));
	connect(fieldFirst, SIGNAL(playerAttackCell(int)), this, SLOT(attackOnCell(int)));
	connect(fieldFirst, SIGNAL(shipOnCells(int,int)), this, SLOT(buildShip(int, int)));
	connect(fieldFirst, SIGNAL(deleteShip(int)), this, SLOT(deleteShipOnCell(int)));
}

void MainWindow::changeCounter(NameOfShips ship, int count)
{
	infoTab->changeCountOfShip(ship, count);
}

void MainWindow::paintCell(int player, int id, Textures texture)
{
	 if (player == YOU){
		fieldFirst->paintCell(id, texture);
	}
	else{
		fieldSecond->paintCell(id, texture);
	}
}

void MainWindow::changeTurn(int player)
{
	if (player == 0){
		ui->label->setText(QString::fromLocal8Bit("ВАШ ХОД"));
		fieldSecond->setEnabled(true);
	}
	else{
		ui->label->setText(QString::fromLocal8Bit("ХОД ПРОТИВНИКА"));
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
	ui->label->setText("LOADING...");
	fieldSecond = new Field;
	connect(fieldSecond, SIGNAL(playerAttackCell(int)), this, SLOT(attackOnCell(int)));
	fieldFirst->setEnabled(false);
	infoTab->~TabOfInformation();
	ui->horizontalLayout_2->addWidget(fieldSecond);
	fieldSecond->setEnabled(false);
}

void MainWindow::deleteShipOnCell(int id)
{
	emit deleteShip(id);
}
