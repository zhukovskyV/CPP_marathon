#pragma once
#include <exception>
#include <iostream>
#include <cxxabi.h>

namespace UniversalReferenceDeterminant {
    template<typename T>
    void determineReference(T&& obj) {
        int status;
        std::cout << abi::__cxa_demangle(typeid(obj).name(), 0, 0, &status);
    if (std::is_lvalue_reference<T>{})
        std::cout << " is l-value reference" << std::endl;
    else 
        std::cout << " is r-value reference" << std::endl;
    }
} // end namespace UniversalReferenceDeterminant

