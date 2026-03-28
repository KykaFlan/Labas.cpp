#include <iostream>
#include <fstream>
#include <vector>
#include "list.h"
#include "validation.h"

void Task3() {
    using namespace std;

    // Создаем циклический список
    CircularList list;

    // Меню выбора способа заполнения
    cout << "\nВыберите способ создания списка:\n";
    cout << "1 - С клавиатуры\n";
    cout << "2 - Из файла\n";
    cout << "3 - Случайно\n";

    cout << "Ваш выбор (1-3): ";
    int choice = Validation::getIntRange(1, 3);  // убрали строку, диапазон 1-3

    switch (choice) {
    case 1: {
        cout << "Введите количество элементов: ";
        int n = Validation::getIntMin(1);  // убрали строку
        cout << "Введите " << n << " чисел:\n";
        for (int i = 0; i < n; i++) {
            cout << "Элемент " << i + 1 << ": ";
            int val = Validation::getInt();  // просто getInt()
            list.append(val);
        }
        break;
    }
    case 2: {
        // Ввод имени файла с проверкой
        cout << "Введите имя файла: ";
        string filename = Validation::getValidFile();

        // Читаем числа из файла
        vector<int> data;
        ifstream file(filename);
        int val;
        while (file >> val) {
            data.push_back(val);
        }
        file.close();

        // Добавляем в список
        for (int v : data) {
            list.append(v);
        }
        cout << "Файл загружен. Добавлено " << data.size() << " чисел.\n";
        break;
    }
    case 3: {
        cout << "Введите количество элементов: ";
        int n = Validation::getIntMin(1);  // убрали строку
        list.fillRandom(n);
        cout << "Сгенерировано " << n << " случайных чисел.\n";
        break;
    }
    }

    if (list.isEmpty()) {
        cout << "Ошибка! Список пуст\n";
        return;
    }

    Node* P1 = list.getHead();

    cout << "\nИсходный циклический список:\n   ";
    list.print();
    cout << "P1 (адрес): " << P1 << ", значение: " << P1->data << "\n";

    // Создаем копию
    cout << "\nСоздаем копию списка.\n";
    CircularList listCopy = list;

    // Поиск последовательности и вывод результата (всё происходит в методе)
    cout << "\n";
    list.findLongestNegativeSequence();

    // Проверка независимости копии
    cout << "\nДобавляем элемент 6752 в копию:\n";
    listCopy.append(6752);
    cout << "Оригинал: ";
    list.print();
    cout << "Копия: ";
    listCopy.print();
    cout << endl;

    // Демонстрация поиска по значению
    cout << "\nВведите число которое нужно найти в копии: ";
    int n = Validation::getInt();
    listCopy.find(n);

    // Деструктор автоматически запускается после завершения функции
}
