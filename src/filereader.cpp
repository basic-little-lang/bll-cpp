#include "include/filereader.hpp"
#include <string>
#include <fstream>

std::string* filereader::read_file_to_string(const std::string& path) {

    std::ifstream file;

    file.open(path);

    if (file.is_open() && !file.fail()) {
        std::string* out = new std::string;

        while (file) {
            out->push_back(file.get());
        }

        file.close();

        return out;
    }

    file.close();

    return nullptr;

}
