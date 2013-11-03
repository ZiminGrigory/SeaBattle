#ifndef INTERFACECHATANDSTATUS_H
#define INTERFACECHATANDSTATUS_H
#include <QString>
#include <QWidget>
#include "types.h"

class InterfaceChatAndStatus: public QWidget
{
public:
	InterfaceChatAndStatus(QWidget *parent = 0): QWidget(parent){}
	virtual void clearChat() = 0;

public slots:
	virtual void appendMessage(Players plr, QString text) = 0;
	virtual void showPicture(Players plr, PictureStatus::Picture status) = 0;

signals:
	void getNewMessage(QString text);
};

#endif // INTERFACECHATANDSTATUS_H
