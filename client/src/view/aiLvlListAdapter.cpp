#include "aiLvlListAdapter.h"

AiLvlListAdapter::AiLvlListAdapter(const QSharedPointer<AiLvlList>& adaptee) :
	mAdaptee(adaptee)
{
	connect(mAdaptee.data(), SIGNAL(buttonExitPushed()), this, SIGNAL(buttonExitPushed()));
	connect(mAdaptee.data(), SIGNAL(buttonVsProPushed()), this, SIGNAL(buttonVsProPushed()));
	connect(mAdaptee.data(), SIGNAL(buttonVsSimplePushed()), this, SIGNAL(buttonVsSimplePushed()));
}
