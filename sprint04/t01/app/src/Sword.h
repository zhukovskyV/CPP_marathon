#ifndef SWORD_H
#define SWORD_H

class Sword final {
    public: Sword (int damage);
        int getDamage() const;

    private:
        const int m_damage;
};

#endif
