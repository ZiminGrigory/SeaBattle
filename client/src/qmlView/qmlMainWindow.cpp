#include <QQuickItem>
#include <QScreen>

#include "qmlMainWindow.h"

QmlMainWindow::QmlMainWindow():
	mWidgetAppender(new QmlWidgetAppender(&mQuickView, mQuickView.screen()))
{
	// ImageProvider специальный класс, который позволяет qml объектам подгружать картинки, из ресурсов, например
	ImageProvider* imageProvider = new ImageProvider();
	// добавляем его в наш qml движок
	mQuickView.engine()->addImageProvider("provider", imageProvider);


	mQuickView.setMainQmlFile("qml/qml/Main.qml");

	// сразу создаём все компоненты интерфейса

	mRoot = mQuickView.rootObject();
#ifdef Q_OS_ANDROID
	mRoot->setWidth(mQuickView.screen()->availableSize().width());
	mRoot->setHeight(mQuickView.screen()->availableSize().height());
	mQuickView.resize(mQuickView.screen()->availableSize());
#else
	mRoot->setWidth(QML_WINDOW_SIZE.width());
	mRoot->setHeight(QML_WINDOW_SIZE.height());
	mQuickView.resize(QML_WINDOW_SIZE);
#endif



	mAiLvlList = QSharedPointer<QmlAiLvlList>(new QmlAiLvlList(mRoot->findChild<QObject*>("AiLvlMenu")));
	mBattleWidget = QSharedPointer<QmlBattleWidget>(new QmlBattleWidget(mRoot->findChild<QObject*>("Battle")));
	mConnectWidget = QSharedPointer<QmlConnectWidget>(new QmlConnectWidget(mRoot->findChild<QObject*>("ConnectWidget")));
	mStartMenu = QSharedPointer<QmlStartMenu>(new QmlStartMenu(mRoot->findChild<QObject*>("StartMenu")));
	mSettingsMenu = QSharedPointer<QmlSettingsMenu>(new QmlSettingsMenu(mRoot->findChild<QObject*>("SettingsMenu")));
}

QmlMainWindow::~QmlMainWindow()
{
	if (mCurrentQmlObject)
	{
		mCurrentQmlObject->hide();
	}
}

void QmlMainWindow::showWidget(Widgets widget)
{
	// сначала прячем текущий qml
	if (mCurrentQmlObject)
	{
		QMetaObject::invokeMethod(mQuickView.rootObject(), "hideAllWidgets");
	}
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
//	switch (widget)
//	{
//		// показываем новый
//		case START_MENU:
//			mStartMenu->hide();
//			break;
//		case AI_MENU:
//			mAiLvlList->hide();
//			break;
//		case SETTINGS:
//			mSettingsMenu->hide();
//			break;
//		case CONNECT:
//			mConnectWidget->hide();
//			break;
//		case BATTLE:
//			mBattleWidget->hide();
//		break;
//	}
}

void QmlMainWindow::showMain()
{
	showWidget(START_MENU);
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
