#include <iostream>
#include <fstream>
#include "TList.h"
#include "validation.h"

void ListWork45() {
    using namespace std;

    // Создаем список
    TList list;

    // Меню выбора способа заполнения
    cout << "\nВыберите способ создания списка:\n";
    cout << "1 - С клавиатуры\n";
    cout << "2 - Из файла\n";
    cout << "3 - Случайно\n";

    cout << "Ваш выбор (1-3): ";
    int choice = Validation::getIntRange(1, 3);

    switch (choice) {
    case 1: {
        cout << "Введите количество элементов: ";
        int n = Validation::getIntMin(1);
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

        // Читаем числа из проверенного файла
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
        cout << "Введите количество элементов: ";
        int n = Validation::getIntMin(1);
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

    // Сохраняем указатели на первый и последний элементы
    DNode* P1 = list.getFirst();
    DNode* P2 = list.getLast();
    // Устанавливаем текущий элемент на позицию 1
    list.ToFirst();
    DNode* P3 = list.getCurrent();

    // Вывод исходного состояния
    cout << "\nИсходный список: ";
    list.print();
    cout << "P1 (адрес первого элемента): " << P1;
    if (P1) cout << ", значение: " << P1->data;
    cout << "\nP2 (адрес последнего элемента): " << P2;
    if (P2) cout << ", значение: " << P2->data;
    cout << "\nP3 (адрес текущего элемента): " << P3;
    if (P3) cout << ", значение: " << P3->data;

    // Создаем копию до обработки
    cout << "\nСоздаем копию списка (конструктор копирования)\n";
    TList listCopy = list;
    cout << "Копия создана\n";

    // Выполняем обнуление элементов с нечетными номерами
    cout << "\nВыполняем обнуление нечетных элементов\n";

    list.ToFirst();
    int position = 1;

    // Удаляем зануляем элементы на нечётных позициях
    while (true) {
        if (position % 2 != 0) {
            cout << "Элемент " << position << " (" << list.getCurrent()->data << ") -> 0\n";
            list.SetData(0);
        }

        if (list.IsLast()) break;
        list.ToNext();
        position++;
    }

    // Вывод результата
    cout << "\nРезультат\n";
    cout << "Итоговый список: ";
    list.print();
    cout << "\nНовые адреса:\n";
    cout << "P1 (первый элемент): " << list.getFirst();
    if (list.getFirst()) cout << ", значение: " << list.getFirst()->data;
    cout << "\nP2 (последний элемент): " << list.getLast();
    if (list.getLast()) cout << ", значение: " << list.getLast()->data;
    cout << "\nP3 (текущий элемент): " << list.getCurrent();
    if (list.getCurrent()) cout << ", значение: " << list.getCurrent()->data;
    cout << endl;

    // Проверка независимости копии
    cout << "\nДобавляем элемент 6752 в копию:\n";
    listCopy.append(6752);
    cout << "Оригинал: ";
    list.print();
    cout << "Копия: ";
    listCopy.print();
    cout << endl;

    // Демонстрация поиска по значению
    cout << "Введите число которое нужно найти в копии: ";
    int n = Validation::getInt();
    listCopy.find(n);

    // Деструктор автоматически запускается после завершения функции
}
