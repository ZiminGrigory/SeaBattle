#include "ChatAndStatus.h"
#include "ui_ChatAndStatus.h"
#include "QPixmap"

ChatAndStatus::ChatAndStatus() :
	InterfaceChatAndStatus(),
	QWidget(),
	ui(new Ui::ChatAndStatus)
{
	ui->setupUi(this);
	//какая-то магия, нашел в сети...
	QString arg = "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0,";
	arg += " stop:0 rgba(0, 0, 0, 0), stop:1 rgba(255, 255, 255, 0));";
	ui->textBrowser->setStyleSheet(arg);
	ui->lineEdit->setStyleSheet(arg);
	ui->buttonEnter->setText(QString::fromLocal8Bit("Ввод"));
	connect(ui->buttonEnter, SIGNAL(clicked()), SLOT(getText()));
	QPixmap picture = QPixmap(":/pictures/forChat/BEGIN.jpg");
	ui->labelLeft->setPixmap(picture);
	ui->labelRight->setPixmap(picture);
	connect(&mTimer, SIGNAL(timeout()), SLOT(clearPicture()));
}

void ChatAndStatus::appendMessage(Players plr, QString text)
{
	QString firstText;
	if (plr == YOU){
		firstText = QString::fromLocal8Bit("<font color = blue>ВЫ: <\\font>");
    } else if (plr == ENEMY) {
		firstText = QString::fromLocal8Bit("<font color = red>ВРАГ: <\\font>");
    } else if (plr == GAME) {
        firstText = QString::fromLocal8Bit("<font color = green>ИГРА: <\\font>");
    }

	firstText += QString("<font color = black>" + text + "<\\font>");
	ui->textBrowser->append(firstText);
}

void ChatAndStatus::showPicture(Players plr, PictureStatus::Picture status)
{
	QPixmap picture;
	switch (status) {
	case PictureStatus::ATTACKED:
		picture = QPixmap(":/pictures/forChat/ATTACK.jpg");
		break;
	case PictureStatus::DAMAGE_SHIP:
		picture = QPixmap(":/pictures/forChat/WOUNDED.jpg");
		break;
	case PictureStatus::KILL_SHIP:
		picture = QPixmap(":/pictures/forChat/KILLED.jpg");
		break;
	case PictureStatus::MISSED:
		picture = QPixmap(":/pictures/forChat/MISS.jpg");
		break;
	}
	if (plr == YOU){
		ui->labelLeft->setPixmap(picture);
	}else {
		ui->labelRight->setPixmap(picture);
	}
	mTimer.start(2000);
}

void ChatAndStatus::getText()
{
	QString text = ui->lineEdit->text();
	ui->lineEdit->clear();
	emit getNewMessage(text);
}

void ChatAndStatus::clearPicture()
{
	mTimer.stop();
	QPixmap picture = QPixmap(":/pictures/forChat/BEGIN.jpg");
	ui->labelLeft->setPixmap(picture);
	ui->labelRight->setPixmap(picture);
}

ChatAndStatus::~ChatAndStatus()
{
	delete ui;
}

void ChatAndStatus::clearChat()
{
	ui->textBrowser->clear();
}
