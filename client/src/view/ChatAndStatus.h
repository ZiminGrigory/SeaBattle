#ifndef CHATANDSTATUS_H
#define CHATANDSTATUS_H

#include <QWidget>
#include "InterfaceChatAndStatus.h"

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

signals:
	void getNewMessage(QString text);

private:
	Ui::ChatAndStatus *ui;
};

#endif // CHATANDSTATUS_H
