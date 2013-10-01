#ifndef INTERFACEAILVLLIST_H
#define INTERFACEAILVLLIST_H
#include <QWidget>

class InterfaceAiLvlList: public QWidget
{
public:
	InterfaceAiLvlList(QWidget *parent = 0): QWidget(parent){}

signals:
	void buttonExitPushed();
	void buttonVsSimplePushed();
	void buttonVsProPushed();
};

#endif // INTERFACEAILVLLIST_H
