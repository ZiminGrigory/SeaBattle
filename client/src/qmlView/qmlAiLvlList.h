#ifndef QMLAILVLLIST_H
#define QMLAILVLLIST_H

#include "InterfaceAiLvlList.h"

class QmlAiLvlList : public InterfaceAiLvlList
{
	Q_OBJECT
public:
	explicit QmlAiLvlList();
signals:
	void buttonExitPushed();
	void buttonVsSimplePushed();
	void buttonVsProPushed();

};

#endif // QMLAILVLLIST_H
