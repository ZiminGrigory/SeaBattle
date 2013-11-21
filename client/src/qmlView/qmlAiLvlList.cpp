#include "qmlAiLvlList.h"

const QString QmlAiLvlList::componentUrl = "qml/qml/AiLvlMenu.qml";

QmlAiLvlList::QmlAiLvlList(QQmlEngine* engine, const QSharedPointer<QmlWidgetAppender>& widgetAppeder) :
	mWidgetAppender(widgetAppeder)
{
	QQmlComponent component(engine, QUrl::fromLocalFile(componentUrl));
	mAiLvlList = QSharedPointer<QQuickItem>(qobject_cast<QQuickItem*>(component.create()));
	// коннектим сигналы, объявленные в qml файле, с сигналами нашего интерфейса
	connect(mAiLvlList.data(), SIGNAL(vsAiSimpleClicked()), this, SIGNAL(buttonVsSimplePushed()));
	connect(mAiLvlList.data(), SIGNAL(vsAihardClicked()), this, SIGNAL(buttonVsProPushed()));
	connect(mAiLvlList.data(), SIGNAL(quitClicked()), this, SIGNAL(buttonExitPushed()));
}

void QmlAiLvlList::show()
{
	mWidgetAppender->show(mAiLvlList);
}

void QmlAiLvlList::hide()
{
	mWidgetAppender->hide(mAiLvlList);
}
