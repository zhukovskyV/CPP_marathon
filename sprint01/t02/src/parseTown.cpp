#include "visitAll.h"

void parseTown(int argc, std::deque<City> cityList, std::deque<City>& cityFull) {
    int first = 0;

    for (int i = 0; i < argc - 1; i++) {
        if (std::stoi(cityList[i].stamina) > std::stoi(cityList[i].dist)) {
            first = i;
            for (int j = i; j < argc - 1; j++)
                cityFull.push_back(cityList[j]);
            for (int j = 0; j < first; ++j)
                cityFull.push_back(cityList[j]);
            break;
        }
        if (first == 0 && i == argc - 2) {
            std::cerr << "Mission: Impossible\n";
            exit(1);
        }
    }
}
