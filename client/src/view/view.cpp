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

void View::showPlayerField()
{
    mMainWindow->showPlayerField(mPlayerField->getField());
}

void View::showEnemyField()
{
    mMainWindow->showEnemyField(mEnemyField->getField());
}

void View::showInfoTab()
{
    mMainWindow->showInfoTab(mInfoTab->getInfoTab());
}

QSharedPointer<FieldView> View::getPlayerFieldView()
{
	return mPlayerField;
}

QSharedPointer<FieldView> View::getEnemyFieldView()
{
	return mEnemyField;
}

QSharedPointer<InfoTabView> View::getInfoTabView()
{
	return mInfoTab;
}

void View::setMessage(QString text)
{
	mMainWindow->setMessage(text);
}

