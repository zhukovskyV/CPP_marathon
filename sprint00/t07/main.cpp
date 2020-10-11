#include "src/inventory.h"

int main() {
    char *arg = new char[20]();
    char *comm = new char[20]();
    char command[256];
    char *inventory = new char[INVENTORY_SIZE];
	empty(&inventory);
	while(true) {
		std::cout << "Enter command:> ";
		std::cin.getline(command, 256, '\n');
		util(command, &inventory, &comm, &arg);
	}
	return 0;
}
