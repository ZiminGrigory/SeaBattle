#include <QQmlComponent>

#include "qmlStartMenu.h"

const QString QmlStartMenu::componentUrl = "qml/qml/StartMenu.qml";

QmlStartMenu::QmlStartMenu(QQmlEngine* engine, const QSharedPointer<QmlWidgetAppender>& widgetAppeder):
	mWidgetAppender(widgetAppeder)
{
	QQmlComponent component(engine, QUrl::fromLocalFile(componentUrl));
	mStartMenu = QSharedPointer<QQuickItem>(qobject_cast<QQuickItem*>(component.create()));

	connect(mStartMenu.data(), SIGNAL(vsAiClicked()), this, SIGNAL(buttonVsPcPushed()));
	connect(mStartMenu.data(), SIGNAL(vsPlayerClicked()), this, SIGNAL(buttonVsPlayerPushed()));
	connect(mStartMenu.data(), SIGNAL(settingsClicked()), this, SIGNAL(buttonSettingsPushed()));
	connect(mStartMenu.data(), SIGNAL(quitClicked()), this, SIGNAL(buttonExitPushed()));
}

void QmlStartMenu::show()
{
	mWidgetAppender->show(mStartMenu);
}

void QmlStartMenu::hide()
{
	mWidgetAppender->hide(mStartMenu);
}


