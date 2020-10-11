#include "referenceOrPointer.h"
#include <iostream>

void multiplyByPointer(int* ptr, int mult) {
    *ptr *= mult;
}

void multiplyByReference(int& ref, int mult) {
    ref *= mult;
}
