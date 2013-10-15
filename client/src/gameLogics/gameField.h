#ifndef GAMEFIELD_H
#define GAMEFIELD_H

#include <QObject>
#include <QSharedPointer>
#include <QStack>

#include "ship.h"
#include "types.h"
#include "gameCell.h"
#include "textureAnalyzer.h"
#include "BattleWidget.h"
#include "fleetFactory.h"
#include "fleetInstaller.h"

class FleetInstaller;

/**
  * Abstract class for enemy & player field.
  * It defines the interface for access to fields.
  */
class GameField : public QObject
{
    Q_OBJECT
public:
    GameField(const QSharedPointer<InterfaceField>& fieldView,
              const QSharedPointer<InterfaceInfoTab>& infoTabView = QSharedPointer<InterfaceInfoTab>(NULL));

    virtual ~GameField()
    {}


    /**
      * Return pointer to ship placed on cell with passed id.
      */
    QSharedPointer<Ship> getShip(int id);
    /**
      * Return fleet assigned with this field.
      */
    QVector< QSharedPointer<Ship> > getFleet();
    /**
      *
      */
    QVector< QSharedPointer<Ship> > getInstalledFleet();
    /**
      * Attack cell with id given by argument. Return the result of attack.
      */
	virtual AttackStatus attack(int id);
    /**
      * Check could this cell being attack.
      */
    bool attackable(int id);
public slots:
    /**
      * Sets ship on field. To define position of placement this slot uses two id,
      * which should be on the single straight.
      */
    PlacementStatus setShip(int firstId, int secondId);
    /**
      * The same as previous, but with different interface.
      *
      * @var id top left id of cell which on ship will placed
      * @var size size of ship
      * @var orientation true - horizontal, false - vertical
      */
    PlacementStatus setShip(int id, int size, bool orientation);
    /**
      * Set ship.
      * This slot assumes that id, size, and ship are correct, so there are not any checks.
      * Use this slot quite carefully.
      *
      * @param id id of cell where ship will placed (if ship occupied few cells, it cell will be top or left,
      *     depend on orientation.
      * @param orientation orientation of ship (for multicell ships).
      *     true - horizontal,
      *     false - vertical
      * @param ship ship for placement.
      */
    void setShip(int id, bool orientation, QSharedPointer<Ship> ship);
    /**
      * This slot remove the ship from field if cell with recieved id contained some ship.
      */
    void deleteShip(int id);
    /**
      * This method delete all ship installed on field.
      */
    void removeInstalledFleet();
    /**
      *
      */
    void checkIsFleetReady();
signals:
    /**
      * Signal emitted after shipPlaced() slot ended work.
      * Signal contains result of last try to place ship on cells.
      */
    void shipPlacementResult(PlacementStatus res);
    /**
      * This signal emits when all fleet was correctly installed.
      */
    void fleetInstalled();
protected:
	int position(QVector<int> vector, int id);
	void markKilled(int i, int j);
    virtual void repaintCell(int row, int column, int partOfShip, int shipSize, bool orientation);

    typedef QPair<int, int> Coord;
	QSharedPointer<InterfaceField> view;
    QSharedPointer<TextureAnalyzer> textureAnalyzer;

	GameCell field[FIELD_ROW_NUM][FIELD_COL_NUM];
    //QVector<int> fleet;
    QVector< QSharedPointer<Ship> > fleet;
    QSharedPointer<FleetInstaller> flInst;

};


#endif // GAMEFIELD_H
