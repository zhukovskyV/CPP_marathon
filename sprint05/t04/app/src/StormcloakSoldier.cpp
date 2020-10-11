#include "StormcloakSoldier.h"
#include "Soldier.h"

StormcloakSoldier::StormcloakSoldier()
        : Soldier("Flynn") {
    std::cout << "Stormcloak soldier was created" << std::endl;
}

StormcloakSoldier::~StormcloakSoldier() {
    std::cout << "Stormcloak soldier was deleted" << std::endl;
}
