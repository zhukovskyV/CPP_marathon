#pragma once
#include "Weapon.h"
#include <string>
#include <iostream>

class Soldier {
public:
    Soldier(std::string&& name, int health = 100);
    virtual ~Soldier();
    void attack(Soldier& other);
    void setWeapon(Weapon* weapon);
    int getHealth() const;
private:
    Weapon* m_weapon{nullptr};
    std::string m_name;
    int m_health;
};
