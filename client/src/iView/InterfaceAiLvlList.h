#ifndef INTERFACEAILVLLIST_H
#define INTERFACEAILVLLIST_H

#include <QObject>

class InterfaceAiLvlList : public QObject
{
	Q_OBJECT
public:
	virtual ~InterfaceAiLvlList() {}
signals:
	void buttonExitPushed();
	void buttonVsSimplePushed();
	void buttonVsProPushed();
};

#endif // INTERFACEAILVLLIST_H
