#ifndef SUMFILEDATA_H
#define SUMFILEDATA_H


#include <fstream>
#include <string>


template <class T>
T sumFileData(const std::string& fileName){
    T sum{0};
    std::ifstream str(fileName);
    std::istream_iterator<T> i{str};
    std::istream_iterator<T> end{};
    for (; i != end; i++)
        sum += *i;
    return sum;
}

#endif
