#include <iostream>
#include <fstream>
#include "Blist.h"
#include "validation.h"

void ListWork48() {
    using namespace std;

    // Создаем список с барьером
    BarrierList list;

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
        cout << "Введите имя файла: ";
        string filename = Validation::getValidFile();

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

    if (list.isEmpty()) {
        cout << "Ошибка! Список пуст!" << endl;
        return;
    }

    // Сохраняем указатели на барьер и текущий элемент
    DNode* P1 = list.getBarrier();
    DNode* P2 = list.getCurrent();

    // Вывод исходного состояния
    cout << "\nИсходный список (реальные элементы): ";
    list.print();
    cout << "P1 (адрес барьера): " << P1 << ", значение: " << P1->data << " (барьер)\n";
    cout << "P2 (адрес текущего): " << P2;
    if (P2 == P1) cout << " (барьер)";
    cout << endl;

    // Создаем копию до обработки
    cout << "\nСоздаем копию списка (конструктор копирования)\n";
    BarrierList listCopy = list;
    cout << "Копия создана\n";

    // Выполняем обнуление элементов с нечетными номерами
    cout << "\nВыполняем обнуление нечетных элементов\n";
    list.LBTofirst(); // переходим к первому реальному элементу
    int position = 1;
    DNode* lastElement = nullptr;

    while (true) {
       
        if (position % 2 != 0) {
            cout << "  Элемент " << position << " (" << list.getCurrent()->data << ") -> 0\n";
            list.LBSetData(0);
        }

        // Проверяем, есть ли следующий элемент
        if (list.getCurrent()->next == list.getBarrier()) {
            // Это последний элемент, выходим из цикла
            break;
        }

        list.LBTNext();
        position++;
    }

    list.CurrentToBarrier(); // Ставим текущий на барьер

    // Вывод результата
    cout << "\nРезультат\n";
    cout << "Итоговый список: ";
    list.print();
    cout << "Количество элементов: " << list.getSize() << "\n";
    cout << "Новый адрес текущего элемента: " << list.getCurrent();
    if (list.getCurrent() && list.getCurrent() != list.getBarrier()) {
        cout << ", значение: " << list.getCurrent()->data;
    }
    cout << endl;

    // Проверка независимости копии
    cout << "\nДобавляем элемент 6752 в копию:\n";
    listCopy.append(6752);
    cout << "Оригинал: ";
    list.print();
    cout << "Копия: ";
    listCopy.print();
    cout << endl;

    // Поиск в копии
    cout << "Введите число для поиска в копии: ";
    int n = Validation::getInt();
    listCopy.find(n);

    // Деструктор автоматически запускается после завершения функции
}
