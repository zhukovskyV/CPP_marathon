#include <regex>
#include <iostream>

#include "Player.h"
#include "Map.h"
#include "MoveManager.h"

static void validation(int ac, char** av) {
    std::regex r(R"lit(\d+)lit");
    std::cmatch match;

    if (ac != 3 || !std::regex_match(av[1], match, r)
        || !std::regex_match(av[2], match, r)) {
        std::cerr << "usage: ./smartPointers [width] [height]" << std::endl;
        exit(EXIT_FAILURE);
    }
    size_t width = std::stoul(av[1]);
    size_t height = std::stoul(av[2]);

    if (width < 5 || width > 20 || height < 5 || height > 20) {
        std::cerr << "Invalid map size" << std::endl;
        exit(EXIT_FAILURE);
    }
}

int main(int ac, char** av) {
    validation(ac, av);

    std::shared_ptr<Player> player = std::make_shared<Player>();
    std::shared_ptr<Map> map = std::make_shared<Map>(std::stoul(av[1]),
                                                     std::stoul(av[2]), player);
    std::unique_ptr<MoveManager> manager = std::make_unique<MoveManager>(player, map);

    map->outputMap();
    while (true) {
        std::cout << ":> ";
        std::string s;
        std::getline(std::cin, s);

        manager->processInputAndMove(s);
        map->outputMap();
    }
    return 0;
}