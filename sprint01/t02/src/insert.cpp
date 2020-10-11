#include "visitAll.h"

void insert(int argc, char **argv, std::deque<City>& cityList) {
    for (int i = 1; i < argc; i++)
        cityList.push_back(*validator(argv[i], i - 1));
}
