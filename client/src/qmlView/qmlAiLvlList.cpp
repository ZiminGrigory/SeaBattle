#include "qmlAiLvlList.h"

const QString QmlAiLvlList::componentUrl = "qml/qml/AiLvlMenu.qml";

QmlAiLvlList::QmlAiLvlList(QQmlEngine* engine, const QSharedPointer<QmlWidgetAppender>& widgetAppeder) :
	mWidgetAppender(widgetAppeder)
{
	QQmlComponent component(engine, QUrl::fromLocalFile(componentUrl));
	mAiLvlList = QSharedPointer<QQuickItem>(qobject_cast<QQuickItem*>(component.create()));
}

void QmlAiLvlList::show()
{
	mWidgetAppender->show(mAiLvlList);
}

void QmlAiLvlList::hide()
{
	mWidgetAppender->hide(mAiLvlList);
}
