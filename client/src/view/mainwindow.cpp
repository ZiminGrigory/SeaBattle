#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui.data()->setupUi(this);
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

void MainWindow::showEnemyField(QSharedPointer<Field> field)
{
	ui.data()->horizontalLayout_2->removeWidget(mInfoTab.data());
	ui.data()->horizontalLayout_2->addWidget(field.data());
}
