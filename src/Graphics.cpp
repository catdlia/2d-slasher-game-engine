#include "Graphics.h"
#include <SDL2/SDL_ttf.h>

Graphics::Graphics() : renderer(nullptr) {}

Graphics::~Graphics() {
    cleanup();
}

bool Graphics::initialize(SDL_Window* window) {
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        return false;
    }
    return true;
}

void Graphics::cleanup() {
    if (renderer) {
        SDL_DestroyRenderer(renderer);
        renderer = nullptr;
    }
}

void Graphics::drawSprite(SDL_Texture* texture, SDL_Rect* srcRect, SDL_Rect* destRect) {
    SDL_RenderCopy(renderer, texture, srcRect, destRect);
}

void Graphics::drawText(const std::string& text, int x, int y, SDL_Color color) {
    TTF_Font* font = TTF_OpenFont("path/to/font.ttf", 24);
    if (!font) {
        return;
    }

    SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), color);
    if (!surface) {
        TTF_CloseFont(font);
        return;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    TTF_CloseFont(font);

    if (!texture) {
        return;
    }

    SDL_Rect destRect = { x, y, surface->w, surface->h };
    SDL_RenderCopy(renderer, texture, nullptr, &destRect);
    SDL_DestroyTexture(texture);
}

void Graphics::handleAnimations() {
    // Handle animations here
}
