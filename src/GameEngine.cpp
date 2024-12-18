#include "GameEngine.h"

GameEngine::GameEngine() : window(nullptr), renderer(nullptr), isRunning(false) {}

GameEngine::~GameEngine() {
    cleanup();
}

bool GameEngine::initialize() {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
        return false;
    }

    window = SDL_CreateWindow("2D Slasher Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    if (!window) {
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        return false;
    }

    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
        return false;
    }

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        return false;
    }

    if (TTF_Init() == -1) {
        return false;
    }

    isRunning = true;
    return true;
}

void GameEngine::update() {
    // Update game logic here
}

void GameEngine::render() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // Render game objects here

    SDL_RenderPresent(renderer);
}

void GameEngine::cleanup() {
    if (renderer) {
        SDL_DestroyRenderer(renderer);
        renderer = nullptr;
    }

    if (window) {
        SDL_DestroyWindow(window);
        window = nullptr;
    }

    Mix_CloseAudio();
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}
