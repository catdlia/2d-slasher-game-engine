#include "Utils.h"

std::string Utils::loadFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        handleError("Failed to open file: " + filename);
        return "";
    }

    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();
    return content;
}

void Utils::handleError(const std::string& errorMessage) {
    std::cerr << "Error: " << errorMessage << std::endl;
}
