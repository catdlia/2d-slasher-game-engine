#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <fstream>
#include <iostream>

class Utils {
public:
    static std::string loadFile(const std::string& filename);
    static void handleError(const std::string& errorMessage);
};

#endif // UTILS_H
