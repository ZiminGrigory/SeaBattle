#include "SettingsMenu.h"
#include "ui_SettingsMenu.h"
#include "Settings.h"
#include "SettingsNetwork.h"

SettingsMenu::SettingsMenu() :
	InterfaceSettingsMenu(),
	ui(new Ui::SettingsMenu)
{
	ui->setupUi(this);
	ui->buttonBack->setText(QString::fromLocal8Bit("Назад в главное меню"));
	ui->buttonNetwork->setText(QString::fromLocal8Bit("Настройки сети"));
	ui->buttonVolume->setText(QString::fromLocal8Bit("Настройки звука"));
	connect(ui->buttonBack, SIGNAL(clicked()), SIGNAL(buttonBackPushed()));
	connect(ui->buttonNetwork, SIGNAL(clicked()), SLOT(showNetworkSettings()));
	connect(ui->buttonVolume, SIGNAL(clicked()), SLOT(showVolumeSettings()));
	volSettings = QSharedPointer<InterfaceVolumeSettings> (new Settings);
	netorkSettings = QSharedPointer<InterfaceNetworkSettings> (new SettingsNetwork);
	connect(volSettings.data(), SIGNAL(buttonBackPushed()), SLOT(hideBoth()));
	connect(netorkSettings.data(), SIGNAL(buttonBackPushed()), SLOT(hideBoth()));
	connect(volSettings.data(), SIGNAL(changeVolume(int)), SLOT(handleVolumeChanched(int)));
	connect(volSettings.data(), SIGNAL(mute(bool)), SLOT(handleMute(bool)));
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

void SettingsMenu::handleVolumeChanged(int i)
{
	settings.setValue(SettingsKey::VOLUME_KEY, i);
	emit volumeChanched(i);
}

void SettingsMenu::handleMute(bool isMute)
{
	settings.setValue(SettingsKey::MUTE_KEY, isMute);
	emit mute(isMute);
}
