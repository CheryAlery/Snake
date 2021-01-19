#pragma once
#include <iostream>
#include <vector>
#include <Windows.h>

class Space
{public:

    Space(const int x0, const int y0, const int space_width, const int space_height) :
        coordBufSize{ short(space_width + 1),short(space_height + 1) },
        ReadArea{ short(x0),short(y0),short(space_width + x0),short(space_height + y0) }
    {   
        chiBuffer = new CHAR_INFO[(space_width + 1) * (space_height + 1)];
        Init();
    }

    ~Space() {
        Clear();
        delete[] chiBuffer;
    }

    Space& Init();
    Space& Clear();

private:
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    CHAR_INFO* chiBuffer;
    COORD coordBufSize; // –азмер колонки/строки chiBuffer
    COORD coordBufCoord = { 0,0 }; //верхн€€ лева€ €чейка назначени€
    SMALL_RECT ReadArea; //пр€моугольник источника

};

