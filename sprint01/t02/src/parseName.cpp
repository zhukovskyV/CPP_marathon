#include "visitAll.h"

bool parseName(std::string str) {
    if (str.size() == 0)
        return true;
    for (int i = 0; i < str.size(); i++)
        if (std::isalpha(str[i]) == 0 && std::isspace(str[i]) == 0)
            return true;
    return false;
}