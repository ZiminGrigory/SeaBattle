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
        sound->setCurrentSource(Phonon::MediaSource("../SeaBattle/client/gui/sounds/begin.wav"));
        break;
    case(FIRST_BLOOD):
        sound->setCurrentSource(Phonon::MediaSource("../SeaBattle/client/gui/sounds/first blood.wav"));
        break;
    case(MISS_SOUND):
        sound->setCurrentSource(Phonon::MediaSource("../SeaBattle/client/gui/sounds/miss.wav"));
        break;
    case(WOUNDED_SOUND):
        sound->setCurrentSource(Phonon::MediaSource("../SeaBattle/client/gui/sounds/wounded.wav"));
        break;
    case(KILLED_SOUND):
        sound->setCurrentSource(Phonon::MediaSource("../SeaBattle/client/gui/sounds/killed.wav"));
        break;
    case(FINISH_HIM):
        sound->setCurrentSource(Phonon::MediaSource("../SeaBattle/client/gui/sounds/finish him.wav"));
        break;
    case(VICTORY_SOUND):
        sound->setCurrentSource(Phonon::MediaSource("../SeaBattle/client/gui/sounds/victory.wav"));
        break;
    case(DEFEAT_SOUND):
        sound->setCurrentSource(Phonon::MediaSource("../SeaBattle/client/gui/sounds/defeat.wav"));
        break;
    }
    sound->play();

}

