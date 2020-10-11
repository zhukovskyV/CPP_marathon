
#ifndef VISITALL_H
#define VISITALL_H

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <sstream>

struct City {
    int counter;
    std::string name;
    std::string dist;
    std::string stamina;
};

void parseTown(int argc, std::deque<City> cityList, std::deque<City>& cityFull);
City *validator(char *str, int counter);
void insert(int argc, char **argv, std::deque<City>& cityList);
void print(std::deque<City> cityFull);
bool parseNum(std::string str);
bool parseName(std::string str);

#endif




