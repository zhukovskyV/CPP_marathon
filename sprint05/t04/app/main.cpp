#include "ImperialSoldier.h"
#include "StormcloakSoldier.h"
#include <utility>
#include <string>

std::pair<int,int> valid_damage(char* av1, char* av2) {
    std::pair<int,int> damage;
    std::pair<size_t,size_t> index;

    damage.first = std::stoi(av1, &index.first);
    damage.second = std::stoi(av2, &index.second);
    if ((damage.first < 10 || damage.first > 20)
          || (damage.second < 10 || damage.second > 20)
          || av1[index.first] != '\0' || av2[index.second] != '\0') {
        std::cerr << "Damage has to be in a range of 10-20 points." << std::endl;
        exit(1);
    }
    return damage;
}

void Fight(ImperialSoldier& imperial, StormcloakSoldier& stormcloak) {
    std::cout << std::endl << "***The battle has begun!***" << std::endl << std::endl;
    while (imperial.getHealth() && stormcloak.getHealth()) {
        stormcloak.attack(imperial);
        if (imperial.getHealth() < 0)
            break ;
        imperial.attack(stormcloak);
        if (stormcloak.getHealth() < 0)
            break ;
        std::cout << "<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>" << std::endl;
    }
    if (imperial.getHealth() < 0)
        std::cout << "<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>" << std::endl;
    std::cout << (imperial.getHealth() > 0 ? "Imperial" : "Stormcloak") << " has won!" << std::endl << std::endl;
}

void createSoldiersAndFight(char* av1, char* av2) {
    std::pair<int, int> damage = valid_damage(av1, av2);

    Sword *sword = new Sword(damage.first);
    Axe *axe = new Axe(damage.second);

    ImperialSoldier imperial;
    StormcloakSoldier stormcloak;

    imperial.setWeapon(sword);
    stormcloak.setWeapon(axe);

    Fight(imperial, stormcloak);
}

int main(int ac, char** av) {
    if (ac != 3) {
        std::cerr << "usage: ./imperialVsStormcloak [dmgOfSword] [dmgOfAxe]" << std::endl;
        return 1;
    }
    createSoldiersAndFight(av[1], av[2]);
    return 0;
}

