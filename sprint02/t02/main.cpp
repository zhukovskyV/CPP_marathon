#include "src/bookSaver.h"

int main() {
    std::string input;
    std::map<std::string,std::string> lib;
    std::string command;

    while (true) {
        std::stringstream ss;
        std::cout << "enter command:> ";
        std::getline(std::cin, command);

        ss.str(command);
        validCommand(ss, lib);
    }
    return 0;
}
