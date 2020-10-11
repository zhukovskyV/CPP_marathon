#ifndef OUTPUTANY_H
#define OUTPUTANY_H

#include <iostream>
#include <vector>
#include <array>

template <class Container>
void outputAny(const Container& c) {
    for (auto& item : c)
        std::cout << item << std::endl;
}

#endif