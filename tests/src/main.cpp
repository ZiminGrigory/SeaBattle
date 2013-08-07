#include <QtCore/QCoreApplication>

#include "enemyFieldTest.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    
    EnemyFieldTest enemyFieldTest;
    QTest::qExec(&enemyFieldTest);

    return a.exec();
}
