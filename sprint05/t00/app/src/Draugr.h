#ifndef DRAUGR_H
#define DRAUGR_H
#include <iostream>
#include <map>
#include <string>

class Draugr {
    public:Draugr();

    void shoutPhrase(int shoutNumber) const;

    private:
        double m_health;
        const int m_frostResist;
        const std::map<int, std::string> tuum;
};


#endif
