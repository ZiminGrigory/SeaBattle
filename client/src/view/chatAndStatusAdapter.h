#ifndef CHATANDSTATUSADAPTER_H
#define CHATANDSTATUSADAPTER_H

#include <QSharedPointer>

#include "InterfaceChatAndStatus.h"
#include "ChatAndStatus.h"

class ChatAndStatusAdapter : public InterfaceChatAndStatus
{
	Q_OBJECT
public:
	ChatAndStatusAdapter(const QSharedPointer<ChatAndStatus> adaptee);
	void clearChat();

public slots:
	void appendMessage(Players plr, QString text);
	void showPicture(Players plr, PictureStatus::Picture status);

signals:
	void getNewMessage(QString text);
private:
	QSharedPointer<ChatAndStatus> mAdaptee;
};

#endif // CHATANDSTATUSADAPTER_H
