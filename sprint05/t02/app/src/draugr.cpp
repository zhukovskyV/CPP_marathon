#include "draugr.h"

Draugr::Draugr() : Draugr(100, 50) {}

Draugr::Draugr(Draugr& other)
        : Draugr(other.m_health, other.m_frostResist) {
    std::cout << "Copy constructor was called" << std::endl;
}

Draugr::Draugr(Draugr&& other)
        : Draugr(other.m_health, other.m_frostResist) {
    std::cout << "Move constructor was called" << std::endl;
}

Draugr::Draugr(int frostResist) : Draugr(100, frostResist) {}

Draugr::Draugr(double health, int frostResist) : m_health(health), m_frostResist(frostResist) {
    std::cout << "Draugr with "
              << m_health << " health and "
              << m_frostResist << "% frost resist was born" << std::endl;
}


void Draugr::setName(const std::string&& name) {
    m_name = name;
}

void Draugr::shoutPhrase(int shoutNumber) const {
    std::map<int, std::string> tuul({
        {0, "Qiilaan Us Dilon!"},
        {1, "Bolog Aaz, Mal Lir!"},
        {2, "Kren Sosaal!"},
        {3, "Dir Volaan!"},
        {4, "Aar Vin Ok!"},
        {5, "Unslaad Krosis!"},
        {6, "Faaz! Paak! Dinok!"},
        {7, "Aav Dilon!"},
        {8, "Sovngarde Saraan!"}});
    if (shoutNumber < 0 || shoutNumber > 8) {
        std::cerr << "Invalid shoutNumber" << std::endl;
        exit(1);
    }
    std::cout << "Draugr " << m_name << " (" << m_health << " health, " << m_frostResist << "% frost resist) shouts:" << std::endl;
    std::cout << tuul.at(shoutNumber) << std::endl;
}
