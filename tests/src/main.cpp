#include <QtCore/QCoreApplication>

#include "enemyFieldTest.h"
#include "PlayerFieldTest.h"
#include "fleetInstallerTest.h"
#include "playerTest.h"
#include "aiPlayerTest.h"
#include "gameMasterTest.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    
    EnemyFieldTest enemyFieldTest;
    QTest::qExec(&enemyFieldTest);

    PlayerFieldTest playerFieldTest;
    QTest::qExec(&playerFieldTest);

    FleetInstallerTest fleetInstallerTest;
    QTest::qExec(&fleetInstallerTest);

    PlayerTest playerTest;
    QTest::qExec(&playerTest);

    AIPlayerTest aiPlayerTest;
    QTest::qExec(&aiPlayerTest);

    GameMasterTest gameMasterTest;
    QTest::qExec(&gameMasterTest);

    return a.exec();
}
