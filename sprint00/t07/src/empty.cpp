#include "inventory.h"

void empty(char **inventory) {
    char *buff = *inventory;
    for(int q = 0; q < 12; q++) {
        buff[q] = '-';
    }
}
