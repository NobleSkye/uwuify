#include <fstream>
#include <string>
#include <sstream>

std::string readFileToString(std::string filename) {
    std::ifstream file(filename);
    std::stringstream filebuffer;
    filebuffer << file.rdbuf();
    return filebuffer.str();
}