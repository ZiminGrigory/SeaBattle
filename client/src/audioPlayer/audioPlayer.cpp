#include "audioPlayer.h"
#include "QDir"
#include "types.h"

AudioPlayer::AudioPlayer()
{
    sound = new QMediaPlayer();
	if (settings.contains(SettingsKey::VOLUME_KEY)){
		int vol = settings.value(SettingsKey::VOLUME_KEY).toInt();
		sound->setVolume(vol);
	}
	else{
		sound->setVolume(50);
		settings.setValue((SettingsKey::VOLUME_KEY), 50);
	}
	if (settings.contains(SettingsKey::MUTE_KEY)){
		isMute = settings.value(SettingsKey::MUTE_KEY).toBool();
	}
	else{
		settings.setValue((SettingsKey::MUTE_KEY), 0);
		isMute = false;
	}
	path = QDir::currentPath();
}

void AudioPlayer::mute()
{
    isMute = true;
	settings.setValue((SettingsKey::MUTE_KEY), 0);
	sound->setMuted(true);
}
void AudioPlayer::setVolume(int value)
{
	settings.setValue((SettingsKey::VOLUME_KEY), value);
	sound->setVolume(value);
}

void AudioPlayer::playSound(Sounds track)
{
    if (isMute)
        return;

    switch (track)
    {
    case (BEGIN_SOUND):
		sound->setMedia(QUrl::fromLocalFile(path + "/gui/sounds/begin.mp3"));
        break;
    case(FIRST_BLOOD):
		 sound->setMedia(QUrl::fromLocalFile(path + "/gui/sounds/first blood.mp3"));
        break;
    case(MISS_SOUND):
		 sound->setMedia(QUrl::fromLocalFile(path + "/gui/sounds/miss.mp3"));
        break;
    case(WOUNDED_SOUND):
		 sound->setMedia(QUrl::fromLocalFile(path + "/gui/sounds/wounded.mp3"));
        break;
    case(KILLED_SOUND):
		 sound->setMedia(QUrl::fromLocalFile(path + "/gui/sounds/killed.mp3"));
        break;
    case(FINISH_HIM):
		 sound->setMedia(QUrl::fromLocalFile(path + "/gui/sounds/finish him.mp3"));
        break;
    case(VICTORY_SOUND):
		 sound->setMedia(QUrl::fromLocalFile(path + "/gui/sounds/victory.mp3"));
        break;
    case(DEFEAT_SOUND):
		 sound->setMedia(QUrl::fromLocalFile(path + "/gui/sounds/defeat.mp3"));
        break;
    }
    sound->play();

}

void AudioPlayer::playBackground()
{
    if(isMute)
        return;
	 sound->setMedia(QUrl::fromLocalFile(path + "/gui/sounds/sea.mp3"));
    sound->play();
}

