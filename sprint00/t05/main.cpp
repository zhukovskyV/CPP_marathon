#include <iostream>
#include <string>

auto check(char* value, size_t n) {
    if(value[n] != '\0')
        throw 1;
}

auto validation(int ac, char **av) {
    auto i = 2;
    auto indx = 0ul;

    try {
        std::stoi(av[i], &indx);
        check(av[i], indx);
        std::stof(av[++i], &indx);
        check(av[i], indx);
        std::stod(av[++i], &indx);
        check(av[i], indx);
    } catch (...) {
        std::cerr << "Invalid argument: " << av[i] << std::endl;
        exit(1);
    }
}

int main(int ac, char** av) {
    if (ac != 5) {
        std::cerr << "usage:./automaton [name] [level] [health] [stamina]" << std::endl;
        return 1;
    }
    validation(ac, av);
        std::cout << "Name = " << av[1] << std::endl;
        std::cout << "Level = " << std::stoi(av[2]) << std::endl;
        std::cout << "Health = " << std::stof(av[3]) << std::endl;
        std::cout << "Stamina = " << std::stod(av[4]) << std::endl;
}
