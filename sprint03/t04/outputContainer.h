#ifndef OUTPUTCONTAINER_H
#define OUTPUTCONTAINER_H

#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>

template <typename Container>
void outputContainer(const Container& container) {
    std::copy(container.begin(), container.end(),
              std::ostream_iterator<typename Container::value_type>(std::cout, "\n"));
}

#endif