#ifndef ENEMY_H
#define ENEMY_H

#include <SDL2/SDL.h>
#include <string>

class Enemy {
public:
    Enemy();
    ~Enemy();

    void update();
    void render(SDL_Renderer* renderer);
    void handleBehavior();

private:
    SDL_Texture* texture;
    SDL_Rect srcRect;
    SDL_Rect destRect;
    int x, y;
    int speed;
    bool isAttacking;
};

#endif // ENEMY_H
