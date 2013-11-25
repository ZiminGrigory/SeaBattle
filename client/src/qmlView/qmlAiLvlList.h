#ifndef QMLAILVLLIST_H
#define QMLAILVLLIST_H

#include <QQuickItem>
#include <QString>

#include "InterfaceAiLvlList.h"
#include "qmlRootWidget.h"
#include "qmlWidgetAppender.h"

class QmlAiLvlList : public InterfaceAiLvlList, public QmlRootWidget
{
	Q_OBJECT
public:
	QmlAiLvlList(QObject* widget);

	void show();
	void hide();
signals:
	void buttonExitPushed();
	void buttonVsSimplePushed();
	void buttonVsProPushed();

private:

	QObject* mAiLvlList;
	QSharedPointer<QmlWidgetAppender> mWidgetAppender;
};

#endif // QMLAILVLLIST_H
