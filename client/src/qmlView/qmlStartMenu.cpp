#include <QQmlComponent>

#include "qmlStartMenu.h"

const QString QmlStartMenu::componentUrl = "qml/qml/StartMenu.qml";

QmlStartMenu::QmlStartMenu(QQmlEngine* engine, const QSharedPointer<QmlWidgetAppender>& widgetAppeder):
	mWidgetAppender(widgetAppeder)
{
	// сначала создаём QQmlComponent из qml файла
	// QQmlComponent - это прототип для всех будущих qml объектов этого типа (см. паттерн Prototype)
	QQmlComponent component(engine, QUrl::fromLocalFile(componentUrl));
	// на основе компонента создаём уже сам объект, с которым будем работать
	mStartMenu = QSharedPointer<QQuickItem>(qobject_cast<QQuickItem*>(component.create()));
	//mStartMenu->setProperty("")
	// коннектим сигналы, объявленные в qml файле, с сигналами нашего интерфейса
	connect(mStartMenu.data(), SIGNAL(vsAiClicked()), this, SIGNAL(buttonVsPcPushed()));
	connect(mStartMenu.data(), SIGNAL(vsPlayerClicked()), this, SIGNAL(buttonVsPlayerPushed()));
	connect(mStartMenu.data(), SIGNAL(settingsClicked()), this, SIGNAL(buttonSettingsPushed()));
	connect(mStartMenu.data(), SIGNAL(quitClicked()), this, SIGNAL(buttonExitPushed()));
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


