#ifndef AILVLLIST_H
#define AILVLLIST_H

#include <QWidget>

namespace Ui {
class AiLvlList;
}

class AiLvlList : public QWidget
{
	Q_OBJECT

public:
	explicit AiLvlList(QWidget *parent = 0);
	~AiLvlList();

private:
	Ui::AiLvlList *ui;
};

#endif // AILVLLIST_H
