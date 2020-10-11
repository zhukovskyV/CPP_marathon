#include "src/visitAll.h"

int main(int argc, char **argv) {
    std::deque<City> cityList;
    std::deque<City> cityFull;

    if (argc == 1) {
        std::cerr << "usage: ./visitAll [[name,stamina,distance] ...]\n";
        exit(1);
    }
    insert(argc, argv,cityList);
    parseTown(argc, cityList, cityFull);
    print(cityFull);
    return 0;
}




