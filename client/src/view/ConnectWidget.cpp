#include "ConnectWidget.h"
#include "ui_ConnectWidget.h"

ConnectWidget::ConnectWidget(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::ConnectWidget)
{
	ui->setupUi(this);
}

ConnectWidget::~ConnectWidget()
{
	delete ui;
}
