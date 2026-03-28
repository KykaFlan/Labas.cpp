#include "queue.h"
#include <cstdlib>
#include <iostream>

// Конструктор по умолчанию
Queue::Queue() : head(nullptr), tail(nullptr) {}

// Конструктор копирования
Queue::Queue(const Queue& other) : head(nullptr), tail(nullptr) {
    if (other.head) {
        Node* cur = other.head;
        while (cur) {
            enqueue(cur->data);
            cur = cur->next;
        }
    }
}

// Деструктор
Queue::~Queue() {
    std::cout << "Начинаем очистку очереди\n";

    Node* cur = head;
    int count = 0;

    while (cur) {
        Node* temp = cur;
        cur = cur->next;
        std::cout << "Удаляем узел с адресом " << temp << ", значение " << temp->data << std::endl;
        delete temp;
        count++;
    }

    head = tail = nullptr;
    std::cout << "Очередь очищена. Удалено " << count << " элементов\n";
}

// Добавление в хвост
void Queue::enqueue(int val) {
    Node* newNode = new Node(val);
    if (isEmpty()) {
        head = tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
}

// Удаление из головы
int Queue::dequeue() {
    if (isEmpty()) {
        std::cerr << "Ошибка: очередь пуста!\n";
        return 0;
    }
    Node* temp = head;
    int val = temp->data;
    head = head->next;
    if (head == nullptr) {
        tail = nullptr;
    }
    delete temp;
    return val;
}

// Просмотр головы
int Queue::front() const {
    if (isEmpty()) {
        std::cerr << "Очередь пуста!\n";
        return 0;
    }
    return head->data;
}

// Просмотр хвоста
int Queue::back() const {
    if (isEmpty()) {
        std::cerr << "Очередь пуста!\n";
        return 0;
    }
    return tail->data;
}

// Проверка на пустоту
bool Queue::isEmpty() const {
    return head == nullptr;
}

// Поиск элемента
void Queue::find(int val) const {
    if (isEmpty()) {
        std::cout << "Очередь пуста. Поиск невозможен.\n";
        return;
    }

    Node* current = head;
    int position = 1;

    while (current != nullptr) {
        if (current->data == val) {
            std::cout << "Элемент " << val << " найден в очереди!\n";
            std::cout << "  Позиция: " << position << " (1 - начало очереди)\n";
            std::cout << "  Адрес ячейки: " << current << std::endl;
            std::cout << "  Значение в ячейке: " << current->data << std::endl;
            return;
        }
        current = current->next;
        position++;
    }
    std::cout << "Элемент " << val << " не найден в очереди\n";
}

// Заполнение с клавиатуры
void Queue::fillFromKeyboard() {
    int n;
    std::cout << "Введите количество элементов: ";
    std::cin >> n;
    std::cout << "Введите " << n << " чисел (от начала к концу): ";
    for (int i = 0; i < n; ++i) {
        int val;
        std::cin >> val;
        enqueue(val);
    }
}

// Заполнение из файла
void Queue::fillFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Не удалось открыть файл!\n";
        return;
    }
    int val;
    while (file >> val) {
        enqueue(val);
    }
}

// Заполнение случайно
void Queue::fillRandom(int count) {
    for (int i = 0; i < count; ++i) {
        enqueue(rand() % 100);
    }
}

// Вывод очереди
void Queue::print() const {
    if (isEmpty()) {
        std::cout << "Очередь пуста\n";
        return;
    }
    std::cout << "Очередь: ";
    Node* cur = head;
    while (cur) {
        std::cout << cur->data << " ";
        cur = cur->next;
    }
    std::cout << std::endl;
}

// Перемещение элементов
int Queue::moveNElementsTo(Queue& dest, int N) {
    if (N <= 0 || isEmpty()) {
        return 0;
    }

    int moved = 0;

    while (!isEmpty() && moved < N) {
        Node* node = head;

        head = head->next;
        if (head == nullptr) {
            tail = nullptr;
        }
        node->next = nullptr;

        if (dest.isEmpty()) {
            dest.head = dest.tail = node;
        }
        else {
            dest.tail->next = node;
            dest.tail = node;
        }
        moved++;
    }
    return moved;
}
