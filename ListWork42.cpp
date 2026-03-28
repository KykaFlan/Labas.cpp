#include <iostream>
#include <vector>
#include <fstream>
#include "CircularDlist.h"
#include "validation.h"

void ListWork42() {
    using namespace std;

    // Создаем циклический двусвязный список
    CircularDoubleList list;

    // Меню выбора способа заполнения
    cout << "\nВыберите способ создания списка:\n";
    cout << "1 - С клавиатуры\n";
    cout << "2 - Из файла\n";
    cout << "3 - Случайно\n";

    cout << "Ваш выбор (1-3): ";
    int choice = Validation::getIntRange(1, 3);

    switch (choice) {
    case 1: {
        cout << "Введите количество элементов (минимум 2): ";
        int n = Validation::getIntMin(2);
        cout << "Введите " << n << " чисел:\n";

        for (int i = 0; i < n; i++) {
            cout << "  Элемент " << i + 1 << ": ";
            int val = Validation::getInt();
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
        cout << "Введите количество элементов (минимум 2): ";
        int n = Validation::getIntMin(2);
        list.fillRandom(n);
        cout << "Сгенерировано " << n << " случайных чисел.\n";
        break;
    }
    }

    // Проверка на пустоту
    if (list.isEmpty()) {
        cout << "Ошибка! Список пуст!" << endl;
        return;
    }

    // Сохраняем указатель на первый элемент P1
    DNode* P1 = list.getHead();

    // Вывод исходного состояния
    cout << "\nИсходный циклический список: ";
    list.print();
    cout << "\nP1 (адрес первого элемента): " << P1;
    if (P1) cout << ", значение: " << P1->data;
    cout << endl;

    // Создаем копию до обработки
    cout << "\nСоздаем копию списка (конструктор копирования)\n";
    CircularDoubleList listCopy = list;
    cout << "Копия создана\n";

    // Выполняем удаление элементов с равными соседями
    cout << "\nВыполняем удаление\n";
    DNode* lastElement = list.removeIfNeighborsEqual();

    // Вывод результата
    cout << "\nРезультат\n";
    cout << "Итоговый список: ";
    list.print();
    cout << "\nУказатель на последний элемент: " << lastElement;
    if (lastElement) cout << ", значение: " << lastElement->data;
    cout << endl;


    // Проверка независимости копии
    cout << "\nДобавляем элемент 6752 в копию:\n";
    listCopy.append(6752);
    cout << "Оригинал: ";
    list.print();
    cout << endl;
    cout << "Копия: ";
    listCopy.print();
    cout << endl;
    
    // Демонстрация поиска по значению
    cout << "\nВведите число которое нужно найти в копии: ";
    int n = Validation::getInt();
    listCopy.find(n);

    // Деструктор автоматически запускается после завершения функции
}