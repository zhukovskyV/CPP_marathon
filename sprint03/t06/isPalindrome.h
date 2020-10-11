#ifndef ISPALINDROME_H
#define ISPALINDROME_H

#include <algorithm>
#include <string>
#include <iterator>

template <class BidirectionalIterator>
bool isPalindrome(BidirectionalIterator begin, BidirectionalIterator end) {
    return std::equal(begin, std::next(begin, std::distance(begin, end) / 2),
                      std::make_reverse_iterator(end));
}

#endif
