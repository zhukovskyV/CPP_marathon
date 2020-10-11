#ifndef AXE_H
#define AXE_H

class Axe final {
    public: Axe (int damage);
        int getDamage() const;

    private:
        const int m_damage;
};

#endif
