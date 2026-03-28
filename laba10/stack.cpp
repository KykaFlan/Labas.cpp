#include "stack.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

// Конструктор по умолчанию - создаем пустой стек
Stack::Stack() : top(nullptr) {}

// Конструктор копированя
Stack::Stack(const Stack& other) : top(nullptr) {
    if (other.top) {
        Stack temp;
        Node* cur = other.top;
        while (cur) {
            temp.push(cur->data);
            cur = cur->next;
        }
        while (!temp.isEmpty()) {
            push(temp.pop());
        }
    }
}
// Деструктор
Stack::~Stack() {
    std::cout << "Начинаем очистку стека\n";
    int count = 0;
    while (!isEmpty()) {
        Node* temp = top;
        top = top->next;
        std::cout << "Удаляем узел с адресом " << temp << ", значение " << temp->data << std::endl;
        delete temp;
        count++;
    }
    std::cout << "Стек очищен. Удалено " << count << " элементов." << std::endl;
}

// Добавление на вершину
void Stack::push(int val) {
    Node* newNode = new Node(val);
    newNode->next = top;
    top = newNode;
}

// Извлечение с вершины
int Stack::pop() {
    if (isEmpty()) {
        std::cerr << "Ошибка: стек пуст!\n";
        return 0;
    }
    Node* temp = top;
    int val = temp->data;
    top = top->next;
    delete temp;
    return val;
}

// Просмотр вершины без удаления
int Stack::peek() const {
    if (isEmpty()) {
        std::cerr << "Стек пуст!\n";
        return 0;
    }
    return top->data;
}

// Проверка на пустоту стека
bool Stack::isEmpty() const {
    return top == nullptr;
}
// Поиск элемента
void Stack::find(int val) const {
    if (isEmpty()) {
        std::cout << "Стек пуст. Поиск невозможен.\n";
        return;
    }

    Node* current = top;
    int position = 1;

    while (current != nullptr) {
        if (current->data == val) {
            std::cout << "Элемент " << val << " найден в стеке!\n";
            std::cout << "  Позиция: " << position << std::endl;
            std::cout << "  Адрес ячейки: " << current << std::endl;
            std::cout << "  Значение в ячейке: " << current->data << std::endl;
            return;
        }
        current = current->next;
        position++;
    }
    std::cout << "Элемент " << val << " не найден в стеке\n";
}
// Заполнение с клавиатуру
void Stack::fillFromKeyboard() {
    int n;
    std::cout << "Введите количество элементов: ";
    std::cin >> n;
    std::cout << "Введите " << n << " чисел (последнее будет вершиной): ";
    for (int i = 0; i < n; ++i) {
        int val;
        std::cin >> val;
        push(val);
    }
}
// Заполнение с файла
void Stack::fillFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Не удалось открыть файл!" << std::endl;
        return;
    }
    int val;
    while (file >> val) {
        push(val);
    }
    std::cout << "Загружено " << (!isEmpty() ? "несколько" : "0") << " элементов\n";
}
// Заполение случайно
void Stack::fillRandom(int count) {
    for (int i = 0; i < count; ++i) {
        push(rand() % 100);
    }
}
// Вывод стека
void Stack::print() const {
    if (isEmpty()) {
        std::cout << "Стек пуст\n";
        return;
    }
    std::cout << "Стек (вершина слева): ";
    Node* cur = top;
    while (cur) {
        std::cout << cur->data << " ";
        cur = cur->next;
    }
    std::cout << std::endl;
}
