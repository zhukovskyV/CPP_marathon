#include "Draugr.h"
#include <string>
#include <iostream>

int onlyOne(int ac, char** av) {
    int av_1 = std::stoi(av[1]);
    if (av_1 < 0 || av_1 > 8)
        throw 1;
    return av_1;
}

std::pair<double, int>moreParametrs(int ac, char** av) {
    if (ac == 3) {
        double av_1 = std::stod(av[2]);
        int av_2 = std::stoi(av[2]);
        return {av_1, av_2};
    }
    if (ac == 4) {
        double av_1 = std::stod(av[2]);
        int av_2 = std::stoi(av[3]);

        if (av_2 > 100)
            throw 1;
        return {av_1, av_2};
    }
    return {0, 0};
}

void run(int ac, const std::pair<double, int>& hpr, int args) {
    if (ac == 2) {
        Draugr draugr;
        draugr.shoutPhrase(args);
    }
    if (ac == 3) {
        Draugr draugr1(hpr.first);
        draugr1.shoutPhrase(args);
        Draugr draugr2(hpr.second);
        draugr2.shoutPhrase(args);
    }
    if (ac == 4) {
        Draugr draugr1(hpr.first, hpr.second);
        draugr1.shoutPhrase(args);
    }

}

int main(int ac, char **av) {
    if (ac < 2 || ac > 4) {
        std::cerr << "usage: ./draugr [shoutNumber] [health] [frostResist]"
                  << std::endl;
        return 1;
    }
    int args;
    std::pair<double, int> hpr;

    try {
        args = onlyOne(ac, av);
    } catch(...) {
        std::cerr << "Invalid shoutNumber"
        << std::endl;
        return 1;
    }
    try {
        hpr = moreParametrs(ac, av);
    } catch(...) {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    run(ac, hpr, args);
    return 0;
}
