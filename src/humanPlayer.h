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
	explicit HumanPlayer(View *view, QObject *parent = 0);
    
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

private slots:
	void cellWasAttacked(int id);
	void deleteShip(int id);
private:
	View *view;
};

#endif // HUMANPLAYER_H
