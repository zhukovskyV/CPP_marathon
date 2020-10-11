#pragma once

#include "Soldier.h"
#include "Sword.h"
#include "StormcloakSoldier.h"
#include <iostream>

class StormcloakSoldier;

class ImperialSoldier : public Soldier {
public:
    ImperialSoldier();
    ~ImperialSoldier();
private:
    Sword* m_weapon;
    int m_health;
};
