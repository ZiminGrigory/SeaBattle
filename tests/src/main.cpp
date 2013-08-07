#include <QtCore/QCoreApplication>

#include "enemyFieldTest.h"
#include "aiPlayerTest.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    
    EnemyFieldTest enemyFieldTest;
    QTest::qExec(&enemyFieldTest);

    AIPlayerTest aiPlayerTest;
    QTest::qExec(&aiPlayerTest);

    return a.exec();
}
