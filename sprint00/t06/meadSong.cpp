#include "meadSong.h"

void meadSong(void) {
    std::string str1 = " bottles of mead on the wall";
    std::string str2 = " bottles of mead. \nTake one down and pass it around, ";
    std::string str3 = "no more bottles of mead.";

    for (int i = 99; i > 0; i--) {
        if (i == 1) {
            std::cout << "1 bottle of mead on the wall, 1 bottle of mead.\n"
                         "Take it down and pass it around, "
                         "no more bottles of mead on the wall\n" << std::endl;
            break;
        }
        std::cout << i << str1 << ", " << i << str2;
        if (i == 2)
            std::cout << i - 1 << " bottle of mead on the wall." << std::endl << std::endl;
        else
            std::cout << i - 1 << str1 << "." << std::endl << std::endl;

    }
    std::cout << "No more" << str1 << " " << str3 << std::endl;
    std::cout << "Go to the store and buy some more, 99" << str1 << "." << std::endl;
}
