#include "draugr.h"
#include <regex>

int getNumber(int ac, char **av) {
    int number;
    try {
        number = std::stoi(av[1]);
    } catch (...) {
        std::string err = "Invalid shoutNumber";
        throw err;
    }
    if ((number < 0) || (number > 8)) {
        std::string err = "Invalid shoutNumber";
        throw err;
    }

    return number;
}

int getNumber_Health(char *str) {
    int number;
    try {
        number = std::stoi(str);
    } catch (...) {
        std::string err = "Error";
        throw err;
    }
    return number;
}

int getNumber_Frost(char *str) {
    int number;
    try {
        number = std::stoi(str);
    } catch (...) {
        std::string err = "Error";
        throw err;
    }
    if (number > 100) {
        std::string err = "Error";
        throw err;
    }
    return number;
}

std::pair <std::string, std::string> getNames(std::string av) {
    std::regex reg("([a-zA-Z0-9\\s]+),([a-zA-Z0-9\\s]+)");
    std::smatch s;

    if (!(std::regex_match(av, s, reg))) {
        std::string err = "Invalid names";
        throw err;
    }
    return {s[1], s[2]};
}

void DoActions(int argc, int number, std::pair<std::string, std::string>& names, int frost, double health) {
    if (argc == 4) {
        Draugr dr1(health);
        dr1.setName(std::string(names.first));
        dr1.shoutPhrase(number);
        Draugr dr2(dr1);
        dr2.setName(std::string(names.second));
        dr2.shoutPhrase(number);
    }
    if (argc == 5) {
        Draugr dr1(health, frost);
        dr1.setName(std::string(names.first));

        dr1.shoutPhrase(number);
        Draugr dr2(std::move(dr1));
        dr2.setName(std::string(names.second));
        dr2.shoutPhrase(number);
    }
}

int main(int ac, char** av) {
    if (ac != 4 && ac != 5) {
        std::cerr << "usage: ./draugr [shoutNumber] [name1,name2] [health] [frostResist]" << std::endl;
        return 1;
    }
    int shoutnumber;
    double health;
    int frost;
    std::pair <std::string, std::string> names;

    try {
        shoutnumber = getNumber(ac, av);
        health = getNumber_Health(av[3]);
        if (ac == 5)
            frost = getNumber_Frost(av[4]);
        std::string av2(av[2]);
        names = getNames(av2);
    } catch (std::string err) {
        std::cerr << err << std::endl;
        return 1;
    }
    DoActions(ac, shoutnumber, names, frost, health);


    return 0;
}
