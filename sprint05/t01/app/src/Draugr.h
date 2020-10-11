#ifndef DRAUGR_H
#define DRAUGR_H
#include <iostream>
#include <map>
#include <string>

class Draugr {
    public:
        explicit Draugr();
        explicit Draugr(int frostResist);
        explicit Draugr(double health, int frostResist = 50);
        void shoutPhrase(int shoutNumber) const;

    private:
        double m_health;
        const int m_frostResist;
};


#endif
