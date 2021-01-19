#include "Core.h"

void Core::SetPos(const int x, const int y)
{
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

string Core::GetName() {
    string name;
    Print({ "Your name:"s,"" }, m_field_width / 3, m_field_height / 3);
    getline(std::cin, name);
    return name;
}

Core& Core::PrintMenu() {
    Print({ "MENU"s, "P - Play"s, "ESC - Exit"s, "H - High score"s }, m_field_width / 3, m_field_height / 3);
    return *this;
};


Core& Core::Print(const vector<string>& words, const int x, const int y) {

    for (int i = 0; i < words.size(); ++i) {
        SetPos(x, y + 3 * i);
        cout << words[i];
    }
    return *this;
}

Core& Core::PrintRecord(vector <pair<int, string>> record) {
    int command = 0;

    for (int i = 0; i < record.size(); ++i) {
        Print({ to_string(i + 1) + ". "s + record[i].second +
            " : "s + to_string(record[i].first) }, m_field_width / 3, 2 + 2 * i);
    }
    Print({ "Press Backspace to return"s }, m_field_width / 3, 4 + 2 * record.size());
    while (command != 8) {
        command = _getch();
    }
    return *this;
}

Core& Core::PrintTable(string name, int score, int lvl, int high_score, int time) {

    Print({ "NAME"s, "SCORE"s, "LVL"s, "PREVIOUS HIGH SCORE"s , "TIME"s },
        m_field_width + 20, 5);
    vector<string> table = { name , to_string(score),
        to_string(lvl), to_string(high_score), to_string(time) };
    Print(table, m_field_width + 40, 5);
    return *this;
}

Core& Core::PrintDeath() {
    Print({ "You died. Press Y to restart" }, m_field_width / 3, m_field_height / 3 - 3);
    return *this;
};

