#include "src/ImperialSoldier.h"
#include "src/StormcloakSoldier.h"
#include "src/Sword.h"
#include "src/Axe.h"
#include <string>
#include <iostream>


void validation(int ac, char **av) {
    if (ac != 3) {
        std::cerr << "usage: ./imperialVsStormcloak [dmgOfSword] [dmgOfAxe]"
                  << std::endl;
        exit(1);
    }
    int av_1 = std::stoi(av[1]);
    int av_2 = std::stoi(av[2]);

    if (av_1 < 10 || av_1 > 20 || av_2 < 10 || av_2 > 20) {
        std::cerr << "Damage has to be in a range of 10-20 points."
        << std::endl;
        exit(1);
    }
}

int main(int ac, char** av) {
    validation(ac, av);
    int av_1 = std::stoi(av[1]);
    int av_2 = std::stoi(av[2]);
    Sword *sword = new Sword(av_1);
    Axe *axe = new Axe(av_2);
    imperialSoldier imp;
    stormCloackSoldier storm;

    imp.setWeapon(sword);
    storm.setWeapon(axe);

    while (imp.getHealth() > 0 && storm.getHealth() > 0) {
        if (imp.getHealth() > 0)
            imp.attack(storm);
        if (storm.getHealth() > 0)
            storm.attack(imp);
        std::cout << "<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>"
        << std::endl;
        if (storm.getHealth() <= 0) {
            std::cout << "Imperial has won!"
            << std::endl;
            return 0;
        }
        if (imp.getHealth() <= 0) {
            std::cout << "Stormcloak has won!"
            << std::endl;
            return 0;
        }
    }
    return 0;
}
