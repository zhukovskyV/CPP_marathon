#include "mySort.h"

void mySort(int ac, char** av) {
    if (ac != 6)
        std::cerr << "usage: ./simpleSort arg1 arg2 arg3 arg4 arg5" << std::endl;
    else {
        std::array<std::string, 5> arr = {av[1],av[2],
                                          av[3], av[4], av[5]};
        std::sort(arr.begin(), arr.end());

        for (const auto& item : arr) {
            std::cout << item;
            if (item != *(arr.end() - 1))
                std::cout << " ";
        }
        std::cout << std::endl;
    }
}
