#include "ImperialSoldier.h"

imperialSoldier::imperialSoldier()
        : m_weapon(0), m_health(100) {}

imperialSoldier::~imperialSoldier() {
    delete m_weapon;
}

void imperialSoldier::setWeapon(Sword *weapon) {
    delete m_weapon;
    m_weapon = weapon;
}

void imperialSoldier::attack(stormCloackSoldier &enemy) {
    int dmg = m_weapon->getDamage();

    if (dmg > enemy.getHealth())
        dmg = enemy.getHealth();
    std::cout << "Imperial soldier attacks and deals " << dmg
              << " damage" << std::endl;
    enemy.consumeDamage(m_weapon->getDamage());
}

void imperialSoldier::consumeDamage(int amount) {
    m_health -= amount;

    if (m_health < 0) {
        amount += m_health;
        m_health = 0;
    }
    std::cout << "Imperial soldier consumes " << amount << " of damage";
    if (m_health == 0) {
        std::cout << " and dies" << std::endl;
        return;
    }
    std::cout << std::endl;
}

int imperialSoldier::getHealth() const {
    return m_health;
}
