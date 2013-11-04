#include "SettingsNetwork.h"
#include "ui_SettingsNetwork.h"

SettingsNetwork::SettingsNetwork() :
	InterfaceNetworkSettings(),
	QWidget(),
	ui(new Ui::SettingsNetwork)
{
	ui->setupUi(this);
	ui->label_IP->setText(QString::fromLocal8Bit("<font color = black>IP сервера:<\\font>"));
	ui->label_PORT->setText(QString::fromLocal8Bit("<font color = black>Номер порта:<\\font>"));
	ui->buttonBACK->setText(QString::fromLocal8Bit("Назад"));
	ui->buttonOK->setText(QString::fromLocal8Bit("ОК"));
	ui->buttonAPPLY->setText(QString::fromLocal8Bit("Принять"));
	ui->lineEdit_IP->setText(settings.value(SettingsKey::IP_KEY).toString());
	ui->lineEdit_PORT->setText(settings.value(SettingsKey::PORT_KEY).toString());
	connect(ui->buttonBACK, SIGNAL(clicked()), SIGNAL(buttonBackPushed()));
	connect(ui->buttonAPPLY, SIGNAL(clicked()), SLOT(applyHandler()));
	connect(ui->buttonOK, SIGNAL(clicked()), SLOT(okHandler()));
}

SettingsNetwork::~SettingsNetwork()
{
	delete ui;
}

void SettingsNetwork::applyHandler()
{
	emit nameOfServerWithPort(ui->lineEdit_IP->text(), quint16(ui->lineEdit_PORT->text().toUInt()));
}

void SettingsNetwork::okHandler()
{
	emit nameOfServerWithPort(ui->lineEdit_IP->text(), quint16(ui->lineEdit_PORT->text().toUInt()));
	emit buttonBackPushed();
}
