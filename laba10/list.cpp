#include "list.h"
#include <cstdlib>
#include <iostream>



// Конструктор по умолчанию
LinkedList::LinkedList() : head(nullptr) {}

// Конструктор копирования
LinkedList::LinkedList(const LinkedList& other) : head(nullptr) {
    if (other.head) {
        Node* cur = other.head;
        Node* last = nullptr;
        while (cur) {
            Node* newNode = new Node(cur->data);
            if (!head) {
                head = newNode;
                last = newNode;
            }
            else {
                last->next = newNode;
                last = newNode;
            }
            cur = cur->next;
        }
    }
}

// Деструктор
LinkedList::~LinkedList() {
    std::cout << "Начинаем очистку списка\n";

    Node* cur = head;
    int count = 0;

    while (cur) {
        Node* temp = cur;
        cur = cur->next;
        std::cout << "Удаляем узел с адресом " << temp << ", значение " << temp->data << std::endl;
        delete temp;
        count++;
    }

    head = nullptr;
    std::cout << "Список очищен. Удалено " << count << " элементов\n";
}

// Добавление элемента в конец списка
void LinkedList::append(int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
    }
    else {
        Node* cur = head;
        while (cur->next) {
            cur = cur->next;
        }
        cur->next = newNode;
    }
}

// Метод для ListWork3 (получение указателя на n-й элемент)
Node* LinkedList::getNthNode(int n) const {
    if (n <= 0 || isEmpty()) return nullptr;

    Node* cur = head;
    int count = 1;

    while (cur && count < n) {
        cur = cur->next;
        count++;
    }

    return cur;
}

// Метод для ListWork24 (вставка значения val после каждого k-го элемента)
void LinkedList::insertAfterEveryK(int k, int val) {
    if (k <= 0 || isEmpty()) return;

    Node* current = head;
    Node* prev = nullptr;
    int original_pos = 1;  // Считаем позиции исходных элементов

    while (current) {
        // Сохраняем указатель на следующий исходный элемент
        Node* nextOriginal = current->next;

        // Проверяем, нужно ли вставлять после текущего элемента
        if (original_pos % k == 0) {
            // Создаем новый узел
            Node* newNode = new Node(val);

            // Вставляем после current
            newNode->next = current->next;
            current->next = newNode;

            // Для отладки
            std::cout << " Вставили " << val << " после элемента " << original_pos << " (значение " << current->data << ")" << std::endl;
        }

        // Переходим к следующему исходному элементу
        // (пропускаем только что вставленный, если он есть)
        current = nextOriginal;
        original_pos++;
    }
}

// Метод для ListWork24 (получение указателя на последний элемент)
Node* LinkedList::getLastNode() const {
    if (isEmpty()) return nullptr;

    Node* cur = head;
    while (cur->next) {
        cur = cur->next;
    }
    return cur;
}

// Метод для ListWork61 (вставка элемента с сохранением упорядоченности)
void LinkedList::insertSorted(int val) {
    Node* newNode = new Node(val);
    // Вставка в начало или пустой список
    if (!head || head->data >= val) {
        newNode->next = head;
        head = newNode;
        return;
    }
    // Поиск места вставки
    Node* cur = head;
    while (cur->next && cur->next->data < val) {
        cur = cur->next;
    }
    // Вставка после cur
    newNode->next = cur->next;
    cur->next = newNode;
}

// Проверка списка на пустоту
bool LinkedList::isEmpty() const {
    return head == nullptr;
}

// Поиск элемента по значению
void LinkedList::find(int val) const {
    if (isEmpty()) {
        std::cout << "Список пуст. Поиск невозможен." << std::endl;
        return;
    }

    Node* current = head;
    int position = 1;  // 1 - начало списка (голова)

    while (current != nullptr) {
        if (current->data == val) {
            std::cout << "Элемент " << val << " найден в списке!" << std::endl;
            std::cout << "  Позиция: " << position << " (1 - начало списка)" << std::endl;
            std::cout << "  Адрес ячейки: " << current << std::endl;
            std::cout << "  Значение в ячейке: " << current->data << std::endl;         
            return;
        }
        current = current->next;
        position++;
    }

    std::cout << "Элемент " << val << " не найден в списке" << std::endl;
}

// Заполнение с клавиатуры
void LinkedList::fillFromKeyboard() {
    int n;
    std::cout << "Введите количество элементов: ";
    std::cin >> n;
    std::cout << "Введите " << n << " чисел: ";
    for (int i = 0; i < n; ++i) {
        int val;
        std::cin >> val;
        append(val);
    }
}

// Заполнение из файла
void LinkedList::fillFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Не удалось открыть файл!\n";
        return;
    }
    int val;
    while (file >> val) {
        append(val);
    }
}

// Заполнение случайно
void LinkedList::fillRandom(int count) {
    for (int i = 0; i < count; ++i) {
        append(rand() % 100);
    }
}

// Вывод списка
void LinkedList::print() const {
    if (isEmpty()) {
        std::cout << "Список пуст\n";
        return;
    }

    Node* cur = head;
    int pos = 1;
    while (cur) {
        std::cout << cur->data;
        if (cur->next) std::cout << " -> ";
        cur = cur->next;
        pos++;
    }
    std::cout << std::endl;
}