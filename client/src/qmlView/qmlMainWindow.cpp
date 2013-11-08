#include <QQuickItem>

#include "qmlMainWindow.h"

QmlMainWindow::QmlMainWindow()
{
	ImageProvider* imageProvider = new ImageProvider();
	mQuickView.engine()->addImageProvider("provider", imageProvider);

	mAiLvlList = QSharedPointer<QmlAiLvlList>(new QmlAiLvlList);
	mBattleWidget = QSharedPointer<QmlBattleWidget>(new QmlBattleWidget);
	mConnectWidget = QSharedPointer<QmlConnectWidget>(new QmlConnectWidget);
	mStartMenu = QSharedPointer<QmlStartMenu>(new QmlStartMenu(mQuickView.engine()));
	mSettingsMenu = QSharedPointer<QmlSettingsMenu>(new QmlSettingsMenu);
}

QmlMainWindow::~QmlMainWindow()
{
	if (mCurrentQmlObject)
	{
		mCurrentQmlObject->setParent(NULL);
	}
}

void QmlMainWindow::showWidget(Widgets widget)
{
	if (mCurrentQmlObject)
	{
		mCurrentQmlObject->setParent(NULL);
	}
	switch (widget)
	{
		case START_MENU:
			mStartMenu->getQmlObject()->setParentItem(mQuickView.contentItem());
			break;

	}
}

void QmlMainWindow::hideWidget(Widgets widget)
{

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
