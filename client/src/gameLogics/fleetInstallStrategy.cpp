#include "fleetInstallStrategy.h"
#include "QDebug"

FleetInstallStrategy::FleetInstallStrategy(const QSharedPointer<GameField>& myField):
field(myField){
    qsrand(QTime::currentTime().msec());
}

QVector<QPair<int, int> > FleetInstallStrategy::getStrategy()
{
    int x = qrand() % 12;
    qDebug() << "strategy is " << x;
    switch (x)
    {
    case 0:
        return QVector<QPair<int, int> >()
                << QPair<int, int> (0, 30) << QPair<int, int> (50, 60)<< QPair<int, int> (80, 90)
                 << QPair<int, int> (2, 22)<< QPair<int, int> (42, 62) << QPair<int, int> (82, 92);
    case 1:
        return QVector<QPair<int, int> >()
                   << QPair<int, int> (0, 30)<< QPair<int, int> (50, 70)<< QPair<int, int> (90, 91)<<
                     QPair<int, int> (2, 4)<< QPair<int, int> (6, 7)<< QPair<int, int> (9, 19);
    case 2:
        return QVector<QPair<int, int> >()
                    <<QPair<int, int> (0, 30)<< QPair<int, int> (50, 60)<< QPair<int, int> (80, 90)<<
                     QPair<int, int> (9, 29)<< QPair<int, int> (49, 59)<< QPair<int, int> (79, 99);
    case 3:
        return QVector<QPair<int, int> >()
                    <<QPair<int, int> (0, 1)<< QPair<int, int> (3, 4)<< QPair<int, int> (6, 9)<<
                     QPair<int, int> (20, 21)<< QPair<int, int> (23, 25)<< QPair<int, int> (27, 29);
    case 4:
        return QVector<QPair<int, int> >()
                <<QPair<int, int> (0, 10)<< QPair<int, int> (2, 4)<< QPair<int, int> (6, 9)<<
                 QPair<int, int> (29, 49)<< QPair<int, int> (69, 79)<< QPair<int, int> (98, 99);
    case 5:
        return QVector<QPair<int, int> >()
                <<QPair<int, int> (0, 1)<< QPair<int, int> (3, 4)<< QPair<int, int> (6, 9)<<
                 QPair<int, int> (90, 92)<< QPair<int, int> (94, 95)<< QPair<int, int> (97, 99);
    case 6:
        return QVector<QPair<int, int> >()
                <<QPair<int, int> (0, 20)<< QPair<int, int> (40, 50)<< QPair<int, int> (70, 90)<<
                 QPair<int, int> (9, 19)<< QPair<int, int> (39, 49)<< QPair<int, int> (69, 99);
    case 7:
        return QVector<QPair<int, int> >()
                <<QPair<int, int> (8, 9)<< QPair<int, int> (29, 49)<< QPair<int, int> (69, 99)<<
                 QPair<int, int> (80, 90)<< QPair<int, int> (92, 93)<< QPair<int, int> (95, 97);
    case 8:
        return QVector<QPair<int, int> >()
                <<QPair<int, int> (7, 17)<< QPair<int, int> (37, 57)<< QPair<int, int> (77, 97)<<
                 QPair<int, int> (9, 19)<< QPair<int, int> (39, 49)<< QPair<int, int> (69, 99);
    case 9:
        return QVector<QPair<int, int> >()
                <<QPair<int, int> (0, 1)<< QPair<int, int> (20, 30)<< QPair<int, int> (50, 70)<<
                 QPair<int, int> (90, 93)<< QPair<int, int> (95, 97)<< QPair<int, int> (89, 99);
    case 10:
        return QVector<QPair<int, int> >()
                <<QPair<int, int> (0, 2)<< QPair<int, int> (4, 5)<< QPair<int, int> (7, 9)<<
                 QPair<int, int> (90, 93)<< QPair<int, int> (95, 96)<< QPair<int, int> (98, 99);
    case 11:
        return QVector<QPair<int, int> >()
                <<QPair<int, int> (70, 72)<< QPair<int, int> (74, 76)<< QPair<int, int> (78, 79)<<
                 QPair<int, int> (90, 93)<< QPair<int, int> (95, 96)<< QPair<int, int> (98, 99);
    }
    return QVector<QPair<int, int> > ();
}

void FleetInstallStrategy::installFleet()
{
    strategy = getStrategy();
    int size = strategy.size();
    for (int i  = 0; i < size; i++)
    {
        field->setShip(strategy.at(i).first, strategy.at(i).second);
    }
    int id;
    for (int i = 0; i < 4; i++)
    {
        do
        {
            id = qrand()%100;
        }
        while(field->setShip(id, id) != OK);
		qDebug() << id;
    }
}
