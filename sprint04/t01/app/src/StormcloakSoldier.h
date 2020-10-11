//#ifndef STORMCLOAKSOLDIER_H
//#define STORMCLOAKSOLDIER_H
#pragma once

#include "Axe.h"
#include "ImperialSoldier.h"
#include <iostream>

class imperialSoldier;

class stormCloackSoldier final {
    public:
        stormCloackSoldier();
        ~stormCloackSoldier();

        void setWeapon(Axe* weapon);
        void attack(imperialSoldier& enemy);
        void consumeDamage(int amount);
        int getHealth() const;

    private:
        Axe* m_weapon;
        int m_health;
};

//#endif
