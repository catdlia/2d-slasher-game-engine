#ifndef AUDIO_H
#define AUDIO_H

#include <SDL2/SDL_mixer.h>
#include <string>

class Audio {
public:
    Audio();
    ~Audio();

    bool initialize();
    void playSoundEffect(const std::string& file);
    void playMusic(const std::string& file);
    void cleanup();

private:
    Mix_Chunk* loadSoundEffect(const std::string& file);
    Mix_Music* loadMusic(const std::string& file);
};

#endif // AUDIO_H
