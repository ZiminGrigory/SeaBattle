#ifndef STARTMENU_H
#define STARTMENU_H

#include <QWidget>

namespace Ui {
class StartMenu;
}

class StartMenu : public QWidget
{
	Q_OBJECT

public:
	StartMenu();
	~StartMenu();

signals:
	void buttonVsPlayerPushed();
	void buttonVsPcPushed();
	void buttonExitPushed();
	void buttonSettingsPushed();

private:
	Ui::StartMenu *ui;
};

#endif // STARTMENU_H
