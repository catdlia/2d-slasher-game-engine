#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <string>

class GameEngine {
public:
    GameEngine();
    ~GameEngine();

    bool initialize();
    void update();
    void render();
    void cleanup();

private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool isRunning;
};

#endif // GAMEENGINE_H
