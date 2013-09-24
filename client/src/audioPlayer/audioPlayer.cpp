#include "audioPlayer.h"

AudioPlayer::AudioPlayer()
{
//    begin = new QSound (":/sounds/begin.wav");
//    begin->setLoops(3);
//    first = new QSound(":/sounds/first blood.wav");
//    miss = new QSound("C:/programmig/semester 2/SeaBattle/client/gui/sounds/miss.wav");
//    miss->setLoops(1);
//    wounded = new QSound(":/sounds/wounded.wav");
//    killed = new QSound(":/sounds/killed.wav");
//    finish = new QSound(":/sounds/finished.wav");
//    victory = new QSound(":/sounds/victory.wav");
//    defeat = new QSound(":/sounds/defeat.wav");
    sound = new MediaObject();
    audioOutput = new AudioOutput(Phonon::MusicCategory);
    createPath(sound, audioOutput);
//    ao = new AudioOutput(MusicCategory, 0);


}


void AudioPlayer::playSound(Sounds track)
{
    switch (track)
    {
    case (BEGIN_SOUND):
        sound->setCurrentSource(Phonon::MediaSource("C:\programmig\semester 2\SeaBattle\client\gui\sounds\begin.wav"));
        break;
    case(FIRST_BLOOD):
        break;
    case(MISS_SOUND):
        sound->setCurrentSource(Phonon::MediaSource("C:\programmig\semester 2\SeaBattle\client\gui\sounds\miss.wav"));
        break;
    case(WOUNDED_SOUND):

        break;
    case(KILLED_SOUND):

        break;
    case(FINISH_HIM):

        break;
    case(VICTORY_SOUND):

        break;
    case(DEFEAT_SOUND):

        break;

    }
    sound->play();

}

