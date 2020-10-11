#include "inventory.h"

void util(char *command, char **inventory, char **comm, char **arg) {
    int count = count_args(command, comm, arg);
    char *buffcomm = *comm;
    char *buffarg = *arg;

    if(count == -1) {
        std::cout << "Invalid item." << std::endl;
    }
    else if(std::string(buffcomm) == "show" && count == 1) {
        show(inventory);
    }
    else if(std::string(buffcomm) == "help" && count == 1) {
        std::cout << "Available commands:\n1. insert <itemType>\n2. remove <itemType>\n3. show\n4. help\n5. exit" << std::endl;
    }
    else if(std::string(buffcomm) == "exit" && count == 1) {
        exit(inventory, comm, arg);
    }
    else if(std::string(buffcomm) == "insert" && count == 2) {
        insert(inventory, buffarg);
    }
    else if(std::string(buffcomm) == "remove" && count == 2) {
        remove(inventory, buffarg);
    }
    else {
        std::cout << "Invalid command." << std::endl;
    }
}
