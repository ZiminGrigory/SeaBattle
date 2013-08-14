#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "field.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	Field *fieldFirst = new Field;
	Field *fieldSecond = new Field;
	ui->horizontalLayout->addWidget(fieldFirst);
	ui->horizontalLayout->addWidget(fieldSecond);
}

MainWindow::~MainWindow()
{
    delete ui;
}
