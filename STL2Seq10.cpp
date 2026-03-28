#include <iostream>
#include <list>
#include <iterator>
#include "STL2Seq10.h"
#include "validation.h"

void STL2Seq10() {
    using namespace std;

    list<int> L;
    int choice;

    cout << "Выберите способ заполнения:\n";
    cout << "1 - С клавиатуры\n";
    cout << "2 - Из файла\n";
    cout << "3 - Случайно\n";
    cout << "Ваш выбор: ";
    choice = Validation::getIntRange(1, 3);

    switch (choice) {
    case 1: {
        cout << "Введите количество элементов (кратно 3): ";
        int n;
        while (true) {
            n = Validation::getIntMin(3);
            if (n % 3 != 0) {
                cout << "Ошибка! Количество должно быть кратно 3. Попробуйте снова: ";
            }
            else {
                break;
            }
        }
        cout << "Введите " << n << " чисел:\n";

        list<int> temp(n);
        list<int>::iterator it;
        int i = 1;
        for (it = temp.begin(); it != temp.end(); it++) {
            cout << "Элемент " << i << ": ";
            int val = Validation::getInt();
            *it = val;
            i++;
        }

        L = temp;
        break;
    }
    case 2: {
        while (true) {
            cout << "Введите имя файла: ";
            string filename = Validation::getValidFile();

            ifstream file(filename);

            // Читаем сразу в список через итераторы!
            list<int> temp((istream_iterator<int>(file)), istream_iterator<int>());
            file.close();

            if (temp.size() % 3 != 0) {
                cout << "Ошибка! Количество элементов должно быть кратно 3\n";                
            }
            else {
                L = temp;
                break;
            }
        }
        cout << "Загружено " << L.size() << " чисел.\n";
        break;
    }
    case 3: {
        cout << "Введите количество элементов (кратно 3): ";
        int n;
        while (true) {
            n = Validation::getIntMin(3);
            if (n % 3 != 0) {
                cout << "Ошибка! Количество должно быть кратно 3. Попробуйте снова: ";
            }
            else {
                break;
            }
        }

        list<int> temp(n);
        list<int>::iterator it;
        for (it = temp.begin(); it != temp.end(); it++) {
            *it = rand() % 100;
        }

        L = temp;
        break;
    }
    }

    if (L.empty()) {
        cout << "Ошибка! Список пуст!\n";
        return;
    }

    // Вывод исходного списка
    cout << "\nИсходный список: ";
    list<int>::iterator it;
    for (it = L.begin(); it != L.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    int SizeThird = L.size() / 3;

    // Создаем итераторы на начало и конец первой трети
    list<int>::iterator start = L.begin();
    list<int>::iterator end = L.begin();
    for (int i = 0; i < SizeThird; i++) {
        end++;
    }

    // Первая треть
    list<int> FirstThird(start, end);

    // Вставляем первую треть в конце с конца трети до начала трети
    L.insert(L.end(), FirstThird.rbegin(), FirstThird.rend());

    // Вывод результата
    cout << "Результат: ";
    for (it = L.begin(); it != L.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    cout << "\nНажмите Enter для продолжения...";
    cin.get();
    cin.get();
    system("cls");
}
