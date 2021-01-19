#include "Fruit.h"


Fruit& Fruit:: CreateFruit() {
    do {
        fruit_coord.first = Random(m_field_width);
        fruit_coord.second = Random(m_field_height);
    } while (Wall::Get()[fruit_coord]);
    return *this;
}

Fruit& Fruit:: RenderFruit() {
    Core::SetPos(fruit_coord.first, fruit_coord.second);
    std::cout << fruit_simbol;
    return *this;
};

int Fruit:: Random(const int max) {
    srand(time(0) + random); // автоматическая рандомизация
    random = 1 + rand() % (max);
    return random;
}