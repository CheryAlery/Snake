#pragma once
#include <map>
#include <iostream>
#include "Core.h"


class Wall {
public:
    // получает длину и ширину поля, рисует его.
   
    Wall(const int width, const int height, const char wall_simbol = '#'): 
            m_wall_simbol{wall_simbol}
    {
            CreateHorizontalWall(width + 1, 0, 0);
            CreateHorizontalWall(width + 1, 0, height + 1);
            CreateVerticalWall(height, 0, 1);
            CreateVerticalWall(height, width + 1, 1);
    };

    static map <std::pair<int, int>, bool> Get() { return barrier; }

    // создаем горизонтальное препятствие в заданных коориднатах
    Wall& CreateHorizontalWall(const int length, const int x, const int y);

    // создаем вертикальное препятствие в заданных коориднатах
    Wall& CreateVerticalWall(const int length, const int x, const int y);

    void Render() const;

private:
    static std::map <std::pair<int, int>, bool> barrier;
    const char m_wall_simbol;
};

