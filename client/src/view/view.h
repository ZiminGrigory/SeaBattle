#pragma once
#include <QSharedPointer>
#include "mainwindow.h"
#include "cell.h"

class View : public QObject
{
	Q_OBJECT
public:
	View();
	~View();
	void showPlayerField(QSharedPointer<FieldView> field);
	void showEnemyField(QSharedPointer<FieldView> field);
	void showInfoTab(QSharedPointer<InfoTabView> infoTab);
	QSharedPointer<Field> getPlayerFieldView();
	QSharedPointer<Field> getEnemyFieldView();
	QSharedPointer<TabOfInformation> getInfoTabView();
public slots:
	void setMessage(QString text);
private:
	QSharedPointer<MainWindow> mMainWindow;
	QSharedPointer<FieldView> mPlayerField;
	QSharedPointer<FieldView> mEnemyField;
	QSharedPointer<InfoTabView> mInfoTab;
};
