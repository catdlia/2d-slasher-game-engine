#include "Audio.h"

Audio::Audio() {}

Audio::~Audio() {
    cleanup();
}

bool Audio::initialize() {
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        return false;
    }
    return true;
}

void Audio::playSoundEffect(const std::string& file) {
    Mix_Chunk* soundEffect = loadSoundEffect(file);
    if (soundEffect) {
        Mix_PlayChannel(-1, soundEffect, 0);
        Mix_FreeChunk(soundEffect);
    }
}

void Audio::playMusic(const std::string& file) {
    Mix_Music* music = loadMusic(file);
    if (music) {
        Mix_PlayMusic(music, -1);
        Mix_FreeMusic(music);
    }
}

void Audio::cleanup() {
    Mix_CloseAudio();
}

Mix_Chunk* Audio::loadSoundEffect(const std::string& file) {
    return Mix_LoadWAV(file.c_str());
}

Mix_Music* Audio::loadMusic(const std::string& file) {
    return Mix_LoadMUS(file.c_str());
}
