#include "inventory.h"

void insert(char **inventory, char* buffarg) {
    if(std::string(buffarg) == "w" || std::string(buffarg) == "f"
       || std::string(buffarg) == "a" || std::string(buffarg) == "p") {
        char *buff = *inventory;
        int q;
        for(q = 0; q < INVENTORY_SIZE; q++) {
            if(buff[q] == '-') {
                buff[q] = buffarg[0];
                std::cout << buffarg[0] << " was inserted." << std::endl;
                break;
            }
        }
        if(q == INVENTORY_SIZE) {
            std::cout << "Inventory is full." << std::endl;
        }
    }
    else {
        std::cout << "Invalid item." << std::endl;
    }
}
