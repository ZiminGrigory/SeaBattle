#ifndef AILVLLIST_H
#define AILVLLIST_H

#include <QWidget>
#include "InterfaceAiLvlList.h"

namespace Ui {
class AiLvlList;
}

class AiLvlList : public InterfaceAiLvlList, public QWidget
{
	Q_OBJECT
public:
	explicit AiLvlList();
	~AiLvlList();

signals:
	void buttonExitPushed();
	void buttonVsSimplePushed();
	void buttonVsProPushed();

private:
	Ui::AiLvlList *ui;
};

#endif // AILVLLIST_H
