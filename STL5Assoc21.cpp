#include <iostream>
#include <vector>
#include <map>
#include <iterator>
#include "STL5Assoc21.h"
#include "validation.h"

void STL5Assoc21() {
    using namespace std;
    srand(static_cast<unsigned>(time(nullptr)));

    vector<int> V;
    int choice;

    cout << "Выберите способ заполнения:\n";
    cout << "1 - С клавиатуры\n";
    cout << "2 - Из файла\n";
    cout << "3 - Случайно\n";
    cout << "Ваш выбор: ";
    choice = Validation::getIntRange(1, 3);

    switch (choice) {
    case 1: {
        cout << "Введите количество элементов: ";
        int n = Validation::getIntMin(1);
        cout << "Введите " << n << " чисел:\n";
        for (int i = 0; i < n; ++i) {
            cout << "Элемент " << i + 1 << ": ";
            int val = Validation::getInt();
            V.push_back(val);
        }
        break;
    }
    case 2: {
        while (true) {
            cout << "Введите имя файла: ";
            string filename = Validation::getValidFile();

            ifstream file(filename);
            vector<int> temp((istream_iterator<int>(file)), istream_iterator<int>());
            file.close();

            if (temp.empty()) {
                cout << "Ошибка! Файл пуст.\n";
            }
            else {
                V = temp;
                break;
            }
        }
        cout << "Загружено " << V.size() << " чисел.\n";
        break;
    }
    case 3: {
        cout << "Введите количество элементов: ";
        int n = Validation::getIntMin(1);
        for (int i = 0; i < n; i++) {
            V.push_back(rand() % 1000);
        }
        break;
    }
    }

    if (V.empty()) {
        cout << "Вектор пуст!\n";
        return;
    }

    // Вывод исходного вектора
    cout << "\nИсходный вектор: ";
    for (vector<int>::iterator it = V.begin(); it != V.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    // мультиотображение (последняя цифра - ключ, число - значение)
    multimap<int, int> M;

    // Заполнение мультиотображения
    vector<int>::iterator it;
    for (it = V.begin(); it != V.end(); it++) {
        int lastDigit = abs(*it) % 10;  // последняя цифра (учитываем отрицательные)
        M.insert(pair<int, int> (lastDigit, *it));
    }

    // Вывод результата
    cout << "\nРезультат группировки (последняя цифра - число):\n";
    multimap<int, int>::iterator it1;
    for (it1 = M.begin(); it1 != M.end(); it1++) {
        cout << (*it1).first << " - " << (*it1).second << endl;
    }

    cout << "\nНажмите Enter для продолжения...";
    cin.get();
    cin.get();
    system("cls");
}