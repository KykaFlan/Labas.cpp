#include <iostream>
#include "ListWork24.h"
#include "list.h"

void ListWork24() {
    using namespace std;
    // Создаем пустой список (конструктор по умолчанию)
    LinkedList list;

    // Меню выбора способа заполнения списка
    cout << "Выберите способ создания списка:" << endl;
    cout << "1 - с клавиатуры" << endl;
    cout << "2 - из файла" << endl;
    cout << "3 - случайно" << endl;
    cout << "Ваш выбор: ";

    int choice;
    cin >> choice;

    // Обработка выбора пользователя
    switch (choice) {
    case 1:  // Ввод с клавиатуры
        list.fillFromKeyboard();
        break;

    case 2: {  // Чтение из файла
        string filename;
        cout << "Введите имя файла: ";
        cin >> filename;
        list.fillFromFile(filename);
        break;
    }

    case 3: {  // Случайная генерация
        int n;
        cout << "Введите количество элементов: ";
        cin >> n;
        list.fillRandom(n);
        break;
    }

    default:  // Неверный выбор
        cout << "Неверный выбор" << endl;
        return;
    }

    // Проверяем на не пустоту списка
    if (list.isEmpty()) {
        cout << "Список пуст. Операция невозможна." << endl;
        return;
    }


    int M;
    cout << "\nВведите значение M для вставки: ";
    cin >> M;

    // Сохраняем указатель на голову P1
    Node* P1 = list.getHead();

    // Вывод исходного состояния
    cout << "\nИсходный список:" << endl;
    cout << "Элементы: ";
    list.print();
    cout << "P1 (адрес головы): " << P1;
    if (P1) cout << ", значение первого элемента: " << P1->data;
    cout << endl;

    // Выполняем вставку значения M после каждого 4-го элемента
    list.insertAfterEveryK(4, M);

    // Получаем последний элемент P2
    Node* P2 = list.getLastNode();

    // Вывод результата
    cout << "\nРезультирующий список:" << endl;
    cout << "Элементы: ";
    list.print();

    cout << "\nИтоги:" << endl;
    cout << "P1 (адрес головы): " << P1 << " (не изменился)" << endl;
    cout << "P2 (адрес последнего элемента): " << P2;
    if (P2) cout << ", значение: " << P2->data;
    cout << endl;

    // Демонстрация поиска по значению
    cout << "\nВведите число которое нужно найти: ";
    int n;
    cin >> n;
    list.find(n);
    cout << endl;

    // Демонстрация конструктора копирования
    cout << "Демонстрация копирования" << endl;
    cout << "Создаем копию списка:" << endl;

    LinkedList listCopy = list;

    cout << "Оригинальный список: ";
    list.print();
    cout << "Копия списка: ";
    listCopy.print();

    // Демонстрация независимости копии от оригинала
    cout << "\nИзменяем оригинал (добавляем элемент в конец '6752')" << endl;
    list.append(6752);

    cout << "Оригинальный список (изменился): ";
    list.print();
    cout << "Копия списка (не изменилась): ";
    listCopy.print();
    cout << endl;

    // После завершения функции автоматически запускается деструктор
}