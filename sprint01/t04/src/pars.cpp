#include "stdAlgoV1.h"

bool check(std::string str, std::string sub) {
    if(str.find(sub) == std::string::npos)
        return true;
    return false;
}

void pars(std::forward_list<std::string> names) {
    bool rich = false;
    bool length = false;
    bool vel = true;
    int mel = 0;

    for (std::string item : names) {
        if (check(item, "rich"))
            rich = true;
        if (item.size() == 15)
            length = true;
        if (check(item, "mel"))
            mel++;
        if (vel == true && item[item.length() - 3] == 'v'
            && item[item.length() - 2] == 'e' && item[item.length() - 1] == 'l')
            vel = true;
        else
            vel = false;
    }
    print(rich, length, vel, mel);
}
