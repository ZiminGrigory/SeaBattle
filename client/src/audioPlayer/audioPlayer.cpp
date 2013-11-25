#include "audioPlayer.h"
#include "QDir"
#include "types.h"
#include <QSound>

AudioPlayer::AudioPlayer()
{
	sound = new QMediaPlayer();
	settings.setValue((SettingsKey::VOLUME_KEY), 100);
	if (settings.contains(SettingsKey::VOLUME_KEY)){
		int vol = settings.value(SettingsKey::VOLUME_KEY).toInt();
		sound->setVolume(vol);
	}
	else{
		sound->setVolume(50);
		settings.setValue((SettingsKey::VOLUME_KEY), 50);
	}
	if (settings.contains(SettingsKey::MUTE_KEY)){
		mIsMute = settings.value(SettingsKey::MUTE_KEY).toBool();
	}
	else{
		settings.setValue((SettingsKey::MUTE_KEY), 0);
		mIsMute = false;
	}
	path = QDir::currentPath();
}

void AudioPlayer::mute(bool isMute)
{
	mIsMute = isMute;
	settings.setValue((SettingsKey::MUTE_KEY), isMute);
}
void AudioPlayer::setVolume(int value)
{
	settings.setValue((SettingsKey::VOLUME_KEY), value);
	sound->setVolume(value);
}

void AudioPlayer::playSound(Sounds track)
{
	if (mIsMute)
        return;
    switch (track)
    {
    case (BEGIN_SOUND):
		sound->setMedia(QUrl("qrc:/sounds/begin.mp3"));
        break;
    case(FIRST_BLOOD):
		 sound->setMedia(QUrl("qrc:/sounds/first blood.mp3"));
        break;
    case(MISS_SOUND):
		 sound->setMedia(QUrl("qrc:/sounds2/miss.mp3"));
        break;
    case(WOUNDED_SOUND):
		 sound->setMedia(QUrl("qrc:/sounds/wounded.mp3"));
        break;
    case(KILLED_SOUND):
		 sound->setMedia(QUrl("qrc:/sounds/killed.mp3"));
        break;
    case(FINISH_HIM):
		 sound->setMedia(QUrl("qrc:/sounds/finish him.mp3"));
        break;
    case(VICTORY_SOUND):
		 sound->setMedia(QUrl("qrc:/sounds/victory.mp3"));
        break;
    case(DEFEAT_SOUND):
		 sound->setMedia(QUrl("qrc:/sounds/defeat.mp3"));
        break;
    case(SHIP_SET_SOUND):
		sound->setMedia(QUrl("qrc:/sounds/ship_set.mp3"));
        break;
    case(SHIP_SET_ERR_SOUND):
		sound->setMedia(QUrl("qrc:/sounds/ship_set_error.mp3"));
    }
    sound->play();

}

void AudioPlayer::playBackground()
{
	if(mIsMute)
        return;
	 sound->setMedia(QUrl::fromLocalFile("qrc:/sounds/sea.mp3"));
    sound->play();
}

