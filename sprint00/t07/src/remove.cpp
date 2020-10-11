#include "inventory.h"

void remove(char **inventory, char* buffarg) {
    if(std::string(buffarg) == "w" || std::string(buffarg) == "f"
       || std::string(buffarg) == "a" || std::string(buffarg) == "p") {
        char *buff = *inventory;
        char symb = '\0';
        int status = 0;
        int q;

        for(q = 0; q < INVENTORY_SIZE; q++) {
            if(buff[q] == buffarg[0] && status == 0) {
                buff[q] = '-';
                std::cout << buffarg[0] << " was removed." << std::endl;
                status = 1;
            }
            if(status == 1 && q != (INVENTORY_SIZE - 1)) {
                buff[q] = buff[q + 1];
                buff[q + 1] = '-';
            }
        }
        if(status == 0) {
            std::cout << "Item not found." << std::endl;
        }
    }
    else {
        std::cout << "Invalid item." << std::endl;
    }
}
