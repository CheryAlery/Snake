#include "Snake.h"

Snake& Snake::RenderSnake(const int x, const int y, int direction) {
    snake.insert(snake.begin(), { x,y });
    snake.resize(m_lenght);
    Core::SetPos(snake[m_lenght - 1].first, snake[m_lenght - 1].second);
    std::cout << tail;
    Core::SetPos(snake[0].first, snake[0].second);
    switch (direction)
    {
        case 77:
            std::cout << face[0];
            break;
        case 75:
            std::cout << face[1];
            break;
        case 80:
            std::cout << face[2];
            break;
        case 72:
            std::cout << face[3];
            break;
    }

    for (int i = 1; i < m_lenght - 1; ++i) {
        Core::SetPos(snake[i].first, snake[i].second);
        std::cout << body;
    }
    return *this;
}

bool Snake:: IsSnake(const int x, const int y) const {
    for (std::pair<int, int> coord : snake) {
        if (coord == std::pair<int, int> {x, y}) {
            return true;
        }
    }
    return false;
}

Snake& Snake:: EatFood() {
    ++m_lenght;
    return *this;
}

int Snake::m_lenght = 1;