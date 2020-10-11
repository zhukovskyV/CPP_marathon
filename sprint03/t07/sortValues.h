#ifndef SORTVALUES_H
#define SORTVALUES_H

#include <algorithm>
#include <vector>
#include <string>

template <class RandomAccessIterator>
RandomAccessIterator sortValues(RandomAccessIterator begin, RandomAccessIterator end) {
    bool swap = true;
    while (begin != end-- && swap) {
        swap = false;
        for (auto i = begin; i != end; ++i) {
            if (*(i + 1) < *i) {
                std::iter_swap(i, i + 1);
                swap = true;
            }
        }
    }
    return begin;
}

#endif
