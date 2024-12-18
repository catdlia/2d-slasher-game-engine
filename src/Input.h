#ifndef INPUT_H
#define INPUT_H

#include <SDL2/SDL.h>

class Input {
public:
    Input();
    ~Input();

    void processEvent(const SDL_Event& event);
    bool isKeyPressed(SDL_Scancode key);
    bool isMouseButtonPressed(Uint8 button);
    int getMouseX();
    int getMouseY();

private:
    const Uint8* keyboardState;
    Uint32 mouseState;
    int mouseX, mouseY;
};

#endif // INPUT_H
