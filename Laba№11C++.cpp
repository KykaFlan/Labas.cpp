#include <iostream>
#include <cstdlib>
#include <ctime>
#include "ListWork68.h"
#include "ListWork42.h"
#include "ListWork45.h"
#include "ListWork48.h"
#include "Task3.h"
#include "validation.h"

int main() {
    using namespace std;
    setlocale(LC_ALL, "RU");
    int number;

    do {
        cout << "\n=^.^=   =^.^=   Задачи   =^.^=   =^.^=\n";
        cout << "1 - ListWork68 (Цикл. список с шагом 4)\n";
        cout << "2 - ListWork42 (Цикл. двусвязный список)\n";
        cout << "3 - ListWork45 (Двусвязный список с TList)\n";
        cout << "4 - ListWork48 (Двусвязный список с BTList)\n";
        cout << "5 - Задача 3 (Цикл. список  поиск самой длинной отриц последовательности)\n";
        cout << "0 - Выход\n";
        cout << "Ваш выбор (0-5): ";
        number = Validation::getIntRange(0, 5);

        cout << endl;
        switch (number) {
        case 1: ListWork68(); break;
        case 2: ListWork42(); break;
        case 3: ListWork45(); break;
        case 4: ListWork48(); break;
        case 5: Task3(); break;
        case 0: cout << "Выход\n"; break;
        }
    } while (number != 0);

    return 0;
}