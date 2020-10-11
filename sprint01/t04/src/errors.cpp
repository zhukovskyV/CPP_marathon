#include "stdAlgoV1.h"

void errorForwardSize(int forward_size) {
    if (forward_size == 0) {
        std::cerr << "error\n";
        exit(1);
    }
}
