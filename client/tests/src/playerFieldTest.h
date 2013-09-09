#ifndef PLAYERFIELDTEST_H
#define PLAYERFIELDTEST_H

#include <QObject>
#include <QtTest/QtTest>

#include "../../src/playerField.h"
#include "../../src/cellShip.h"

class PlayerFieldTest : public QObject
{
    Q_OBJECT
public:
    explicit PlayerFieldTest(QObject *parent = 0):
        QObject(parent)
    {}
private slots:
    void setShipTest1()
    {
        QSharedPointer<Ship> ship(new CellShip<1>());
        PlayerField field;
        field.setShip(0, true, ship);
        QCOMPARE(field.getShip(0), ship);
    }
    void setShipTest2()
    {
        QSharedPointer<Ship> ship(new CellShip<4>());
        PlayerField field;
        field.setShip(0, false, ship);
        QCOMPARE(field.getShip(0), ship);
        QCOMPARE(field.getShip(10), ship);
        QCOMPARE(field.getShip(20), ship);
        QCOMPARE(field.getShip(30), ship);
    }
};

#endif // PLAYERFIELDTEST_H
