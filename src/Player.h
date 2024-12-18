#ifndef PLAYER_H
#define PLAYER_H

#include <SDL2/SDL.h>
#include <string>

class Player {
public:
    Player();
    ~Player();

    void handleInput(const SDL_Event& event);
    void update();
    void render(SDL_Renderer* renderer);

private:
    SDL_Texture* texture;
    SDL_Rect srcRect;
    SDL_Rect destRect;
    int x, y;
    int speed;
    bool isAttacking;
};

#endif // PLAYER_H
