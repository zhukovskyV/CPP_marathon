#include "ImperialSoldier.h"

ImperialSoldier::ImperialSoldier()
        : Soldier("Martin") {
    std::cout << "Imperial soldier was created" << std::endl;
}

ImperialSoldier::~ImperialSoldier() {
    std::cout << "Imperial soldier was deleted" << std::endl;
}
