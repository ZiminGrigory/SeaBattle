#include <QQmlComponent>
#include <QDebug>
#include <QScreen>

#include "qmlStartMenu.h"
#include "qmlViewTypes.h"


QmlStartMenu::QmlStartMenu(QObject* widget):
	mStartMenu(widget)
{
	// коннектим сигналы, объявленные в qml файле, с сигналами нашего интерфейса
	connect(mStartMenu, SIGNAL(vsAiClicked()), this, SIGNAL(buttonVsPcPushed()));
	connect(mStartMenu, SIGNAL(vsPlayerClicked()), this, SIGNAL(buttonVsPlayerPushed()));
	connect(mStartMenu, SIGNAL(settingsClicked()), this, SIGNAL(buttonSettingsPushed()));
	connect(mStartMenu, SIGNAL(quitClicked()), this, SIGNAL(buttonExitPushed()));
}
void QmlStartMenu::show()
{
}

void QmlStartMenu::hide()
{
}

void QmlStartMenu::slo()
{
	qDebug() << "signal from qml";
}


