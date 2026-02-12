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
        cout << "Введите номер задания(1 - BackRec9; 2 - HomeDyn3; 3 - HomeDyn15 или 0 для выхода) : ";
        cin >> Task_number;
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
            cout << "ОШИБКА\n";
        }
    } 
    while (Task_number != 0);
    return 0;
}
