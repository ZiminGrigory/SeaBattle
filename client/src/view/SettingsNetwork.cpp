#include "SettingsNetwork.h"
#include "ui_SettingsNetwork.h"

SettingsNetwork::SettingsNetwork() :
	QWidget(),
	ui(new Ui::SettingsNetwork)
{
	ui->setupUi(this);
    ui->label_IP->setText("<font color = black>IP сервера:<\\font>");
    ui->label_PORT->setText("<font color = black>Номер порта:<\\font>");
    ui->buttonBACK->setText("Назад");
    ui->buttonOK->setText("ОК");
    ui->buttonAPPLY->setText("Принять");
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
