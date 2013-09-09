#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include <QObject>

#include "player.h"
#include "fleetInstaller.h"
#include "view.h"

// for test purpose
class HumanPlayerTest;

class HumanPlayer : public Player
{
    Q_OBJECT
public:
    explicit HumanPlayer(const QSharedPointer<GameField>& plrField,
                         const QSharedPointer<GameField>& enmField,
                         const QSharedPointer<Field>& _fieldView,
                         QObject* parent = 0);
    
    // for test purpose
    friend class HumanPlayerTest;

    /**
      *
      */
    void installFleet(const FleetInstaller& fleetInstaller);
public slots:
    /**
      * This slot do nothing because it need to wait until player made a choise.
      */
    void turn();

private slots:
    /**
      * This slot connected with cellWasAttacked() signal of Field view.
      */
	void cellWasAttacked(int id);
    /**
      * This slot connected with fleetInstalled() signal of fleetInstaller
      */
    void fleetInstalledSlot();
    //void deleteShip(int id);
private:
    QSharedPointer<Field> fieldView;
};

#endif // HUMANPLAYER_H
