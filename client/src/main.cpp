#include <QObject>

#include "view.h"
#include "gameMaster.h"
#include "humanPlayer.h"
#include "aiPlayerSimple.h"
#include "audioPlayer/audioPlayer.h"

#ifdef QT4
    #include <QtGui>
#elif QT5
    #include <QtWidgets/QApplication>
#endif


int main(int argc, char *argv[])
{


    AudioPlayer * player = new AudioPlayer();

    player->playSound(BEGIN_SOUND);



	QApplication a(argc, argv);
    GameMaster gameMaster(QSharedPointer<View>(new View));
	gameMaster.startGame();
	return a.exec();

}
