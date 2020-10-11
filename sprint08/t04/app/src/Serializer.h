#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <regex>

class Serializer {
public:
    template<class T>
    void serialize(const T* object, const std::string& fileName) {
        std::ofstream file(fileName, std::ios::out | std::ios::binary);
        if (file) {
            file.write(reinterpret_cast<const char *>(object), sizeof(T));
        } else {
            throw std::runtime_error("error");
        }
    }

    template<class T>
    T deserialize(const std::string& fileName) {
        T object;
        std::ifstream file(fileName, std::ios::in | std::ios::binary);
        if (file || file.peek() != std::ifstream::traits_type::eof()) {
            file.read(reinterpret_cast<char *>(&object), sizeof(T));
        } else {
            throw std::runtime_error("error");
        }
        return object;
    }
};