#include "inventory.h"

void exit(char **inventory, char **comm, char **arg) {
    char *buffinventory = *inventory;
    char *buffcomm = *comm;
    char *buffarg = *arg;

    delete[] buffinventory;
    delete[] buffcomm;
    delete[] buffarg;

    buffinventory = nullptr;
    buffcomm = nullptr;
    buffarg = nullptr;

    std::cout << "Bye." << std::endl;
    exit(1);
}
