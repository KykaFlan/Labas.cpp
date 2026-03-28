#include <iostream>
#include "queue.h"

void Dynamic22() {
    using namespace std;

    // Создаем две пустые очереди (конструкторы по умолчанию)
    Queue queue1, queue2;

    // Заполнение первой очереди
    cout << "Первая очередь" << endl;
    cout << "Выберите способ:" << endl;
    cout << "1 - с клавиатуры" << endl;
    cout << "2 - из файла" << endl;
    cout << "3 - случайно" << endl;
    cout << "Ваш выбор: ";

    int choice;
    cin >> choice;

    // Обработка выбора для первой очереди
    switch (choice) {
    case 1:  // Ввод с клавиатуры
        queue1.fillFromKeyboard();  // Пользователь вводит элементы
        break;
    case 2: {  // Чтение из файла
        string filename;
        cout << "Введите имя файла: ";
        cin >> filename;
        queue1.fillFromFile(filename);  // Чтение чисел из файла
        break;
    }
    case 3: {  // Случайная генерация
        int n;
        cout << "Введите количество элементов: ";
        cin >> n;
        queue1.fillRandom(n);  // Генерация случайных чисел
        break;
    }
    default:
        cout << "Неверный выбор";
        break;
    }

    // Заполнение второй очереди
    cout << "\nВторая очередь" << endl;
    cout << "Выберите способ:" << endl;
    cout << "1 - с клавиатуры" << endl;
    cout << "2 - из файла" << endl;
    cout << "3 - случайно" << endl;
    cout << "Ваш выбор: ";

    cin >> choice;

    // Обработка выбора для второй очереди
    switch (choice) {
    case 1:
        queue2.fillFromKeyboard();
        break;
    case 2: {
        string filename;
        cout << "Введите имя файла: ";
        cin >> filename;
        queue2.fillFromFile(filename);
        break;
    }
    case 3: {
        int n;
        cout << "Введите количество элементов: ";
        cin >> n;
        queue2.fillRandom(n);
        break;
    }
    default:
        cout << "Неверный выбор." << endl;
        break;
    }

    // Обе очереди должны быть непустыми
    if (queue1.isEmpty() || queue2.isEmpty()) {
        cout << "\nОШИБКА: По условию задачи обе очереди должны быть непустыми!" << endl;
        cout << "Пожалуйста, перезапустите программу и создайте непустые очереди." << endl;
        return;  // Выход из функции
    }

    int N;
    cout << "\nВведите количество элементов для перемещения N: ";
    cin >> N;

    if (N <= 0) {
        cout << "ОШИБКА: N должно быть больше 0!" << endl;
        return;  // Выход из функции
    }

    // Вывод исходного состояния
    cout << "Исходное состояние:" << endl;

    // Вывод первой очереди с адресами начала P1 и конца P2
    cout << "Первая очередь:  ";
    queue1.print();  // Вывод элементов
    cout << "  P1 (начало): " << queue1.getHead();  // Адрес начала
    if (queue1.getHead()) cout << " (значение: " << queue1.getHead()->data << ")";
    cout << "\n  P2 (конец):   " << queue1.getTail();  // Адрес конца
    if (queue1.getTail()) cout << " (значение: " << queue1.getTail()->data << ")";

    // Вывод второй очереди с адресами начала P3 и конца P4
    cout << "\nВторая очередь: ";
    queue2.print();
    cout << "  P3 (начало): " << queue2.getHead();  // Адрес начала
    if (queue2.getHead()) cout << " (значение: " << queue2.getHead()->data << ")";
    cout << "\n  P4 (конец):   " << queue2.getTail(); // Адрес конца
    if (queue2.getTail()) cout << " (значение: " << queue2.getTail()->data << ")";
    cout << endl;

    cout << "Перемещаем " << N << " элементов из первой очереди во вторую" << endl;

    // Вызов метода перемещения 
    int moved = queue1.moveNElementsTo(queue2, N);

    // Вывод результата
    cout << "Перемещено: " << moved << " элементов" << endl;
    if (moved < N) {
        cout << "(первая очередь содержала только " << moved << " элементов)" << endl;
    }

    // Вывод состояния первой очереди после перемещения
    cout << "\nПервая очередь" << endl;
    cout << "Состояние: ";
    queue1.print();
    cout << "Новые адреса:" << endl;
    cout << "  P1 (начало): " << queue1.getHead();
    if (queue1.getHead()) cout << " (значение: " << queue1.getHead()->data << ")";
    else cout << " (nullptr - очередь пуста)";
    cout << "\n  P2 (конец):   " << queue1.getTail();
    if (queue1.getTail()) cout << " (значение: " << queue1.getTail()->data << ")";
    else cout << " (nullptr - очередь пуста)";
    cout << endl;

    // Вывод состояния второй очереди после перемещения
    cout << "\nВторая очередь" << endl;
    cout << "Состояние: ";
    queue2.print();
    cout << "Новые адреса:" << endl;
    cout << "  P3 (начало): " << queue2.getHead();
    if (queue2.getHead()) cout << " (значение: " << queue2.getHead()->data << ")";
    cout << "\n  P4 (конец):   " << queue2.getTail();
    if (queue2.getTail()) cout << " (значение: " << queue2.getTail()->data << ")";
    cout << endl;

    // Демострация поиска по значению в 1 и 2 очередях
    cout << "\nВведите число которое нужно найти в обоих очередях: ";
    int n;
    cin >> n;
    // Поиск в первой очереди
    cout << "Поиск в очереди 1" << endl;
    queue1.find(n);  
    cout << endl;
    // Поиск во второй очереди
    cout << "Поиск в очереди 2" << endl;
    queue2.find(n);  
    cout << endl;

    // Демонстрация конструктора копирования
    cout << "Создаем копию второй очереди:" << endl;
    // Вызов конструктора копирования
    Queue queue2Copy = queue2;

    cout << "Оригинальная вторая очередь: ";
    queue2.print();
    cout << "Копия второй очереди: ";
    queue2Copy.print();

    // Демонстрация независимости копии от оригинала
    cout << "\nИзменяем оригинал (удаляем первый элемент)" << endl;
    if (!queue2.isEmpty()) {
        queue2.dequeue();  // Удаляем первый элемент из оригинала
    }

    cout << "Оригинал после изменения: ";
    queue2.print();  // Оригинал изменился
    cout << "Копия (не изменилась): ";
    queue2Copy.print();  // Копия осталась прежней
    cout << endl;

    // После завершения функции автоматически запускается деструктора
}
