#include "StormcloakSoldier.h"

stormCloackSoldier::stormCloackSoldier()
    : m_weapon(0), m_health(100) {}

stormCloackSoldier::~stormCloackSoldier() {
    delete m_weapon;
}

void stormCloackSoldier::setWeapon(Axe *weapon) {
    delete m_weapon;
    m_weapon = weapon;
}

void stormCloackSoldier::attack(imperialSoldier &enemy) {
    int dmg = m_weapon->getDamage();

    if (dmg > enemy.getHealth())
        dmg = enemy.getHealth();
    std::cout << "Stormcloak soldier attacks and deals " << dmg
    << " damage" << std::endl;
    enemy.consumeDamage(m_weapon->getDamage());
}

void stormCloackSoldier::consumeDamage(int amount) {
    m_health -= amount;

    if (m_health < 0) {
        amount += m_health;
        m_health = 0;
    }
    std::cout << "Stormcloak soldier consumes " << amount << " of damage";
    if (m_health == 0) {
        std::cout << " and dies" << std::endl;
        return ;
    }
    std::cout << std::endl;
}

int stormCloackSoldier::getHealth() const {
    return m_health;
}
