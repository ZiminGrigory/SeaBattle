#ifndef AUDIOPLAYER_H
#define AUDIOPLAYER_H

#include <QMediaPlayer>



enum Sounds
{
    BEGIN_SOUND,
    FIRST_BLOOD,
    MISS_SOUND,
    WOUNDED_SOUND,
    KILLED_SOUND,
    FINISH_HIM,
    VICTORY_SOUND,
    DEFEAT_SOUND
};


class AudioPlayer: public QObject
{
Q_OBJECT
public:
	AudioPlayer();
	void playBackground();
	void playSound(Sounds track);
public slots:
	void setVolume(int value);
	void mute(bool isMute);
private:
	QString path;
	bool mIsMute;
    QMediaPlayer * sound;

};

#endif // AUDIOPLAYER_H
