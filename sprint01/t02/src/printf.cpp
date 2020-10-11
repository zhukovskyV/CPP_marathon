#include "visitAll.h"

void print(std::deque<City> cityFull) {
    for (int i = 0; i < cityFull.size(); i++) {
        std::cout << cityFull[i].counter << " ";
        std::cout << cityFull[i].name << std::endl;
    }
}

