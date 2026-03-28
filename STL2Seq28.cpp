#include <iostream>
#include <deque>
#include <algorithm>
#include <iterator>
#include "STL2Seq28.h"
#include "validation.h"

void STL2Seq28() {
    using namespace std;

    deque<int> D;
    int choice;

    cout << "Выберите способ заполнения:\n";
    cout << "1 - С клавиатуры\n";
    cout << "2 - Из файла\n";
    cout << "3 - Случайно\n";
    cout << "Ваш выбор: ";
    choice = Validation::getIntRange(1, 3);

    switch (choice) {
    case 1: {
        cout << "Введите количество элементов (кратно 4): ";
        int n;
        while (true) {
            n = Validation::getIntMin(4);
            if (n % 4 != 0) {
                cout << "Ошибка! Количество должно быть кратно 4. Попробуйте снова: ";
            }
            else {
                break;
            }
        }
        cout << "Введите " << n << " чисел:\n";

        deque<int> temp(n);
        deque<int>::iterator it;
        int i = 1;
        for (it = temp.begin(); it != temp.end(); it++) {
            cout << "Элемент " << i << ": ";
            *it = Validation::getInt();
            i++;
        }
        D = temp;
        break;
    }
    case 2: {
        while (true) {
            cout << "Введите имя файла: ";
            string filename = Validation::getValidFile();

            ifstream file(filename);
            deque<int> temp((istream_iterator<int>(file)), istream_iterator<int>());
            file.close();

            if (temp.size() % 4 != 0) {
                cout << "Ошибка! Количество элементов должно быть кратно 4\n";
            }
            else {
                D = temp;
                break;
            }
        }
        cout << "Загружено " << D.size() << " чисел.\n";
        break;
    }
    case 3: {
        cout << "Введите количество элементов (кратно 4): ";
        int n;
        while (true) {
            n = Validation::getIntMin(4);
            if (n % 4 != 0) {
                cout << "Ошибка! Количество должно быть кратно 4. Попробуйте снова: ";
            }
            else {
                break;
            }
        }

        deque<int> temp(n);
        deque<int>::iterator it;
        for (it = temp.begin(); it != temp.end(); it++) {
            *it = rand() % 100;
        }
        D = temp;
        break;
    }
    }

    if (D.empty()) {
        cout << "Ошибка! Дек пуст!\n";
        return;
    }

    // Вывод исходного дека
    cout << "\nИсходный дек: ";
    deque<int>::iterator it;
    for (it = D.begin(); it != D.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    int N = D.size();
    int iterations = N / 4;

    deque<int>::iterator i = D.begin();

    for (int k = 1; k < iterations; k++) {
         // переходим на четный элемент
        i = D.erase(++i); // удаляем и получаем новый итератор (теперь нечётный)
    }

    // Вывод результата
    cout << "Результат: ";
    for (it = D.begin(); it != D.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    cout << "\nНажмите Enter для продолжения...";
    cin.get();
    cin.get();
    system("cls");
}
