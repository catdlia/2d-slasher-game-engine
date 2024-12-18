#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

class Graphics {
public:
    Graphics();
    ~Graphics();

    bool initialize(SDL_Window* window);
    void cleanup();
    void drawSprite(SDL_Texture* texture, SDL_Rect* srcRect, SDL_Rect* destRect);
    void drawText(const std::string& text, int x, int y, SDL_Color color);
    void handleAnimations();

private:
    SDL_Renderer* renderer;
};

#endif // GRAPHICS_H
