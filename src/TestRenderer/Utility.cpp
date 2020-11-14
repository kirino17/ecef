#include "Utility.h"

std::string LoadJavascript(const char* filename) {
    std::string extension;
    std::ifstream file(filename, std::ios_base::in | std::ios_base::binary);
    file.seekg(0, file.end);
    int length = file.tellg();
    file.seekg(0, file.beg);
    extension.resize(length);
    file.read(&extension[0], length);
    file.close();
    return std::move(extension);
}