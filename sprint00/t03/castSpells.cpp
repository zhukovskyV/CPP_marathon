#include "castSpells.h"

int castFloatToInt(float num) {
    return int(num);
}

int* castToNonConstIntPtr(const int* ptr) {
    return const_cast<int*>(ptr);
}
