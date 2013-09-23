#include "AiLvlList.h"
#include "ui_AiLvlList.h"

AiLvlList::AiLvlList(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::AiLvlList)
{
	ui->setupUi(this);
}

AiLvlList::~AiLvlList()
{
	delete ui;
}
