#include "Enemy.h"
#include <SDL2/SDL_image.h>

Enemy::Enemy() : x(0), y(0), speed(3), isAttacking(false) {
    // Load enemy texture
    SDL_Surface* tempSurface = IMG_Load("assets/enemy.png");
    texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
    SDL_FreeSurface(tempSurface);

    // Set source and destination rectangles
    srcRect = {0, 0, 64, 64};
    destRect = {x, y, 64, 64};
}

Enemy::~Enemy() {
    SDL_DestroyTexture(texture);
}

void Enemy::update() {
    // Update enemy position
    destRect.x = x;
    destRect.y = y;
}

void Enemy::render(SDL_Renderer* renderer) {
    SDL_RenderCopy(renderer, texture, &srcRect, &destRect);
}

void Enemy::handleBehavior() {
    // Handle enemy behavior and attacks
    if (isAttacking) {
        // Perform attack logic
    } else {
        // Perform movement logic
    }
}
