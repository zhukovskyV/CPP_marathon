#include "dragonborn.h"
#include <map>
#include <iostream>

void Dragonborn::executeAction(const Actions action) {
    static std::map<Actions, void(Dragonborn::*)(void) const> spells {
            {Actions::Weapon, &Dragonborn::attackWithWeapon},
            {Actions::Shout, &Dragonborn::shoutThuum},
            {Actions::Magic, &Dragonborn::attackWithMagic}
    };
    (this->*spells.at(action))();
}

void Dragonborn::shoutThuum() const {
    std::cout << "Yol Toor Shul" << std::endl;
}

void Dragonborn::attackWithWeapon() const {
    std::cout << "*attacks with weapon*" << std::endl;
}

void Dragonborn::attackWithMagic() const {
    std::cout << "*attacks with magic spell*" << std::endl;
}
