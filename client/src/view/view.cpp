#include "view.h"
#include <QDebug>
View::View()
{
	mMainWindow = QSharedPointer<MainWindow>(new MainWindow);
	mPlayerField = QSharedPointer<FieldView>(new FieldView);
	mEnemyField = QSharedPointer<FieldView>(new FieldView) ;
	mInfoTab = QSharedPointer<InfoTabView>(new InfoTabView) ;
	mMainWindow.data()->show();
}

View::~View()
{
}

void View::showPlayerField(QSharedPointer<FieldView> field)
{
	mMainWindow->showPlayerField(field);
}

void View::showEnemyField(QSharedPointer<FieldView> field)
{
	mMainWindow->showEnemyField(field);
}

void View::showInfoTab(QSharedPointer<InfoTabView> infoTab)
{
	mMainWindow->showInfoTab(infoTab);
}

QSharedPointer<Field> View::getPlayerFieldView()
{
	return mPlayerField;
}

QSharedPointer<Field> View::getEnemyFieldView()
{
	return mEnemyField;
}

QSharedPointer<TabOfInformation> View::getInfoTabView()
{
	return mInfoTab;
}

void View::setMessage(QString text)
{
	mMainWindow->setMessage(text);
}

