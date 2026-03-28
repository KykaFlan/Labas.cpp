#include "Blist.h"
#include <cstdlib>
#include <iostream>

// Конструктор
BarrierList::BarrierList() {
    // Создаем барьерный элемент
    Barrier = new DNode(0); // барьер со значением 0 (можно выставить любое значение)
    Barrier->next = Barrier; // пока список пуст, барьер указывает сам на себя
    Barrier->prev = Barrier;
    Current = Barrier; // текущим становится барьер
}

// Конструктор копирования
BarrierList::BarrierList(const BarrierList& other) {
    // Создаем барьер
    Barrier = new DNode(0);
    Barrier->next = Barrier;
    Barrier->prev = Barrier;
    Current = Barrier;

    // Копируем реальные элементы
    if (other.Barrier->next != other.Barrier) {
        DNode* cur = other.Barrier->next;
        while (cur != other.Barrier) {
            append(cur->data);  // добавляем элементы
            cur = cur->next;
        }
    }
    std::cout << "Конструктор копирования BarrierList создал копию\n";
}

// Деструктор
BarrierList::~BarrierList() {
    std::cout << "Начинаем очистку списка с барьером\n";

    // Удаляем все реальные элементы
    DNode* cur = Barrier->next;
    int count = 0;

    while (cur != Barrier) {
        DNode* temp = cur;
        cur = cur->next;
        std::cout << "Удаляем узел с адресом " << temp << ", значение " << temp->data << std::endl;
        delete temp;
        count++;
    }

    // Удаляем барьер
    std::cout << "Удаляем барьер с адресом " << Barrier << std::endl;
    delete Barrier;

    Barrier = nullptr;
    Current = nullptr;
    std::cout << "Список очищен. Удалено " << count << " реальных элементов + барьер\n";
}

// Добавление в конец
void BarrierList::append(int val) {
    DNode* newNode = new DNode(val);

    if (Barrier->next == Barrier) {  // список пуст
        Barrier->next = newNode;
        Barrier->prev = newNode;
        newNode->next = Barrier;
        newNode->prev = Barrier;
    }
    else {
        DNode* last = Barrier->prev;
        last->next = newNode;
        newNode->prev = last;
        newNode->next = Barrier;
        Barrier->prev = newNode;
    }
}

// Проверка на пустоту
bool BarrierList::isEmpty() const {
    return Barrier->next == Barrier;  // нет элементов (не считая барьера)
}

// Получить количество реальных элементов
int BarrierList::getSize() const {
    int count = 0;
    DNode* cur = Barrier->next;
    while (cur != Barrier) {
        count++;
        cur = cur->next;
    }
    return count;
}

// Вывод
void BarrierList::print() const {
    if (isEmpty()) {
        std::cout << "Список пуст\n";
        return;
    }

    DNode* cur = Barrier->next;
    while (cur != Barrier) {
        std::cout << cur->data << " ";
        cur = cur->next;
    }
    std::cout << std::endl;
}

// Поиск
void BarrierList::find(int val) const {
    if (isEmpty()) {
        std::cout << "Список пуст. Поиск невозможен.\n";
        return;
    }

    DNode* cur = Barrier->next;
    int position = 1;

    while (cur != Barrier) {
        if (cur->data == val) {
            std::cout << "Элемент " << val << " найден в списке!\n";
            std::cout << "Позиция: " << position << "\n";
            std::cout << "Адрес: " << cur << std::endl;
            std::cout << "Значение: " << cur->data << std::endl;
            return;
        }
        cur = cur->next;
        position++;
    }

    std::cout << "Элемент " << val << " не найден в списке\n";
}

// Сделать текущим первый реальный элемент
void BarrierList::LBTofirst() {
    Current = Barrier->next;  // первый реальный элемент после барьера
}

// Перейти к следующему
void BarrierList::LBTNext() {
    if (Current->next != Barrier) {
        Current = Current->next;
    }
}

// Установить значение текущему
void BarrierList::LBSetData(int val) {
    if (Current != Barrier) {  // проверка, что это не барьер
        Current->data = val;
    }
}

// Проверка является ли текущий барьером
bool BarrierList::IsBarrier() {
    return Current == Barrier;
}

// Случайное заполнение
void BarrierList::fillRandom(int count) {
    for (int i = 0; i < count; ++i) {
        append(rand() % 100);
    }
    std::cout << "Сгенерировано " << count << " случайных чисел\n";
}