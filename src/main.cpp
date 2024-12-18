#include "GameEngine.h"

int main(int argc, char* argv[]) {
    GameEngine gameEngine;

    if (!gameEngine.initialize()) {
        return -1;
    }

    bool isRunning = true;
    while (isRunning) {
        isRunning = gameEngine.update();
        gameEngine.render();
    }

    gameEngine.cleanup();
    return 0;
}
