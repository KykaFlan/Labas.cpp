#include "TList.h"
#include <cstdlib>
#include <iostream>

// Конструктор
TList::TList() : First(nullptr), Last(nullptr), Current(nullptr) {}

// Конструктор копирования
TList::TList(const TList& other) : First(nullptr), Last(nullptr), Current(nullptr) {
    if (other.First) {
        DNode* cur = other.First;
        while (cur) {
            append(cur->data);
            cur = cur->next;
        }
    }
    std::cout << "Конструктор копирования TList создал копию\n";
}

// Деструктор
TList::~TList() {
    std::cout << "Начинаем очистку списка\n";
    DNode* cur = First;
    int count = 0;

    while (cur) {
        DNode* temp = cur;
        cur = cur->next;
        std::cout << "Удаляем узел с адресом " << temp << ", значение " << temp->data << std::endl;
        delete temp;
        count++;
    }

    First = Last = Current = nullptr;
    std::cout << "Список очищен. Удалено " << count << " элементов\n";
}

// Добавление в конец
void TList::append(int val) {
    DNode* newNode = new DNode(val);

    if (isEmpty()) {
        First = Last = newNode;
    }
    else {
        Last->next = newNode;
        newNode->prev = Last;
        Last = newNode;
    }
}

// Проверка на пустоту
bool TList::isEmpty() const {
    return First == nullptr;
}

// Вывод
void TList::print() const {
    if (isEmpty()) {
        std::cout << "Список пуст\n";
        return;
    }

    DNode* cur = First;
    while (cur) {
        std::cout << cur->data << " ";
        cur = cur->next;
    }
    std::cout << std::endl;
}

// Поиск
void TList::find(int val) const {
    if (isEmpty()) {
        std::cout << "Список пуст. Поиск невозможен.\n";
        return;
    }

    DNode* cur = First;
    int position = 1;

    while (cur) {
        if (cur->data == val) {
            std::cout << "Элемент " << val << " найден в списке!\n";
            std::cout << "Позиция: " << position << "\n";
            std::cout << "Адрес: " << cur << "\n";
            std::cout << "Значение: " << cur->data << "\n";
            return;
        }
        cur = cur->next;
        position++;
    }

    std::cout << "Элемент " << val << " не найден в списке\n";
}

// Сделать текущим первый
void TList::ToFirst() {
    Current = First;
}

// Перейти к следующему
void TList::ToNext() {
    if (Current && Current->next) {
        Current = Current->next;
    }
}

// Установить значение текущему
void TList::SetData(int val) {
    if (Current) {
        Current->data = val;
    }
}

// Проверка последний ли текущий  
bool TList::IsLast() const {
    return Current == Last;
}


// Случайное заполнение
void TList::fillRandom(int count) {
    for (int i = 0; i < count; ++i) {
        append(rand() % 100);
    }
}