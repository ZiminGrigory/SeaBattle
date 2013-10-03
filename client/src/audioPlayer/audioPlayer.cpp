#include "audioPlayer.h"

AudioPlayer::AudioPlayer()
{
    sound = new QMediaPlayer();
    sound->setVolume(50);

    isMute = false;
}

void AudioPlayer::mute()
{
    isMute = true;
}
void AudioPlayer::setVolume(int value)
{
   sound->setVolume(value);
}

void AudioPlayer::playSound(Sounds track)
{
    if (isMute)
        return;

    switch (track)
    {
    case (BEGIN_SOUND):
        sound->setMedia(QUrl::fromLocalFile("../SeaBattle/client/gui/sounds/begin.mp3"));
        break;
    case(FIRST_BLOOD):
         sound->setMedia(QUrl::fromLocalFile("../SeaBattle/client/gui/sounds/first blood.mp3"));
        break;
    case(MISS_SOUND):
         sound->setMedia(QUrl::fromLocalFile("../SeaBattle/client/gui/sounds/miss.mp3"));
        break;
    case(WOUNDED_SOUND):
         sound->setMedia(QUrl::fromLocalFile("../SeaBattle/client/gui/sounds/wounded.mp3"));
        break;
    case(KILLED_SOUND):
         sound->setMedia(QUrl::fromLocalFile("../SeaBattle/client/gui/sounds/killed.mp3"));
        break;
    case(FINISH_HIM):
         sound->setMedia(QUrl::fromLocalFile("../SeaBattle/client/gui/sounds/finish him.mp3"));
        break;
    case(VICTORY_SOUND):
         sound->setMedia(QUrl::fromLocalFile("../SeaBattle/client/gui/sounds/victory.mp3"));
        break;
    case(DEFEAT_SOUND):
         sound->setMedia(QUrl::fromLocalFile("../SeaBattle/client/gui/sounds/defeat.mp3"));
        break;
    }
    sound->play();

}

void AudioPlayer::playBackground()
{
    if(isMute)
        return;
     sound->setMedia(QUrl::fromLocalFile("../SeaBattle/client/gui/sounds/sea.mp3"));
    sound->play();
}

