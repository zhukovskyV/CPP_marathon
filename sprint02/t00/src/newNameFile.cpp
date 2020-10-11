#include "uniqueWords.h"

std::string newNameFile(const std::string& str) {
    std::stringstream oldFile(str);
    std::string temp;
    std::string newFile;

    getline(oldFile, newFile, '.');
    newFile += "_mod";
    getline(oldFile, temp);
    if (temp.size() != 0)
        newFile += ".";
    newFile += temp;
    return newFile;
}

