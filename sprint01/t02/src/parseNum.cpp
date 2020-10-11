#include "visitAll.h"

bool parseNum(std::string str) {
    if (str.size() == 0)
        return true;
    for (int i = 0; i < str.size(); i++)
        if (std::isdigit(str[i]) == false)
            return true;
    return false;
}
