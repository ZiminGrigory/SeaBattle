#include <QMainWindow>
#include "cell.h"
#include "field.h"
#include "tabOfInformation.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	void paintStartDialog();
	void changeCounter(NameOfShips ship, int count);
    void paintCell(int player, int id, Textures texture);
	void changeTurn(int player);

	~MainWindow();

public slots:
	void attackOnCell(int id);
	void buildShip(int firstId, int secondId);

signals:
	void deleteShip(int id);
	void createShip(int firstId, int secondId);
	void attackCell(int id);
	void readyToFight();

private slots:
	void paintEnemyField();
	void deleteShipOnCell(int id);

private:
	Ui::MainWindow *ui;
	Field *fieldFirst;
	Field *fieldSecond;
	TabOfInformation *infoTab;
};
