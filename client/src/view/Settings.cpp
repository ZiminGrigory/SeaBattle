#include "Settings.h"
#include "ui_Settings.h"

Settings::Settings() :
	InterfaceVolumeSettings(),
	QWidget(),
	ui(new Ui::Settings)
{
	ui->setupUi(this);
	ui->label->setText(QString::fromLocal8Bit("<font color = black>Настройка громкости:<\\font>"));
	ui->checkBox->setText(QString::fromLocal8Bit(""));
	ui->buttonBack->setText(QString::fromLocal8Bit("Назад"));
	ui->buttonOK->setText(QString::fromLocal8Bit("ОК"));
	ui->buttonAPPLY->setText(QString::fromLocal8Bit("Принять"));
	ui->labelForChecker->setText(QString::fromLocal8Bit("<font color = black>Выключить звук<\\font>"));
	if (settings.contains(SettingsKey::VOLUME_KEY)){
		int s = settings.value(SettingsKey::VOLUME_KEY).toInt();
		ui->horizontalSlider->setValue(settings.value(SettingsKey::VOLUME_KEY).toInt());
		ui->progressBar->setValue(settings.value(SettingsKey::VOLUME_KEY).toInt());
	} else {
		ui->horizontalSlider->setValue(50);
		ui->progressBar->setValue(50);
	}
	if (settings.contains(SettingsKey::MUTE_KEY)){
		ui->checkBox->setChecked(settings.value(SettingsKey::MUTE_KEY).toBool());
	} else {
		ui->checkBox->setChecked(false);
	}
	connect(ui->horizontalSlider, SIGNAL(valueChanged(int)), ui->progressBar, SLOT(setValue(int)));
	connect(ui->buttonBack, SIGNAL(clicked()), SIGNAL(buttonBackPushed()));
	connect(ui->buttonAPPLY, SIGNAL(clicked()), SLOT(applyHandler()));
	connect(ui->buttonOK, SIGNAL(clicked()), SLOT(okHandler()));
}

Settings::~Settings()
{
	delete ui;
}

void Settings::applyHandler()
{
	emit changeVolume(ui->horizontalSlider->value());
	emit mute(ui->checkBox->isChecked());
}

void Settings::okHandler()
{
	emit changeVolume(ui->horizontalSlider->value());
	emit mute(ui->checkBox->isChecked());
	emit buttonBackPushed();
}
