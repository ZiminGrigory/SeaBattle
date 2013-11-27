#include "SettingsMenu.h"
#include "ui_SettingsMenu.h"
#include "Settings.h"
#include "SettingsNetwork.h"

SettingsMenu::SettingsMenu() :
	QWidget(),
	ui(new Ui::SettingsMenu)
{
	ui->setupUi(this);
    ui->buttonBack->setText("Назад в главное меню");
    ui->buttonNetwork->setText("Настройки сети");
    ui->buttonVolume->setText("Настройки звука");
	connect(ui->buttonBack, SIGNAL(clicked()), SIGNAL(buttonBackPushed()));
	connect(ui->buttonNetwork, SIGNAL(clicked()), SLOT(showNetworkSettings()));
	connect(ui->buttonVolume, SIGNAL(clicked()), SLOT(showVolumeSettings()));
	volSettings = QSharedPointer<Settings> (new Settings);
	netorkSettings = QSharedPointer<SettingsNetwork> (new SettingsNetwork);
	connect(volSettings.data(), SIGNAL(buttonBackPushed()), SLOT(hideBoth()));
	connect(netorkSettings.data(), SIGNAL(buttonBackPushed()), SLOT(hideBoth()));
	connect(volSettings.data(), SIGNAL(changeVolume(int)), SIGNAL(volumeChanched(int)));
	connect(volSettings.data(), SIGNAL(mute(bool)), SIGNAL(mute(bool)));
	connect(netorkSettings.data(), SIGNAL(nameOfServerWithPort(QString,quint16))
			, SLOT(handleNameOfServerWithPort(QString,quint16)));

	ui->layoutForWidget->addWidget(volSettings.data());
	ui->layoutForWidget->addWidget(netorkSettings.data());
	hideBoth();
}

SettingsMenu::~SettingsMenu()
{
	delete ui;
}

void SettingsMenu::showNetworkSettings()
{
	ui->buttonNetwork->hide();
	ui->buttonVolume->hide();
	netorkSettings->show();
}

void SettingsMenu::showVolumeSettings()
{
	ui->buttonNetwork->hide();
	ui->buttonVolume->hide();
	volSettings->show();
}

void SettingsMenu::hideBoth()
{
	ui->buttonNetwork->show();
	ui->buttonVolume->show();
	netorkSettings->hide();
	volSettings->hide();
}

void SettingsMenu::handleNameOfServerWithPort(QString name, quint16 i)
{
	settings.setValue(SettingsKey::IP_KEY, name);
	settings.setValue(SettingsKey::PORT_KEY, i);
}
