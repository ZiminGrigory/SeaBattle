#include "ChatAndStatus.h"
#include "ui_ChatAndStatus.h"

ChatAndStatus::ChatAndStatus(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::ChatAndStatus)
{
	ui->setupUi(this);
}

ChatAndStatus::~ChatAndStatus()
{
	delete ui;
}
