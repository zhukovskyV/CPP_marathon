#include "moveAlong.h"

void moveAlong(int ac, char** av) {
    if (ac == 1) {
        std::cerr << "usage: ./moveAlong [args]" << std::endl;
        exit(1);
    }
    std::vector<std::string> args;
    for (int i = 1; i < ac; i++)
        args.push_back(av[i]);

    std::string str;
    for (auto elem = args.begin(); elem != args.end(); elem++) {
        str = *elem;
        std::transform(str.begin(), str.end(), str.begin(),
                [](unsigned char c) {return std::tolower(c);
        });
        if (str.find("jim") != std::string::npos
        || str.find("mercer") != std::string::npos
        || str.find("emer") != std::string::npos) {
            std::cout << *elem << " move along!" << std::endl;
        }
        str.clear();
    }
}

