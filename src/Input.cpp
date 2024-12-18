#include "Input.h"

Input::Input() {
    keyboardState = SDL_GetKeyboardState(nullptr);
    mouseState = SDL_GetMouseState(&mouseX, &mouseY);
}

Input::~Input() {}

void Input::processEvent(const SDL_Event& event) {
    if (event.type == SDL_KEYDOWN || event.type == SDL_KEYUP) {
        keyboardState = SDL_GetKeyboardState(nullptr);
    } else if (event.type == SDL_MOUSEBUTTONDOWN || event.type == SDL_MOUSEBUTTONUP) {
        mouseState = SDL_GetMouseState(&mouseX, &mouseY);
    }
}

bool Input::isKeyPressed(SDL_Scancode key) {
    return keyboardState[key];
}

bool Input::isMouseButtonPressed(Uint8 button) {
    return mouseState & SDL_BUTTON(button);
}

int Input::getMouseX() {
    return mouseX;
}

int Input::getMouseY() {
    return mouseY;
}
