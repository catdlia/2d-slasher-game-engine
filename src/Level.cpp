#include "Level.h"
#include "Graphics.h"
#include <fstream>
#include <sstream>

Level::Level() {}

Level::~Level() {}

bool Level::load(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        return false;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::vector<int> row;
        std::istringstream iss(line);
        int tile;
        while (iss >> tile) {
            row.push_back(tile);
        }
        tiles.push_back(row);
    }

    file.close();
    return true;
}

void Level::render(Graphics& graphics) {
    for (size_t y = 0; y < tiles.size(); ++y) {
        for (size_t x = 0; x < tiles[y].size(); ++x) {
            // Render each tile using the graphics object
            graphics.drawTile(tiles[y][x], x * TILE_SIZE, y * TILE_SIZE);
        }
    }
}
