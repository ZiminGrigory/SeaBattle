#include "StartMenu.h"
#include "ui_StartMenu.h"

StartMenu::StartMenu(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::StartMenu)
{
	ui->setupUi(this);
}

StartMenu::~StartMenu()
{
	delete ui;
}
