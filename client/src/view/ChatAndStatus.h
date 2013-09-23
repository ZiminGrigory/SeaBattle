#ifndef CHATANDSTATUS_H
#define CHATANDSTATUS_H

#include <QWidget>

namespace Ui {
class ChatAndStatus;
}

class ChatAndStatus : public QWidget
{
	Q_OBJECT

public:
	explicit ChatAndStatus(QWidget *parent = 0);
	~ChatAndStatus();

private:
	Ui::ChatAndStatus *ui;
};

#endif // CHATANDSTATUS_H
