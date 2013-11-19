#include <QQmlComponent>
#include <QDebug>
#include <QScreen>

#include "qmlStartMenu.h"
#include "qmlViewTypes.h"

const QString QmlStartMenu::componentUrl = "qml/qml/StartMenu.qml";

QmlStartMenu::QmlStartMenu(QObject* widget):
	mStartMenu(widget),
	mWidgetAppender(widgetAppeder)
{
	// коннектим сигналы, объявленные в qml файле, с сигналами нашего интерфейса
	connect(mStartMenu, SIGNAL(vsAiClicked()), this, SIGNAL(buttonVsPcPushed()));
	connect(mStartMenu, SIGNAL(vsPlayerClicked()), this, SIGNAL(buttonVsPlayerPushed()));
	connect(mStartMenu, SIGNAL(settingsClicked()), this, SIGNAL(buttonSettingsPushed()));
	connect(mStartMenu, SIGNAL(quitClicked()), this, SIGNAL(buttonExitPushed()));


}

void QmlStartMenu::show()
{
	// показывание/скрытие qml объектов инкапсулировано в отдельном классе
	mWidgetAppender->show(mStartMenu);
}

void QmlStartMenu::hide()
{
	mWidgetAppender->hide(mStartMenu);
}


