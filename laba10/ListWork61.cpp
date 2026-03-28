#include <iostream>
#include "ListWork61.h"
#include <fstream>
#include "list.h"

void ListWork61() {
    using namespace std;

    // Запрашиваем имя файла у пользователя
    string filename;
    cout << "Введите имя файла (например, data/list61.txt): ";
    cin >> filename;

    // Открываем файл для чтения
    ifstream file(filename);
    if (!file) {
        cerr << "Не удалось открыть файл!" << endl;
        return;  // Выход из функции
    }

    // Читаем количество элементов из первой строки файла
    int N;
    file >> N;

    // Создаем пустой список (конструктор по умолчанию)
    LinkedList list;

    // Выводим информацию о чтении
    cout << "\nЧтение " << N << " чисел из файла" << endl;
    cout << "Числа: ";

    // Читаем числа и вставляем их в упорядоченный список
    for (int i = 0; i < N; ++i) {
        int val;
        file >> val;
        cout << val << " ";
        list.insertSorted(val);  // Упорядоченная вставка
    }
    cout << endl;

    // Закрываем файл
    file.close();

    // Вывод результата
    cout << "\nРезультирующий упорядоченный список:" << endl;
    cout << "Элементы: ";
    list.print();

    // Получаем указатель на первый элемент P1
    Node* p1 = list.getHead();
    cout << "P1 (адрес первого элемента): " << p1;
    if (p1) cout << ", значение: " << p1->data;
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
    cout << "\nИзменяем оригинал (добавляем элемент в конец '228')" << endl;
    list.append(228);  // Добавляем элемент в оригинал

    cout << "Оригинальный список (изменился): ";
    list.print();
    cout << "Копия списка (не изменилась): ";
    listCopy.print();
    cout << endl;

    // После завершения функции автоматически запускается деструктор
}