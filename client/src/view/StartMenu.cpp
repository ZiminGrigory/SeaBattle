#include "StartMenu.h"
#include "ui_StartMenu.h"

StartMenu::StartMenu() :
	 QWidget(),
	ui(new Ui::StartMenu)
{
	ui->setupUi(this);
    ui->buttonVsPC->setText("Игрок против Компьютера");
    ui->buttonExit->setText("Выход");
    ui->buttonVsPlayer->setText("Игрок против игрока");
    ui->buttonSettings->setText("Настройки");
	connect(ui->buttonExit, SIGNAL(clicked()), SIGNAL(buttonExitPushed()));
	connect(ui->buttonVsPC, SIGNAL(clicked()), SIGNAL(buttonVsPcPushed()));
	connect(ui->buttonVsPlayer, SIGNAL(clicked()), SIGNAL(buttonVsPlayerPushed()));
	connect(ui->buttonSettings, SIGNAL(clicked()), SIGNAL(buttonSettingsPushed()));
}

StartMenu::~StartMenu()
{
	delete ui;
}
