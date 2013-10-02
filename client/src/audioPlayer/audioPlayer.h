#ifndef AUDIOPLAYER_H
#define AUDIOPLAYER_H
#include <QMediaPlayer.h>



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


class AudioPlayer
{

public:
    AudioPlayer();
    void playSound(Sounds track);
    void mute();
    void playBackground();
    void setVolume(int value);
private:
    bool isMute;
    QMediaPlayer * sound;

};

#endif // AUDIOPLAYER_H
