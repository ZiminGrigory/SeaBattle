#include <QQuickItem>

#include "qmlMainWindow.h"

QmlMainWindow::QmlMainWindow():
	mWidgetAppender(new QmlWidgetAppender(&mQuickView))

{
	// ImageProvider специальный класс, который позволяет qml объектам подгружать картинки, из ресурсов, например
	ImageProvider* imageProvider = new ImageProvider();
	// добавляем его в наш qml движок
	mQuickView.engine()->addImageProvider("provider", imageProvider);
	mQuickView.resize(QML_WINDOW_SIZE);

	// сразу создаём все компоненты интерфейса
	mAiLvlList = QSharedPointer<QmlAiLvlList>(new QmlAiLvlList(mQuickView.engine(), mWidgetAppender));
	mBattleWidget = QSharedPointer<QmlBattleWidget>(new QmlBattleWidget);
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
