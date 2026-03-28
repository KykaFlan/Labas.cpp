#include <iostream>
#include "Dynamic5.h"
#include "Dynamic22.h"
#include "ListWork3.h"
#include "ListWork24.h"
#include "ListWork61.h"
#include <cstdlib>
#include <ctime>

int main() {
    using namespace std;
    setlocale(LC_ALL, "RU");
    int number;

    do {
        cout << "1-Dynamic5 2-Dynamic22 3-ListWork3 4-ListWork24 5-ListWork61 0-Выход\n";
        cout << "Выбор: ";
        cin >> number;
        if (cin.fail() || number < 0 || number > 5) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Ошибка! Введите 0-5\n";
            continue;
        }
        cout << endl;
        switch (number) {
        case 1: Dynamic5(); break;
        case 2: Dynamic22(); break;
        case 3: ListWork3(); break;
        case 4: ListWork24(); break;
        case 5: ListWork61(); break;
        case 0: cout << "Выход"; break;
        }
    } while (number != 0);
    return 0;
}