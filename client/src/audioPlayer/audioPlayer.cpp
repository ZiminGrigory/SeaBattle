#include "audioPlayer.h"

AudioPlayer::AudioPlayer()
{
    sound = new MediaObject();
    audioOutput = new AudioOutput(Phonon::MusicCategory);
    createPath(sound, audioOutput);

    isMute = false;
}

void AudioPlayer::mute()
{
    isMute = true;
}

void AudioPlayer::playSound(Sounds track)
{
    if (isMute)
        return;

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

void AudioPlayer::playBackground()
{
    if(isMute)
        return;
    sound->setCurrentSource(Phonon::MediaSource("../SeaBattle/client/gui/sounds/sea.wav"));
    sound->play();
}

