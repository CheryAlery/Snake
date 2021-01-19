#include "Wall.h"




Wall& Wall :: CreateHorizontalWall(const int length, const int x, const int y) {
    for (int i = 0; i <= length; ++i) {
        barrier[{ x + i, y }] = 1;
    }
    return *this;
};

    // создаем вертикальное препятствие в заданных коориднатах
Wall& Wall :: CreateVerticalWall(const int length, const int x, const int y) {
    for (int i = 0; i <= length; ++i) {
        barrier[{ x, y + i }] = true;
    }
    return *this;
};

void Wall::Render() const {
    for (const auto& coord : barrier)
    {
        Core::SetPos(coord.first.first, coord.first.second);
        std::cout << m_wall_simbol;
    }
};


map <std::pair<int, int>, bool> Wall::barrier = { { std::pair<int, int>{0,0},0 } };


