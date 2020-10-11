#pragma once

#include "Axe.h"
#include "ImperialSoldier.h"
#include <iostream>
#include "Soldier.h"

class ImperialSoldier;

class StormcloakSoldier : public Soldier {
public:
    StormcloakSoldier();
    ~StormcloakSoldier();
private:
    Axe* m_weapon;
    int m_health;
};
