//#ifndef IMPERIALSOLDIER_H
//#define IMPERIALSOLDIER_H
#pragma once

#include "Sword.h"
#include "StormcloakSoldier.h"
#include <iostream>

class stormCloackSoldier;

class imperialSoldier final {
    public:
        imperialSoldier();
        ~imperialSoldier();

        void setWeapon(Sword* weapon);
        void attack(stormCloackSoldier& enemy);
        void consumeDamage(int amount);
        int getHealth() const;

    private:
        Sword* m_weapon;
        int m_health;
};

///endif
