#include <iostream>
#include "BackRec9.h"
#include "HomeDyn3.h"
#include "HomeDyn15.h"

int main()
{
    using namespace std;
    setlocale(LC_ALL, "RU");
    int Task_number;    
    do {
        cout << "Введите номер задания(1 - BackRec9; 2 - HomeDyn3; 3 - HomeDyn15 или 0 для выходаGG) : ";
        cin >> Task_number;
        bool ok = false;
        while (!ok) {
            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                cin >> Task_number;
            }
            else {
                ok = true;
            }
        }
        switch (Task_number) {
        case(0):
            cout << "Конец кода";
            break;
        case(1):
            BackRec9();
            break;
        case(2):
            HomeDyn3();
            break;
        case(3):
            HomeDyn15();
            break;
        default:
            if (!ok) {
                cout << "ОШИБКА\n";
            }
            break;
        }
    } 
    while (Task_number != 0);
    return 0;
}
