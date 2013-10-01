#include "ChatAndStatus.h"
#include "ui_ChatAndStatus.h"
#include "QPixmap"

ChatAndStatus::ChatAndStatus() : InterfaceChatAndStatus(),
	ui(new Ui::ChatAndStatus)
{
	ui->setupUi(this);
	ui->buttonEnter->setText(QString::fromLocal8Bit("Ввод"));
	connect(ui->buttonEnter, SIGNAL(clicked()), SLOT(getText()));
}

void ChatAndStatus::appendMessage(Players plr, QString text)
{
	QString firstText;
	if (plr == YOU){
		firstText = QString::fromLocal8Bit("ВЫ: ");
	} else {
		firstText= QString::fromLocal8Bit("Враг: ");
	}

	firstText += text;
	ui->textBrowser->append(firstText);
}

void ChatAndStatus::showPicture(Players plr, PictureStatus::Picture status)
{
	QPixmap picture;
	switch (status) {
	case PictureStatus::ATTACKED:
		break;
	case PictureStatus::DAMAGE_SHIP:
		break;
	case PictureStatus::KILL_SHIP:
		break;
	case PictureStatus::MISSED:
		break;
	}
	if (plr == YOU){
		ui->labelLeft->setPixmap(picture);
	}else {
		ui->labelRight->setPixmap(picture);
	}
}

void ChatAndStatus::getText()
{
	QString text = ui->lineEdit->text();
	ui->lineEdit->clear();
	emit getNewMessage(text);
}

ChatAndStatus::~ChatAndStatus()
{
	delete ui;
}

void ChatAndStatus::clearChat()
{
	ui->textBrowser->clear();
}
