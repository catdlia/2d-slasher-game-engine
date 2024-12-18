#include "Player.h"
#include <SDL2/SDL_image.h>

Player::Player() : x(0), y(0), speed(5), isAttacking(false) {
    // Load player texture
    SDL_Surface* tempSurface = IMG_Load("assets/player.png");
    texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
    SDL_FreeSurface(tempSurface);

    // Set source and destination rectangles
    srcRect = {0, 0, 64, 64};
    destRect = {x, y, 64, 64};
}

Player::~Player() {
    SDL_DestroyTexture(texture);
}

void Player::handleInput(const SDL_Event& event) {
    if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.sym) {
            case SDLK_w:
                y -= speed;
                break;
            case SDLK_s:
                y += speed;
                break;
            case SDLK_a:
                x -= speed;
                break;
            case SDLK_d:
                x += speed;
                break;
            case SDLK_SPACE:
                isAttacking = true;
                break;
        }
    } else if (event.type == SDL_KEYUP) {
        if (event.key.keysym.sym == SDLK_SPACE) {
            isAttacking = false;
        }
    }
}

void Player::update() {
    // Update player position
    destRect.x = x;
    destRect.y = y;
}

void Player::render(SDL_Renderer* renderer) {
    SDL_RenderCopy(renderer, texture, &srcRect, &destRect);
}
