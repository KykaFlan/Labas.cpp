#include <iostream>
#include <cstdlib>
#include <ctime>
#include "STL2Seq3.h"
#include "STL2Seq10.h"
#include "STL2Seq28.h"
#include "STL1Iter10.h"
#include "validation.h"

int main() {
    setlocale(LC_ALL, "RU");
    using namespace std;
    srand(time(nullptr)); // для случайных чисел

    int choice;

    do {
        cout << "\n=^.^= Меню лабораторной работы 12 (Вариант 3) =^.^=\n";
        cout << "1 - STL2Seq3\n";
        cout << "2 - STL2Seq10\n";
        cout << "3 - STL2Seq28\n";
        cout << "4 - STL1Iter10\n";
        cout << "0 - Выход\n";

        cout << "Ваш выбор: ";
        choice = Validation::getIntRange(0, 4);

        switch (choice) {
        case 1: STL2Seq3(); break;
        case 2: STL2Seq10(); break;
        case 3: STL2Seq28(); break;
        case 4: STL1Iter10(); break;
        case 0: cout << "Выход\n"; break;
        }
    } while (choice != 0);

    return 0;
}