#include <iostream>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <sstream>
#include "STL1Iter10.h"
#include "validation.h"

void STL1Iter10() {
    using namespace std;

    int choice;
    cout << "Выберите способ ввода:\n";
    cout << "1 - С клавиатуры\n";
    cout << "2 - Из файла\n";
    cout << "Ваш выбор: ";
    choice = Validation::getIntRange(1, 2);

    switch (choice) {
    case 1: {
        string line; 
        bool valid = false;
        // cin.ignore() очищает буфер ввода от предыдущего символа '\n'
        // Это нужно, чтобы getline() не прочитал пустую строку после предыдущего cin
        cin.ignore(10000, '\n');

        // Цикл продолжается, пока пользователь не введет корректные данные
        while (!valid) {
            cout << "Введите вещественные числа через пробел (минимум 2):\n";
            getline(cin, line); // читаем всю строку целиком

            // Проверка на пустую строку
            if (line.empty()) {
                cout << "Строка пуста. Попробуйте снова.\n\n";
                continue;
            }

            // Создаем поток из строки
            // stringstream позволяет работать со строкой как с файлом или потоком ввода
            stringstream ss(line);

            streampos begin = ss.tellg(); // tellg возвращает текущую позицию

            // Подсчёт количества чисел
            int count = 0;
            double temp;
            while (ss >> temp) {
                count++;
            }

            // Достаточно ли чисел
            if (count < 2) {
                cout << "Ошибка! Введено " << count << " чисел, а нужно минимум 2.\n\n";
                continue;
            }

            // Возвращаемся начало для следующего прохода
            ss.clear();
            ss.seekg(begin);

            // Вывод чисел на чётных позициях
            int index = 1; // Счетчик позиций
            cout << "Числа на четных позициях: ";


            // Читает числа из потока ss и копирует их в cout
            // Но только если предикат возвращает false
            // которая возвращает либо true, либо false для каждого элемента списка
            remove_copy_if( // remove_copy_if — копирует, если предикат false
                istream_iterator<double>(ss), // итератор на начало потока
                istream_iterator<double>(), // итератор конца потока
                ostream_iterator<double>(cout, " "), // итератор для вывода в cout
                [&index](double) { return index++ % 2 != 0; }
            );
            // лямбда-функция (предикат)                  [&index] — захватывает переменную index по ссылке
            // Возвращаем true для нечётных позиций       (double) — принимает число
            // index++ увеличивает счетчик после проверки index++ % 2 != 0 — возвращает true при нечётной позиции
            
            cout << endl; // перевод строки после вывода

            valid = true; // отмечаем, что ввод корректен и выходим из цикла
        }
        break;
    }

    case 2: {
        // Цикл продолжается, пока не будет найден корректный файл
        while (true) {
            cout << "Введите имя файла: ";
            string filename = Validation::getValidFileDouble();

            ifstream file(filename);

            // Сохраняем позицию в начале файла
            streampos begin = file.tellg();

            // Подсчёт количества чисел
            int count = 0;
            double temp;
            while (file >> temp) {
                count++;
            }

            // Достаточно ли чисел
            if (count < 2) {
                cout << "Ошибка! Файл содержит " << count << " чисел, а нужно минимум 2. Попробуйте другой файл.\n";
                file.close();
                continue;
            }

            // Возвращаемся начало для следующего прохода
            file.clear();
            file.seekg(begin);

            // Вывод чисел на чётных позициях
            int index = 1; // Счетчик позиций
            cout << "Числа на четных позициях: ";

            remove_copy_if(
                istream_iterator<double>(file),
                istream_iterator<double>(),
                ostream_iterator<double>(cout, " "),
                [&index](double)  { return index++ % 2 != 0; }
            );
            cout << endl;

            file.close();
            break;
        }
        break;
    }
    }

    cout << "\nНажмите Enter для продолжения...";
    cin.get();
    cin.get();
    system("cls");
}