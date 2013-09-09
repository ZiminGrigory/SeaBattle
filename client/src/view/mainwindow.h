#include <QMainWindow>
#include <QSharedPointer>
#include "cell.h"
#include "field.h"
#include "tabOfInformation.h"
#include "infoTabView.h"
#include "fieldView.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	void setMessage(QString text);
	void showPlayerField(QSharedPointer<Field> field);
	void showEnemyField(QSharedPointer<Field> field);
	void showInfoTab(QSharedPointer<TabOfInformation> infoTab);


private:
	QSharedPointer<Ui::MainWindow> ui;
	QSharedPointer<TabOfInformation> mInfoTab;
};
