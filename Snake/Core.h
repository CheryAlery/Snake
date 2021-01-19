#pragma once
#include <Windows.h>
#include <iostream>
#include <string>
#include <vector>
#include <conio.h>

using namespace std;

class Core {
public:

    Core(const int FIELD_WIDTH, const int FIELD_HEIGHT) : m_field_width{ FIELD_WIDTH }, m_field_height{ FIELD_HEIGHT } {
    }


    string GetName();

    Core& PrintMenu();

    static void SetPos(const int x, const int y);

    Core& Print(const vector<string>& words, const int x, const int y);

    Core& PrintRecord(vector <pair<int, string>> record);

    Core& PrintTable(string name, int score, int lvl, int high_score, int time);

    Core& PrintDeath();

private:
    const int m_field_width;
    const int m_field_height;
    
};


