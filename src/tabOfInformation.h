#ifndef TABOFINFORMATION_H
#define TABOFINFORMATION_H

#include <QWidget>
#include "types.h"
namespace Ui {
class TabOfInformation;
}

class TabOfInformation : public QWidget
{
	Q_OBJECT
	
public:
	explicit TabOfInformation(QWidget *parent = 0);
	~TabOfInformation();
	
private:
	Ui::TabOfInformation *ui;
};

#endif // TABOFINFORMATION_H
