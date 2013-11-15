#include "qmlSettingsMenu.h"

#include <QString>
#include <QDebug>

const QString QmlSettingsMenu::componentUrl = "qml/qml/SettingsMenu.qml";

QmlSettingsMenu::QmlSettingsMenu(QQmlEngine* engine, const QSharedPointer<QmlWidgetAppender>& widgetAppeder) :
	mWidgetAppender(widgetAppeder)
{
	QQmlComponent component(engine, QUrl::fromLocalFile(componentUrl));
	mSettingsWidget = QSharedPointer<QQuickItem>(qobject_cast<QQuickItem*>(component.create()));
	connect(mSettingsWidget.data(), SIGNAL(volume(int)), this, SLOT(volumeHandler(int)));
	connect(mSettingsWidget.data(), SIGNAL(ipAndPort(QString, QString)), this, SLOT(ipAndPortHandler(QString,QString)));
	connect(mSettingsWidget.data(), SIGNAL(quitClicked()), SIGNAL(buttonBackPushed()));
	mSettingsWidget->setProperty("ip", settings.value(SettingsKey::IP_KEY));
	mSettingsWidget->setProperty("port", settings.value(SettingsKey::PORT_KEY));
	mSettingsWidget->setProperty("currentVolumeState", settings.value(SettingsKey::VOLUME_KEY).toInt() / 25);
}

void QmlSettingsMenu::show()
{
	mWidgetAppender->show(mSettingsWidget);
}

void QmlSettingsMenu::hide()
{
	mWidgetAppender->hide(mSettingsWidget);
}

void QmlSettingsMenu::volumeHandler(int lvl)
{
	qDebug()<< lvl;
	if (lvl == 0){
		settings.setValue(SettingsKey::MUTE_KEY, true);
		settings.setValue(SettingsKey::VOLUME_KEY, 0);
		emit mute(true);
	} else {
		settings.setValue(SettingsKey::VOLUME_KEY, lvl * 25);
		emit volumeChanched(lvl * 25);
	}
}

void QmlSettingsMenu::ipAndPortHandler(QString ip, QString port)
{
	qDebug() << ip << port;
	settings.setValue(SettingsKey::PORT_KEY, quint16(port.toInt()));
	settings.setValue(SettingsKey::IP_KEY, ip);
}
