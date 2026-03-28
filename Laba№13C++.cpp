#include <iostream>
#include <cstdlib>
#include <ctime>
#include "STL3Alg4.h"
#include "STL3Alg18.h"
#include "STL3Alg48.h"
#include "STL3Alg60.h"
#include "validation.h"

int main() {
    setlocale(LC_ALL, "RU");
    using namespace std;
    srand(time(nullptr)); // для случайных чисел

    int choice;

    do {
        cout << "\n=^.^= Меню лабораторной работы 13 (Вариант 3) =^.^=\n";
        cout << "1 - STL2Seq3\n";
        cout << "2 - STL2Seq10\n";
        cout << "3 - STL2Seq28\n";
        cout << "4 - STL1Iter10\n";
        cout << "0 - Выход\n";

        cout << "Ваш выбор: ";
        choice = Validation::getIntRange(0, 4);

        switch (choice) {
        case 1: STL3Alg4(); break;
        case 2: STL3Alg18(); break;
        case 3: STL3Alg48(); break;
        case 4: STL3Alg60(); break;
        case 0: cout << "Выход\n"; break;
        }
    } while (choice != 0);

    return 0;
}