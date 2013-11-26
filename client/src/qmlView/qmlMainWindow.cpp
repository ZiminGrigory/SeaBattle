#include <QQuickItem>
#include <QScreen>

#include "qmlMainWindow.h"

QmlMainWindow::QmlMainWindow()
{

#ifdef Q_OS_ANDROID
	mQuickView.resize(mQuickView.screen()->availableSize());
	mQuickView.contentOrientation()
#else
	mQuickView.resize(QML_WINDOW_SIZE);
#endif
	mQuickView.setResizeMode(QQuickView::SizeRootObjectToView);

	// ImageProvider специальный класс, который позволяет qml объектам подгружать картинки, из ресурсов, например
	ImageProvider* imageProvider = new ImageProvider();
	// добавляем его в наш qml движок
	mQuickView.engine()->addImageProvider("provider", imageProvider);

	mQuickView.setMainQmlFile("qml/qml/Main.qml");

	mRoot = mQuickView.rootObject();

	mAiLvlList = QSharedPointer<QmlAiLvlList>(new QmlAiLvlList(mRoot->findChild<QObject*>("AiLvlMenu")));
	mBattleWidget = QSharedPointer<QmlBattleWidget>(new QmlBattleWidget(mRoot->findChild<QObject*>("Battle")));
	mConnectWidget = QSharedPointer<QmlConnectWidget>(new QmlConnectWidget(mRoot->findChild<QObject*>("ConnectWidget")));
	mStartMenu = QSharedPointer<QmlStartMenu>(new QmlStartMenu(mRoot->findChild<QObject*>("StartMenu")));
	mSettingsMenu = QSharedPointer<QmlSettingsMenu>(new QmlSettingsMenu(mRoot->findChild<QObject*>("SettingsMenu")));
}

QmlMainWindow::~QmlMainWindow()
{
}

void QmlMainWindow::showWidget(Widgets widget)
{
	// сначала прячем текущий qml
	QMetaObject::invokeMethod(mRoot, "hideAllWidgets");
	switch (widget)
	{
		// показываем новый
		case BATTLE:
			mRoot->setProperty("state", "Battle");
		break;
		case START_MENU:
			mRoot->setProperty("state", "StartMenu");
			break;
		case AI_MENU:
			mRoot->setProperty("state", "AiLvlMenu");
			break;
		case SETTINGS:
			mRoot->setProperty("state", "SettingsMenu");
			break;
		case CONNECT:
			mRoot->setProperty("state", "ConnectWidget");
			break;
	}
}

void QmlMainWindow::hideWidget(Widgets widget)
{
	Q_UNUSED(widget);

	QMetaObject::invokeMethod(mRoot, "hideAllWidgets");
}

void QmlMainWindow::showMain()
{
	mQuickView.showExpanded();
}

QSharedPointer<InterfaceAiLvlList> QmlMainWindow::getInterfaceAiLvlList()
{
	return mAiLvlList;
}

QSharedPointer<InterfaceBattleWidget> QmlMainWindow::getInterfaceBattleWidget()
{
	return mBattleWidget;
}

QSharedPointer<InterfaceConnectWidget> QmlMainWindow::getInterfaceConnectWidget()
{
	return mConnectWidget;
}

QSharedPointer<InterfaceStartMenu> QmlMainWindow::getInterfaceStartMenu()
{
	return mStartMenu;
}

QSharedPointer<InterfaceSettingsMenu> QmlMainWindow::getInterfaceSettingsMenu()
{
	return mSettingsMenu;
}
