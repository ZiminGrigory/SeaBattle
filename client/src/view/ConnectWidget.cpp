#include "ConnectWidget.h"
#include "ui_ConnectWidget.h"

ConnectWidget::ConnectWidget() :
	InterfaceConnectWidget(),
	QWidget(),
	ui(new Ui::ConnectWidget)
{
	ui->setupUi(this);
	ui->buttoCancel->setText(QString::fromLocal8Bit("Назад"));
	ui->buttonTryAgain->setText(QString::fromLocal8Bit("Переподключиться"));
	ui->labelTitle->setText(QString::fromLocal8Bit("<font color = black>Состояние подключения:<\\font>"));

	loader = QSharedPointer<QMovie>(new QMovie(":/pictures/loader.gif"));
	ui->labelGif->setMovie(loader.data());
	loader->start();
	ui->labelGif->hide();

	connect(ui->buttoCancel, SIGNAL(clicked()), SIGNAL(buttonExitPushed()));
	connect(ui->buttonTryAgain, SIGNAL(clicked()), SIGNAL(buttonTryAgainPushed()));
}

ConnectWidget::~ConnectWidget()
{
	delete ui;
}

void ConnectWidget::showMessage(QString text)
{
	ui->labelStatus->setText(QString("<font color = black>" + text + "<\\font>"));
}

void ConnectWidget::showLoader()
{
	ui->labelGif->show();
}

void ConnectWidget::hideLoader()
{
	ui->labelGif->hide();
}

void ConnectWidget::setEnabledTryAgain(bool switcher)
{
	ui->buttonTryAgain->setEnabled(switcher);
}
