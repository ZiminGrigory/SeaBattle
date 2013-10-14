#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include <QObject>

#include "player.h"
#include "fleetInstaller.h"
#include "BattleWidget.h"

// for test purpose
class HumanPlayerTest;

class HumanPlayer : public Player
{
    Q_OBJECT
public:
	explicit HumanPlayer(const QSharedPointer<GameField> &plrField,
						 const QSharedPointer<GameField>& enmField,
						 const QSharedPointer<InterfaceField>& _plrFieldView,
						 const QSharedPointer<InterfaceField>& _enmFieldView,
						 const QSharedPointer<InterfaceInfoTab> &_infoTab,
						 const QSharedPointer<InterfaceChatAndStatus> &_chat,
						 QObject *parent = 0);
    
    // for test purpose
    friend class HumanPlayerTest;

    /**
      *
      */
    void installFleet();
public slots:
    /**
      * This slot do nothing because it need to wait until player made a choise.
      */
    void turn();
protected slots:
    /**
      * This slot connected with cellWasAttacked() signal of Field view.
      */
    virtual void cellWasAttacked(int id);
private slots:
    /**
      * Reemit fleetInstalled signal with this parametr.
      */
    void reEmitFleetInstalled();
	void needAutoInstallFleet();
    //void deleteShip(int id);

protected:
	QSharedPointer<InterfaceField> plrFieldView;
	QSharedPointer<InterfaceField> enmFieldView;

	QSharedPointer<InterfaceInfoTab> infoTab;
	QSharedPointer<InterfaceChatAndStatus> mChat;
	bool myTurn;
};

#endif // HUMANPLAYER_H
