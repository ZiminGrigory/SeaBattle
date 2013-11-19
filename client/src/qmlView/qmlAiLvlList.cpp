#include "qmlAiLvlList.h"

const QString QmlAiLvlList::componentUrl = "qml/qml/AiLvlMenu.qml";

QmlAiLvlList::QmlAiLvlList(QObject* widget) :
	mAiLvlList(widget),
	mWidgetAppender(widgetAppeder)
{
	// коннектим сигналы, объявленные в qml файле, с сигналами нашего интерфейса
	connect(mAiLvlList, SIGNAL(vsAiSimpleClicked()), this, SIGNAL(buttonVsSimplePushed()));
	connect(mAiLvlList, SIGNAL(vsAihardClicked()), this, SIGNAL(buttonVsProPushed()));
	connect(mAiLvlList, SIGNAL(quitClicked()), this, SIGNAL(buttonExitPushed()));
}

void QmlAiLvlList::show()
{
	mWidgetAppender->show(mAiLvlList);
}

void QmlAiLvlList::hide()
{
	mWidgetAppender->hide(mAiLvlList);
}
