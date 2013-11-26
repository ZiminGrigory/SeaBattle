#ifndef QMLAILVLLIST_H
#define QMLAILVLLIST_H

#include <QQuickItem>
#include <QString>

#include "InterfaceAiLvlList.h"

class QmlAiLvlList : public InterfaceAiLvlList
{
	Q_OBJECT
public:
	QmlAiLvlList(QObject* widget);

signals:
	void buttonExitPushed();
	void buttonVsSimplePushed();
	void buttonVsProPushed();

private:

	QObject* mAiLvlList;
};

#endif // QMLAILVLLIST_H
