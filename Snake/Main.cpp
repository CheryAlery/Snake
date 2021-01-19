#include <Windows.h>
#include <conio.h>
#include "Wall.h"
#include "Snake.h"
#include "Fruit.h"
#include "Core.h"
#include "Space.h"

using namespace std;

// http://www.realcoding.net/articles/funktsii-dlya-raboty-s-reestrom.html

// JSON - "{[1,2,3,4,5]}"

// таблица рекордов
extern vector <pair<int, string>> record(10, { 0, "Noname"s });

int main() {


    // убираем курсор
    CONSOLE_CURSOR_INFO cursor{ 20 , false };
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);

    // задаем расположение поля и таблицы
    const int FIELD_WIDTH = 50;
    const int FIELD_HEIGHT = 25;
    const int TABLE_WIDTH = 100;
    const int TABLE_HEIGHT = 30;
    Space space(1, 1, FIELD_WIDTH, FIELD_HEIGHT);
    Space spaceScore(FIELD_WIDTH + 20, 5, TABLE_WIDTH, TABLE_HEIGHT);
    Core core(FIELD_WIDTH, FIELD_HEIGHT);
    int command=0;
    int command_prev= command;    
    while (command != 27) {

        core.PrintMenu();
        command = _getch();
        space.Clear();
        switch (command) {
        case 'h' :
        case 'H' :
            core.PrintRecord(record);
            space.Clear();
            break;

        case 'p' :
        case 'P' :
            string name = core.GetName();
            space.Clear();
            // создание стен и доп. препятствий
            Wall wall( FIELD_WIDTH, FIELD_HEIGHT);
            wall.CreateHorizontalWall(10, 3, 2).Render();
            space.Init();
            while (command != 27) {
                // выпускаем змею
                Snake snake(name);
                int x = FIELD_WIDTH / 2 + 1;
                int x_prev;
                int y = FIELD_HEIGHT / 2 + 1;
                int y_prev;
                int lvl = 1;
                command = 77;

                // поле успехов 
                core.PrintTable(name, snake.GetLenght() - 1, lvl, record[0].first, 0);

                //создаем фрукт
                Fruit fruit(FIELD_WIDTH, FIELD_HEIGHT);
                fruit.RenderFruit();

                // заводим таймер
                clock_t start = clock();

                // начинаем
                while (!Wall::Get()[{x, y}] && command != 27) {
                    x_prev = x;
                    y_prev = y;
                    command_prev = command;
                    // управление

                    do {
                        if (_kbhit()) {
                            command = _getch();
                        }
                        switch (command) {
                        case 77:
                            ++x;
                            break;
                        case 75:
                            --x;
                            break;
                        case 80:
                            ++y;
                            break;
                        case 72:
                            --y;
                            break;
                        }
                    } while (x_prev == x && y_prev == y);
                                   

                    // не врезаась ли в саму себя
                    if (snake.IsSnake(x, y)) {
                        break;
                    }


                    // съела фрукт
                    if (std::pair<int, int> { x, y } == fruit.fruit_coord) {
                        fruit.CreateFruit();
                        snake.EatFood();
                        lvl = (Snake::GetLenght() - 1) / 10 + 1;
                    }

                    // рисуем змею
                    snake.RenderSnake(x, y, command);
                    fruit.RenderFruit();
                    core.PrintTable(name, Snake::GetLenght() - 1, lvl,
                        record[0].first, (clock() - start) / CLOCKS_PER_SEC);

                    // задержка
                    Sleep(250 - 30 * lvl);
                    space.Clear();
                }

                spaceScore.Clear();
                core.PrintDeath();
                command = _getch();
                if (command == static_cast<int>('y') ||
                    command == static_cast<int>('Y')) {
                    continue;
                }
                break;
            }
        space.Clear();
        break;
        }
    }
    return 0;
}










