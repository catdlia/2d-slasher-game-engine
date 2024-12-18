#ifndef LEVEL_H
#define LEVEL_H

#include <string>
#include <vector>
#include "Graphics.h"

class Level {
public:
    Level();
    ~Level();

    bool load(const std::string& filename);
    void render(Graphics& graphics);

private:
    std::vector<std::vector<int>> tiles;
};

#endif // LEVEL_H
