#ifndef AUDIOPLAYER_H
#define AUDIOPLAYER_H

#include <Phonon/MediaObject>
#include <Phonon/AudioOutput>
#include <Phonon/MediaSource>

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


using namespace Phonon;

class AudioPlayer
{

public:
    AudioPlayer();
    void playSound(Sounds track);
private:
    MediaObject * sound;
    AudioOutput* audioOutput;



};

#endif // AUDIOPLAYER_H
