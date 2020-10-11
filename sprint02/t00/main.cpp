#include "src/uniqueWords.h"

int main(int ac, char** av) {
    if (ac != 2) {
        std::cerr << "usage: ./uniqueWords [file_name]" << std::endl;
        return 1;
    }

    uniqueWords(av);

    return 0;
}
