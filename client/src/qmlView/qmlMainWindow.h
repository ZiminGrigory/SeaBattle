#ifndef QMLMAINWINDOW_H
#define QMLMAINWINDOW_H

#include "InterfaceMainWindow.h"
#include "imageprovider.h"
#include "qtquick2applicationviewer.h"

#include "qmlAiLvlList.h"
#include "qmlBattleWidget.h"
#include "qmlConnectWidget.h"
#include "qmlStartMenu.h"
#include "qmlSettingsMenu.h"
#include "qmlViewTypes.h"
#include "qmlRootWidget.h"
#include "qmlWidgetAppender.h"

class QmlMainWindow : public InterfaceMainWindow
{
public:
	QmlMainWindow();
	~QmlMainWindow();
	void showWidget(Widgets widget);
	void hideWidget(Widgets widget);
	void showMain();
	QSharedPointer<InterfaceAiLvlList> getInterfaceAiLvlList();
	QSharedPointer<InterfaceBattleWidget> getInterfaceBattleWidget();
	QSharedPointer<InterfaceConnectWidget> getInterfaceConnectWidget();
	QSharedPointer<InterfaceStartMenu> getInterfaceStartMenu();
	QSharedPointer<InterfaceSettingsMenu> getInterfaceSettingsMenu();
private:
	/*
	 * Эта штука отвечает за отображение qml компонентов в окошке.
	 */
	QtQuick2ApplicationViewer mQuickView;
	QQuickItem* mRoot;

	QSharedPointer<QmlAiLvlList> mAiLvlList;
	QSharedPointer<QmlBattleWidget> mBattleWidget;
	QSharedPointer<QmlConnectWidget> mConnectWidget;
	QSharedPointer<QmlStartMenu> mStartMenu;
	QSharedPointer<QmlSettingsMenu> mSettingsMenu;

	/*
	 * Отображаемый в данный момент объект.
	 */
	QSharedPointer<QmlRootWidget> mCurrentQmlObject;
	/*
	 * Эта штука передаётся в конструкторе всем qml виджетам, чтобы они умели себя добавлять в окно.
	 */
	QSharedPointer<QmlWidgetAppender> mWidgetAppender;
};

#endif // QMLMAINWINDOW_H
