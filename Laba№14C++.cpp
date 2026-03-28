#include <iostream>
#include <cstdlib>
#include <ctime>
#include "STL5Assoc2.h"
#include "STL5Assoc17.h"
#include "STL5Assoc21.h"
#include "validation.h"

int main() {
    setlocale(LC_ALL, "RU");
    using namespace std;
    srand(time(nullptr)); // для случайных чисел

    int choice;

    do {
        cout << "\n=^.^= Меню лабораторной работы 13 (Вариант 3) =^.^=\n";
        cout << "1 - STL5Assoc2\n";
        cout << "2 - STL5Assoc17\n";
        cout << "3 - STL5Assoc21\n";
        cout << "0 - Выход\n";

        cout << "Ваш выбор: ";
        choice = Validation::getIntRange(0, 4);

        switch (choice) {
        case 1: STL5Assoc2(); break;
        case 2: STL5Assoc17(); break;
        case 3: STL5Assoc21(); break;
        case 0: cout << "Выход\n"; break;
        }
    } while (choice != 0);

    return 0;
}