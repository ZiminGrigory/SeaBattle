#ifndef AILVLLISTADAPTER_H
#define AILVLLISTADAPTER_H

#include <QSharedPointer>

#include "InterfaceAiLvlList.h"
#include "AiLvlList.h"

class AiLvlListAdapter : public InterfaceAiLvlList
{
	Q_OBJECT
public:
	AiLvlListAdapter(const QSharedPointer<AiLvlList>& adaptee);
signals:
	void buttonExitPushed();
	void buttonVsSimplePushed();
	void buttonVsProPushed();
private:
	QSharedPointer<AiLvlList> mAdaptee;
};

#endif // AILVLLISTADAPTER_H
