#pragma once
#include <vector>
#include <ctime>
#include "Wall.h"
#include "Core.h"



class Fruit {
public:
    Fruit(int field_width, int field_height) :
        m_field_width{ field_width},
        m_field_height{ field_height } {
    CreateFruit();
    }
    const char fruit_simbol = '&';
    std::pair <int, int> fruit_coord;

    // создает фрукт в поле с заданной шириной и высотой
    Fruit& CreateFruit();

    // рисует в заданном месте заданный символ
    Fruit& RenderFruit();

private:
    const int m_field_width;
    const int m_field_height;
    int random = 0;
    int Random(const int max);
};

