#include "Soldier.h"

Soldier::Soldier(std::string&& name, int health)
        : m_name(name),
          m_health(health)
{
    std::cout << "Soldier " << m_name << " was created" << std::endl;
}

Soldier::~Soldier() {
    std::cout << "Soldier " << m_name << " was deleted" << std::endl;
    delete m_weapon;
}

void Soldier::attack(Soldier& other) {
    other.m_health -= m_weapon->getDamage();
    std::cout << m_name << " attacks " << other.m_name
              << " and deals " << m_weapon->getDamage() << " damage" << std::endl;
}

void Soldier::setWeapon(Weapon* weapon) {
    delete m_weapon;
    m_weapon = weapon;
}

int Soldier::getHealth() const {
    return m_health;
}
