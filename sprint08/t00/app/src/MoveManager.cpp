#include <iostream>

#include "MoveManager.h"
#include "Player.h"
#include "Map.h"

MoveManager::MoveManager(std::shared_ptr<Player> &player, std::shared_ptr<Map> &map)
        : m_map(map), m_player(player)
{}

void MoveManager::processInputAndMove(const std::string &inputStr) {
    if (inputStr == "u") {
        if (checkMove(MoveManager::Direction::Up))
            m_player->movePlayer(MoveManager::Direction::Up);
    }
    else if (inputStr == "d") {
        if (checkMove(MoveManager::Direction::Down))
            m_player->movePlayer(MoveManager::Direction::Down);
    }
    else if (inputStr == "l") {
        if (checkMove(MoveManager::Direction::Left))
            m_player->movePlayer(MoveManager::Direction::Left);
    }
    else if (inputStr == "r") {
        if (checkMove(MoveManager::Direction::Right))
            m_player->movePlayer(MoveManager::Direction::Right);
    }
    else if (inputStr == "e") {
        exit(EXIT_SUCCESS);
    }
    else {
        std::cerr << "Invalid input" << std::endl;
    }
}

bool MoveManager::checkMove(MoveManager::Direction dir) const {
    if (dir == MoveManager::Direction::Up) {
        if (m_player->posY() != 0)
            return true;
    }
    else if (dir == MoveManager::Direction::Down) {
        if (m_player->posY() + 1 < m_map->height())
            return true;
    }
    else if (dir == MoveManager::Direction::Left) {
        if (m_player->posX() != 0)
            return true;
    }
    else if (dir == MoveManager::Direction::Right) {
        if (m_player->posX() + 1 < m_map->width())
            return true;
    }
    std::cerr << "Invalid direction" << std::endl;
    return false;
}
