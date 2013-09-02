#ifndef FLEETINSTALLERTEST_H
#define FLEETINSTALLERTEST_H

#include <QObject>
#include <QtDebug>
#include <QtTest/QtTest>

#include "../../src/fleetInstaller.h"
#include "../../src/fleetFactory.h"
#include "../../src/playerField.h"

class FleetInstallerTest : public QObject
{
    Q_OBJECT
public:
    explicit FleetInstallerTest(QObject *parent = 0):
        QObject(parent)
    {}
private slots:
    // check the placement on free field with full fleet
    // it must be OK
    void shipPlaced_OK_Test()
    {
        PlayerField field;
        FleetFactory factory;
        FleetInstaller inst(factory.createFleet(), &field);

        QSignalSpy spy(&inst, SIGNAL(placementResult(PlacementStatus)));
        inst.shipPlaced(QPair<int, int>(0, 3));

        QCOMPARE(spy.count(), 1);
        FleetInstaller::PlacementStatus status = qvariant_cast<FleetInstaller::PlacementStatus>(spy.at(0).at(0));
        QCOMPARE(status, FleetInstaller::OK);
    }
    // test the placement of two ships to crossing areas.
    void shipPlaced_CELL_OCCUPIED_Test()
    {
        PlayerField field;
        FleetFactory factory;
        FleetInstaller inst(factory.createFleet(), &field);

        QSignalSpy spy(&inst, SIGNAL(placementResult(PlacementStatus)));
        inst.shipPlaced(QPair<int, int>(0, 3));
        inst.shipPlaced(QPair<int, int>(14, 24));

        QCOMPARE(spy.count(), 2);
        FleetInstaller::PlacementStatus status = qvariant_cast<FleetInstaller::PlacementStatus>(spy.at(1).at(0));
        QCOMPARE(status, FleetInstaller::CELL_OCCUPIED);
    }
    // test the case, when the player has not suitable ship for the placement.
    void shipPlaced_HAVE_NOT_SHIP_Test()
    {
        PlayerField field;
        FleetFactory factory;
        FleetInstaller inst(factory.createFleet(), &field);

        QSignalSpy spy(&inst, SIGNAL(placementResult(PlacementStatus)));
        inst.shipPlaced(QPair<int, int>(0, 3));
        // there isn't two 4-cells ships
        // it must emit signal with HAVE_NOT_SHIP parameter.
        inst.shipPlaced(QPair<int, int>(0, 3));

        QCOMPARE(spy.count(), 2);
        FleetInstaller::PlacementStatus status = qvariant_cast<FleetInstaller::PlacementStatus>(spy.at(1).at(0));
        QCOMPARE(status, FleetInstaller::HAVE_NOT_SHIP);
    }
    // test case when slot recieves coordinates out of field
    void shipPlaced_UNCORRECT_COORDINATES_Test()
    {
        PlayerField field;
        FleetFactory factory;
        FleetInstaller inst(factory.createFleet(), &field);

        QSignalSpy spy(&inst, SIGNAL(placementResult(PlacementStatus)));
        inst.shipPlaced(QPair<int, int>(-1, 1));

        QCOMPARE(spy.count(), 1);
        FleetInstaller::PlacementStatus status = qvariant_cast<FleetInstaller::PlacementStatus>(spy.at(0).at(0));
        QCOMPARE(status, FleetInstaller::UNCORRECT_COORDINATES);
    }
    // test case when slot recieves coordinates which form curve line
    void shipPlaced_NOT_LINE_Test()
    {
        PlayerField field;
        FleetFactory factory;
        FleetInstaller inst(factory.createFleet(), &field);

        QSignalSpy spy(&inst, SIGNAL(placementResult(PlacementStatus)));
        inst.shipPlaced(QPair<int, int>(0, 11));

        QCOMPARE(spy.count(), 1);
        FleetInstaller::PlacementStatus status = qvariant_cast<FleetInstaller::PlacementStatus>(spy.at(0).at(0));
        QCOMPARE(status, FleetInstaller::NOT_LINE);
    }
};

#endif // FLEETINSTALLERTEST_H
