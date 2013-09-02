#include <QMainWindow>
#include "cell.h"
#include "field.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
	void test(QVector<Cell*> vector);
	void testAttack(Cell *item);
	void testBuildShip(int x, int y);
private:
    Ui::MainWindow *ui;
	Field *fieldFirst;
	Field *fieldSecond;
};
