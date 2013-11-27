#include "AiLvlList.h"
#include "ui_AiLvlList.h"

AiLvlList::AiLvlList() :
	QWidget(),
	ui(new Ui::AiLvlList)
{
	ui->setupUi(this);
    ui->buttonBack->setText("Назад");
    ui->buttonVs2->setText("2 уровень компьютера");
    ui->buttonVs1->setText("1 уровень компьютера");
	connect(ui->buttonBack, SIGNAL(clicked()), SIGNAL(buttonExitPushed()));
	connect(ui->buttonVs1, SIGNAL(clicked()), SIGNAL(buttonVsSimplePushed()));
	connect(ui->buttonVs2, SIGNAL(clicked()), SIGNAL(buttonVsProPushed()));
}

AiLvlList::~AiLvlList()
{
	delete ui;
}
