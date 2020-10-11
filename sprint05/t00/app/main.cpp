#include "Draugr.h"
#include <string>
#include <iostream>
#include <limits>


int main(int ac, char **av) {
    if (ac != 2) {
        std::cerr << "usage: ./draugr [shoutNumber]"
                  << std::endl;
        return 1;
    }
    Draugr draugr;

    try {
        draugr.shoutPhrase(std::stoi(av[1]));
    } catch(...) {
        std::cerr << "Invalid shoutNumber"
        << std::endl;
        return 1;
    }
    return 0;
}
