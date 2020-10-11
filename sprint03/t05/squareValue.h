#ifndef SQUAREVALUE_H
#define SQUAREVALUE_H

#include <iterator>

template <class Container>
void squareValue(Container& container) {
    auto i = container.begin();
    auto end = container.end();

    for (; i < end; i++)
        *i *= *i;
}

#endif