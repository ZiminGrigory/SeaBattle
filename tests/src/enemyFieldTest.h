#ifndef ENEMYFIELDTEST_H
#define ENEMYFIELDTEST_H

#include <QObject>
#include <QtTest/QtTest>

#include "../../src/enemyField.h"

class EnemyFieldTest : public QObject
{
    Q_OBJECT
public:
    explicit EnemyFieldTest(QObject *parent = 0):
        QObject(parent)
    {
    }
    
signals:
    
private slots:
    // test the sequence of emitting of signals after the attack on cell.
    void attackTest()
    {
        EnemyField field;
        EnemyCell* const ptrCell = &field.field[1][2];
        int cellId = 1 * FIELD_ROW_NUM + 2;

        QSignalSpy cellSpy(ptrCell, SIGNAL(attacked()));
        QSignalSpy mapperSpy(&field.mapper, SIGNAL(mapped(int)));
        QSignalSpy fieldSpy(&field, SIGNAL(attacked(int)));

        ptrCell->attack();

        // check that all signals was emitted.
        QCOMPARE(cellSpy.count(), 1);
        QCOMPARE(mapperSpy.count(), 1);
        QCOMPARE(fieldSpy.count(), 1);

        // check id of attacked cell.
        QCOMPARE(fieldSpy.takeFirst().at(0).toInt(), cellId);
    }
    // test case when the attack was over miss.
    void attackResult_MISS_Test()
    {
        EnemyField field;
        field.attack(0);
        field.attackResult(MISS);
        QCOMPARE(field.field[0][0].getAttackStatus(), MISS);
    }
    // test case when the attack was over wounding.
    void attackResult_WOUNDED_Test()
    {
        EnemyField field;
        field.attack(0);
        field.attackResult(WOUNDED);
        QCOMPARE(field.field[0][0].getAttackStatus(), WOUNDED);
    }
    // test case when the attack was over killing.
    void attackResult_KILLED_Test()
    {
        EnemyField field;
        field.attack(0);
        field.attackResult(WOUNDED);
        field.attack(1);
        field.attackResult(KILLED);

        QCOMPARE(field.field[0][0].getAttackStatus(), KILLED);
        QCOMPARE(field.field[0][1].getAttackStatus(), KILLED);
        QCOMPARE(field.field[1][0].getAttackStatus(), MISS);
        QCOMPARE(field.field[1][1].getAttackStatus(), MISS);
        QCOMPARE(field.field[1][2].getAttackStatus(), MISS);
        QCOMPARE(field.field[0][2].getAttackStatus(), MISS);
    }
};

#endif // ENEMYFIELDTEST_H
