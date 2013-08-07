#ifndef HUMANPLAYERTEST_H
#define HUMANPLAYERTEST_H

#include <QObject>
#include <QtTest/QtTest>

#include "../../src/humanPlayer.h"

class HumanPlayerTest : public QObject
{
    Q_OBJECT
private slots:
    // test that after calling of attack slot of EnemyField player emits turnMade() signal.
    // (it
    void turnTest()
    {

    }
};

#endif // HUMANPLAYERTEST_H
