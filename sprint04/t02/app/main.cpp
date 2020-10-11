#include "dragonborn.h"
#include <string>
#include <iostream>


int main(int ac, char** av) {
    if (ac != 2) {
        std::cerr << "usage: ./dragonborn [action]"
                  << std::endl;
        return 1;
    }
    Dragonborn *dovakin = 0;
    std::string cast {av[1]};
    dovakin = new(Dragonborn);

    if (cast == "shout")
        dovakin->executeAction(Dragonborn::Actions::Shout);
    else if (cast == "magic")
        dovakin->executeAction(Dragonborn::Actions::Magic);
    else if (cast == "weapon")
        dovakin->executeAction(Dragonborn::Actions::Weapon);
    else
       std::cerr << "Invalid action" << std::endl;
}
