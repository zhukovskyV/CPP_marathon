#pragma once

#include <map>
#include <string>
#include <iostream>

class Draugr {
public:
    explicit Draugr();
    Draugr(Draugr& other);
    Draugr(Draugr&& other);
    explicit Draugr(int frostResist);
    explicit Draugr(double health, int frostResist = 50);
    void setName(const std::string&& name);
    void shoutPhrase(int shoutnum) const;
private:
    std::string m_name;
    double m_health;
    const int m_frostResist;
    const std::map<int, std::string> tuul;
};
