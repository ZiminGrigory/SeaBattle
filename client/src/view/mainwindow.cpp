#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui.data()->setupUi(this);
	ui.data()->lcdNumber->hide();
	this->setWindowTitle(QString::fromLocal8Bit("МОРСКОЙ БОЙ"));
}

void MainWindow::setMessage(QString text)
{
	ui->label->setText(QString::fromLocal8Bit(text.toLocal8Bit()));
}

void MainWindow::showPlayerField(QSharedPointer<Field> field)
{
	ui.data()->horizontalLayout_2->addWidget(field.data());
}

void MainWindow::showInfoTab(QSharedPointer<TabOfInformation> infoTab)
{
	ui.data()->horizontalLayout_2->addWidget(infoTab.data());
}

void MainWindow::setTime(int time)
{
	ui->lcdNumber->display(time);
	timer.start(1000);
	connect(&timer, SIGNAL(timeout()), this, SLOT(decTime()));
}

void MainWindow::decTime()
{
	ui->lcdNumber->display(ui->lcdNumber->value() - 1);
}

void MainWindow::showEnemyField(QSharedPointer<Field> field)
{
	ui.data()->lcdNumber->show();
	ui.data()->horizontalLayout_2->itemAt(1)->widget()->hide();
	ui.data()->horizontalLayout_2->addWidget(field.data());
}
