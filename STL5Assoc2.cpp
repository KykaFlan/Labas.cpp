#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "STL5Assoc2.h"
#include "validation.h"

void STL5Assoc2() {
    using namespace std;
    srand(static_cast<unsigned>(time(nullptr)));

    // Ввод вектора V0
    vector<int> V0;
    cout << "\nЗаполнение эталонного вектора V0\n";
    cout << "Выберите способ заполнения:\n";
    cout << "1 - С клавиатуры\n";
    cout << "2 - Из файла\n";
    cout << "3 - Случайно\n";
    cout << "Ваш выбор: ";
    int choiceV0 = Validation::getIntRange(1, 3);

    switch (choiceV0) {
    case 1: {
        cout << "Введите количество элементов: ";
        int n = Validation::getIntMin(1);
        cout << "Введите " << n << " чисел:\n";
        V0.resize(n);
        for (int i = 0; i < n; i++) {
            cout << "Элемент " << i + 1 << ": ";
            V0[i] = Validation::getInt();
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
                cout << "Ошибка! Файл пуст. Попробуйте снова.\n";
            }
            else {
                V0 = temp;
                break;
            }
        }
        cout << "Загружено " << V0.size() << " чисел.\n";
        break;
    }
    case 3: {
        cout << "Введите количество элементов: ";
        int n = Validation::getIntMin(1);
        V0.resize(n);
        for (int i = 0; i < n; i++) {
            V0[i] = rand() % 201 - 100;
        }
        break;
    }
    }

    if (V0.empty()) {
        cout << "Ошибка! Вектор V0 пуст!\n";
        return;
    }

    // Создаем множество из V0
    set<int> setV0(V0.begin(), V0.end());

    // Вывод V0 через copy
    cout << "\nV0 = ";
    copy(V0.begin(), V0.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    // Вывод уникальных элементов V0
    cout << "Уникальные элементы V0: ";
    copy(setV0.begin(), setV0.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    // Ввод количества векторов
    cout << "\nВведите количество векторов N: ";
    int N = Validation::getIntMin(1);

    int count = 0;

    // Обрабатываем каждый вектор Vi
    for (int i = 1; i <= N; i++) {
        cout << "\nЗаполнение вектора V" << i << endl;
        cout << "Выберите способ заполнения:\n";
        cout << "1 - С клавиатуры\n";
        cout << "2 - Из файла\n";
        cout << "3 - Случайно\n";
        cout << "Ваш выбор: ";
        int choiceVi = Validation::getIntRange(1, 3);

        vector<int> Vi;

        switch (choiceVi) {
        case 1: {
            cout << "Введите количество элементов: ";
            int n = Validation::getIntMin(setV0.size());
            cout << "Введите " << n << " чисел:\n";
            Vi.resize(n);
            for (int j = 0; j < n; ++j) {
                cout << "Элемент " << j + 1 << ": ";
                Vi[j] = Validation::getInt();
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
                    cout << "Ошибка! Файл пуст. Попробуйте снова.\n";
                }
                else if (temp.size() < setV0.size()) {
                    cout << "Ошибка! Файл содержит " << temp.size()
                        << " чисел, но нужно минимум " << setV0.size() << ".\n";
                }
                else {
                    Vi = temp;
                    break;
                }
            }
            break;
        }
        case 3: {
            cout << "Введите количество элементов: ";
            int n = Validation::getIntMin(setV0.size());
            Vi.resize(n);
            for (int j = 0; j < n; ++j) {
                Vi[j] = rand() % 201 - 100;
            }
            break;
        }
        }

        if (Vi.empty()) {
            cout << "Вектор V" << i << " пуст, пропускаем.\n";
            continue;
        }

        // Вывод Vi
        cout << "V" << i << " = ";
        copy(Vi.begin(), Vi.end(), ostream_iterator<int>(cout, " "));
        cout << endl;

        // Создаем множество из Vi
        set<int> setVi(Vi.begin(), Vi.end());

        // Проверяем, содержит ли setVi все элементы setV0
        if (includes(setVi.begin(), setVi.end(), setV0.begin(), setV0.end())) {
            cout << "Вектор V" << i << " содержит все элементы V0\n";
            count++;
        }
        else {
            cout << "Вектор V" << i << " не содержит все элементы V0\n";
        }
    }

    cout << "\nРезультат: " << count << " векторов содержат все элементы V0\n";

    cout << "\nНажмите Enter для продолжения...";
    cin.get();
    cin.get();
    system("cls");
}