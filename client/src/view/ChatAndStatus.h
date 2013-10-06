#ifndef CHATANDSTATUS_H
#define CHATANDSTATUS_H

#include <QWidget>
#include "InterfaceChatAndStatus.h"
#include <QTimer>

namespace Ui {
class ChatAndStatus;
}

class ChatAndStatus : public InterfaceChatAndStatus
{
	Q_OBJECT

public:
	explicit ChatAndStatus();
	~ChatAndStatus();
	void clearChat();

public slots:
	void appendMessage(Players plr, QString text);
	void showPicture(Players plr, PictureStatus::Picture status);

private slots:
	void getText();
	void clearPicture();

signals:
	void getNewMessage(QString text);

private:
	Ui::ChatAndStatus *ui;
	QTimer mTimer;
};

#endif // CHATANDSTATUS_H
