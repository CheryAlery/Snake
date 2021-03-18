#pragma once
#include <iostream>
#include <vector>
#include "Core.h"
#include <algorithm>

using namespace std;
extern vector <pair<int, string>> record;

class Snake {

public:
    Snake(const string name) : m_name{ name } {
    }

    ~Snake() {
        WriteRecord();
        m_lenght = 1;
    }

    std::vector<char> face = { '>','<','v','^' };
    char body = '%';
    char tail = '*';

    Snake& RenderSnake(const int x, const int y, int direction);

    Snake& EatFood();

    bool IsSnake(const int x, const int y) const;

    static int GetLenght() {
        return m_lenght;
    };

private:
    static int m_lenght;

    const string m_name;

    void WriteRecord() {
        record.push_back({ m_lenght-1 , m_name });
        sort(record.begin(), record.end());
        reverse(record.begin(), record.end());
        record.resize(record.size() - 1);
    }
    std::vector<std::pair<int, int>> snake;
    
};

