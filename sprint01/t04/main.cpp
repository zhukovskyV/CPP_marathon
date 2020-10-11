#include "src/stdAlgoV1.h"

bool checkForName(std::string str) {
    for (char i : str) {
        if (isspace(i) == 0)
            return true;
    }
    return false;
}


int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "usage: ./stdAlgoV1 [file_name]\n";
        exit(1);
    }

    std::forward_list <std::string> names;
    std::string temp;
    std::ifstream file(argv[1]);
    int forward_size;

    if (!file.is_open()) {
        std::cerr << "error\n";
        exit(1);
    }
    while (getline(file, temp))
        if (checkForName(temp))
            names.push_front(temp);
    forward_size = std::distance(names.begin(), names.end());
    errorForwardSize(forward_size);
    std::cout << "size: " << forward_size << "\n";
    pars(names);
    return 0;
}
