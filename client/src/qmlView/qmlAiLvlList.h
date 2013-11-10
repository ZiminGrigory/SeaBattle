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
	QmlAiLvlList(QQmlEngine* engine, const QSharedPointer<QmlWidgetAppender>& widgetAppeder);

	void show();
	void hide();
signals:
	void buttonExitPushed();
	void buttonVsSimplePushed();
	void buttonVsProPushed();

private:
	static const QString componentUrl;

	QSharedPointer<QQuickItem> mAiLvlList;
	QSharedPointer<QmlWidgetAppender> mWidgetAppender;
};

#endif // QMLAILVLLIST_H
