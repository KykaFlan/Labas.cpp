#include <iostream>
#include <deque>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "STL3Alg18.h"
#include "validation.h"

class Sequence {
private:
    int& value;  // ссылка на внешнюю переменную
public:
    Sequence(int& v) : value(v) {}

    int operator()() {
        return value++;
    }
};

void STL3Alg18() {
    using namespace std;

    deque<int> D;
    int choice;
    int N;

    cout << "Введите N (> 0): ";
    N = Validation::getIntMin(1);

    // Создаем дек с размером 2*N
    D.resize(2 * N);

    cout << "Выберите способ начального заполнения (будет перезаписано):\n";
    cout << "1 - С клавиатуры\n";
    cout << "2 - Из файла\n";
    cout << "3 - Случайно\n";
    cout << "Ваш выбор: ";
    choice = Validation::getIntRange(1, 3);

    switch (choice) {
    case 1: {
        cout << "Введите " << 2 * N << " чисел (будут перезаписаны):\n";
        for (int i = 0; i < 2 * N; ++i) {
            cout << "Элемент " << i + 1 << ": ";
            D[i] = Validation::getInt();
        }
        break;
    }
    case 2: {
        while (true) {
            cout << "Введите имя файла: ";
            string filename = Validation::getValidFile();

            ifstream file(filename);
            deque<int> temp((istream_iterator<int>(file)), istream_iterator<int>());
            file.close();

            if (temp.size() < 2 * N) {
                cout << "Ошибка! Файл содержит менее " << 2 * N << " чисел.\n";
            }
            else {
                copy(temp.begin(), temp.begin() + 2 * N, D.begin());
                break;
            }
        }
        cout << "Загружено " << 2 * N << " чисел.\n";
        break;
    }
    case 3: {
        srand(time(nullptr));
        for (int i = 0; i < 2 * N; i++) {
            D[i] = rand() % 100;
        }
        cout << "Сгенерировано " << 2 * N << " чисел.\n";
        break;
    }
    }

    // Вывод исходного дека
    cout << "\nИсходный дек: ";
    copy(D.begin(), D.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    // Создаем переменную которую будет вставлять и увеличивать
    int current = 1;
    Sequence F(current);

    // Вставляем первые N числа
    generate(D.begin(), D.begin() + N, F);

    // Заединичим число
    current = 1;

    // Заполням с конца до следующего элемента после первой пололвины 
    generate(D.rbegin(), D.rbegin() + N, F);

    // Вывод результата
    cout << "Результат: ";
    copy(D.begin(), D.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    cout << "\nНажмите Enter для продолжения...";
    cin.get();
    cin.get();
    system("cls");
}