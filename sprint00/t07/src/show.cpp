#include "inventory.h"

void show(char **inventory) {
    char *buff = *inventory;
    std::cout << "Inventory { ";
    for(int q = 0; q < INVENTORY_SIZE; q++) {
        std::cout << buff[q] << " ";
    }
    std::cout << "}" << std::endl;
}
