#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>
#include "STL3Alg4.h"
#include "validation.h"

class Negrative {
public:
    bool operator()(int x) const {
        return x < 0;
    }
};
void STL3Alg4() {
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
        cout << "Введите количество элементов: ";
        int n = Validation::getIntMin(1);
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

            if (temp.empty()) {
                cout << "Ошибка! Файл пуст.\n";
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
        cout << "Введите количество элементов: ";
        int n = Validation::getIntMin(1);
        for (int i = 0; i < n; i++) {
            L.push_back(rand() % 201 - 100);        
        }
        cout << "Сгенерировано " << n << " чисел.\n";
        break;
    }
    }

    if (L.empty()) {
        cout << "Список пуст!\n";
        return;
    }

    // Вывод исходного списка
    cout << "\nИсходный список: ";
    copy(L.begin(), L.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    // Находим первый отрицательный элемент
    list<int>::iterator firstNeg = find_if(L.begin(), L.end(), Negrative());

    // Если нет отрицательных
    if (firstNeg == L.end()) {
        cout << "Отрицательных элементов нет. Список не изменён.\n";
    }
    else {
        // Сдвигаем итератор на следующее число т.к. будет браться диапазом [)
        firstNeg++;
        // Ищем второй отрицательный элемент
        list<int>::iterator secondNeg = find_if(firstNeg, L.end(), Negrative());

        if (secondNeg == L.end()) {
            // Только один отрицательный — удаляем все элементы после него
            L.erase(firstNeg, L.end());
            cout << "Только один отрицательный. Удалены элементы после него.\n";
        }
        else {
            // Удаляем элементы между firstNeg и secondNeg
            L.erase(firstNeg, secondNeg);
            cout << "Удалены элементы между первым и вторым отрицательными.\n";
        }
    }

    // Вывод результата
    cout << "Результат: ";
    copy(L.begin(), L.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    cout << "\nНажмите Enter для продолжения...";
    cin.get();
    cin.get();
    system("cls");
}