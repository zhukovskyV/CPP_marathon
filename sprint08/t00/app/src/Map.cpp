#include <iostream>

#include "Map.h"
#include "Player.h"

Map::Map(size_t width, size_t height, std::shared_ptr<Player> &player)
        : m_width(width), m_height(height), m_player(player)
{
    generateMap();
}

size_t Map::width() const {
    return m_width;
}
size_t Map::height() const {
    return m_height;
}

void Map::outputMap() const {
    for (size_t i = 0; i <= m_width * m_height - 1; ++i) {

        if (m_player->posX() + m_player->posY() * width() == i)
            std::cout << m_player->getIdentifier();
        else
            std::cout << m_map[i];
        if ((i + 1) % m_width == 0)
            std::cout << '\n';
        else
            std::cout << ' ';
    }
}

void Map::generateMap() {
    size_t len = m_width * m_height;

    m_map = std::make_unique<char[]>(len);
    std::fill(m_map.get(), m_map.get() + width() * height(), '.');

    for (size_t i = 0; i < len; ++i) {
        int element = std::rand() % 3;
        if (element == 0)
            m_map[i] = '.';
        else if (element == 1)
            m_map[i] = 'T';
        else if (element == 2)
            m_map[i] = '@';
    }
}