#include <iostream>
#include "list.h"
#include "validation.h"

void ListWork68() {
    using namespace std;

    // Создаем циклический список
    CircularList list;

    // Меню выбора способа заполнения
    cout << "\nВыберите способ создания списка:\n";
    cout << "1 - С клавиатуры\n";
    cout << "2 - Из файла\n";
    cout << "3 - Случайно\n";

    cout << "Ваш выбор (1-3): ";
    int choice = Validation::getIntRange(1, 3);

    switch (choice) {
    case 1: {
        // Ввод с клавиатуры
        cout << "Введите количество элементов: ";
        int n = Validation::getIntMin(1);
        cout << "Введите " << n << " чисел:\n";

        for (int i = 0; i < n; i++) {
            cout << "Элемент " << i + 1 << ": ";
            int val = Validation::getInt(); 
            list.append(val);
        }
        break;
    }
    case 2: {
        // Ввод имени файла с проверкой
        cout << "Введите имя файла: ";
        string filename = Validation::getValidFile();

        // Теперь нужно прочитать числа из файла
        ifstream file(filename);
        int val;
        while (file >> val) {
            list.append(val);
        }
        file.close();

        cout << "Файл загружен.\n";
        break;
    }
    case 3: {
        // Случайная генерация
        cout << "Введите количество элементов: ";
        int n = Validation::getIntMin(1);  // без строки-приглашения
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
    Node* P1 = list.getHead();

    // Вывод исходного состояния
    cout << "\nИсходный циклический список: ";
    list.print();
    cout << "P1 (адрес первого элемента): " << P1;
    if (P1) cout << ", значение: " << P1->data;
    cout << endl;

    // Создаем копию ДО обработки
    cout << "\nСоздаем копию списка (конструктор копирования)\n";
    CircularList listCopy = list;

    // Имя выходного файла
    string filename = "listwork68Result.txt";
    cout << "Результат будет сохранен в файл: " << filename << endl;

    // Выполняем обработку с шагом 4
    list.processWithStepToFile(4, filename);

    // Демонстрация копирования
    cout << "\nДемонстрация копирования\n";
    cout << "Оригинал (после обработки): ";
    list.print();
    cout << "Копия (созданная до обработки): ";
    listCopy.print();

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
    // Поиск элемента по значению
    listCopy.find(n);
    cout << endl;

    // Деструктор автоматически запускается после завершения функции
}