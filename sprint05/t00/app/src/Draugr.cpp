#include "Draugr.h"


Draugr::Draugr() : tuum({
            {0, "Qiilaan Us Dilon!"},
            {1, "Bolog Aaz, Mal Lir!"},
            {2, "Kren Sosaal!"},
            {3, "Dir Volaan!"},
            {4, "Aar Vin Ok!"},
            {5, "Unslaad Krosis!"},
            {6, "Faaz! Paak! Dinok!"},
            {7, "Aav Dilon!"},
            {8, "Sovngarde Saraan!"}}),
          m_health(100),
          m_frostResist(50) {}

void Draugr::shoutPhrase(int shoutNumber) const {
    if (shoutNumber < 0 || shoutNumber > 8)
        throw 1;
    std::cout << "Draugr (100 health, 50% frost resist) shouts:" << std::endl;
    std::cout << tuum.at(shoutNumber) << std::endl;
}
