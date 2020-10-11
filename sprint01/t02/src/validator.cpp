#include "visitAll.h"

std::string strTrim(const std::string &s) {
    std::string::const_iterator i = s.begin();
    while (i != s.end() && isspace(*i))
        i++;

    std::string::const_reverse_iterator ri = s.rbegin();
    while (ri.base() != i && isspace(*ri))
        ri++;

    return std::string(i, ri.base());
}

City *validator(char *str, int counter) {
    std::string tmp;
    std::vector<std::string> pars;
    std::stringstream ss;
    City *city = new City;
    ss << str;

    while (std::getline(ss, tmp, ',')) {
        tmp = strTrim(tmp);
        pars.push_back(tmp);
    }
    try {
        if (parseName(pars[0]))
            throw false;
        if (parseNum(pars[1]))
            throw false;
        if (parseNum(pars[2]))
            throw false;
    }
    catch (...) {
        std::cout << "Argument " << str << " is not valid" << std::endl;
        exit(1);
    }
    city->name = pars[0];
    city->stamina = pars[1];
    city->dist = pars[2];
    city->counter = counter;
    return city;
}
