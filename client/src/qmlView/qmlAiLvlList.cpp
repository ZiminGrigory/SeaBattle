#include "qmlAiLvlList.h"


QmlAiLvlList::QmlAiLvlList(QObject* widget) :
	mAiLvlList(widget)
{
	// коннектим сигналы, объявленные в qml файле, с сигналами нашего интерфейса
	connect(mAiLvlList, SIGNAL(vsAiSimpleClicked()), this, SIGNAL(buttonVsSimplePushed()));
	connect(mAiLvlList, SIGNAL(vsAihardClicked()), this, SIGNAL(buttonVsProPushed()));
	connect(mAiLvlList, SIGNAL(quitClicked()), this, SIGNAL(buttonExitPushed()));
}
