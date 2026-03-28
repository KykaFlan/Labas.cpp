#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <iomanip>
#include "STL3Alg60.h"
#include "validation.h"

class Average {
public:
    double operator()(int a, int b) const {
        return (a + b) / 2.0;
    }
};

void STL3Alg60() {
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
        cout << "Введите количество элементов (минимум 2): ";
        int n = Validation::getIntMin(2);
        cout << "Введите " << n << " чисел:\n";

        for (int i = 0; i < n; ++i) {
            cout << "Элемент " << i + 1 << ": ";
            int val = Validation::getInt();
            L.push_back(val);
        }
        break;
    }
    case 2: {
        while (true) {
            cout << "Введите имя файла: ";
            string filename = Validation::getValidFile();

            ifstream file(filename);
            list<int> temp((istream_iterator<int>(file)), istream_iterator<int>());
            file.close();

            if (temp.size() < 2) {
                cout << "Ошибка! Файл содержит менее 2 чисел.\n";
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
        cout << "Введите количество элементов (минимум 2): ";
        int n = Validation::getIntMin(2);
        for (int i = 0; i < n; ++i) {
            L.push_back(rand() % 100);
        }
        cout << "Сгенерировано " << n << " чисел.\n";
        break;
    }
    }

    if (L.size() < 2) {
        cout << "Ошибка! В списке менее 2 элементов.\n";
        return;
    }

    cout << "\nИсходный список: ";
    copy(L.begin(), L.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    vector<double> V;

    adjacent_difference(L.begin(), L.end(),
        back_inserter(V), // Итератор вставки (вставляет элементы в контейнер, не перезаписывая существующие)
        Average());

    // после алгоритма в начале вектора стоит первое число из L, так работает adjacent_difference (для востановление исходного списка)
    // поэтому удалим первый элемент в полученном векторе
    V.erase(V.begin());

    cout << fixed << setprecision(1);
    cout << "Средние арифметические соседних элементов: ";
    copy(V.begin(), V.end(), ostream_iterator<double>(cout, " "));
    cout << endl;

    cout << "\nНажмите Enter для продолжения...";
    cin.get();
    cin.get();
    system("cls");
}