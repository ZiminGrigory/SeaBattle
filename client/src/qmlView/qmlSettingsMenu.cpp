#include "qmlSettingsMenu.h"

#include <QString>
#include <QDebug>


QmlSettingsMenu::QmlSettingsMenu(QObject* widget) :
	mSettingsWidget(widget)
{
	connect(mSettingsWidget, SIGNAL(volume(int)), this, SLOT(volumeHandler(int)));
	connect(mSettingsWidget, SIGNAL(ipAndPort(QString, QString)), this, SLOT(ipAndPortHandler(QString,QString)));
	connect(mSettingsWidget, SIGNAL(quitClicked()), SIGNAL(buttonBackPushed()));
	mSettingsWidget->setProperty("ip", settings.value(SettingsKey::IP_KEY));
	mSettingsWidget->setProperty("port", settings.value(SettingsKey::PORT_KEY));
	mSettingsWidget->setProperty("currentVolumeState", settings.value(SettingsKey::VOLUME_KEY).toInt() / 25);
}

void QmlSettingsMenu::volumeHandler(int lvl)
{
	qDebug()<< lvl;
	if (lvl == 0){
		emit mute(true);
		emit volumeChanched(0);
	} else {
		emit mute(false);
		emit volumeChanched(lvl * 25);
	}
}

void QmlSettingsMenu::ipAndPortHandler(QString ip, QString port)
{
	qDebug() << ip << port;
	settings.setValue(SettingsKey::PORT_KEY, quint16(port.toInt()));
	settings.setValue(SettingsKey::IP_KEY, ip);
}
