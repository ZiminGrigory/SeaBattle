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

	#ifdef Q_OS_ANDROID
		mQuickView.resize(mQuickView.screen()->availableSize());
	#else
		mQuickView.resize(QML_WINDOW_SIZE);
	#endif

	// сразу создаём все компоненты интерфейса
	mAiLvlList = QSharedPointer<QmlAiLvlList>(new QmlAiLvlList(mQuickView.engine(), mWidgetAppender));
	mBattleWidget = QSharedPointer<QmlBattleWidget>(new QmlBattleWidget(mQuickView.engine(), mWidgetAppender));
	mConnectWidget = QSharedPointer<QmlConnectWidget>(new QmlConnectWidget(mQuickView.engine(), mWidgetAppender));
	mStartMenu = QSharedPointer<QmlStartMenu>(new QmlStartMenu(mQuickView.engine(), mWidgetAppender));
	mSettingsMenu = QSharedPointer<QmlSettingsMenu>(new QmlSettingsMenu(mQuickView.engine(), mWidgetAppender));
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
		mCurrentQmlObject->hide();
	}
	switch (widget)
	{
		// показываем новый
		case BATTLE:
			mBattleWidget->show();
		break;
		case START_MENU:
			mStartMenu->show();
			break;
		case AI_MENU:
			mAiLvlList->show();
			break;
		case SETTINGS:
			mSettingsMenu->show();
			break;
		case CONNECT:
			mConnectWidget->show();
			break;
	}
}

void QmlMainWindow::hideWidget(Widgets widget)
{
	switch (widget)
	{
		// показываем новый
		case START_MENU:
			mStartMenu->hide();
			break;
		case AI_MENU:
			mAiLvlList->hide();
			break;
		case SETTINGS:
			mSettingsMenu->hide();
			break;
		case CONNECT:
			mConnectWidget->hide();
			break;
		case BATTLE:
			mBattleWidget->hide();
		break;
	}
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
