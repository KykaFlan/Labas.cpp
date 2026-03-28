#include "CircularDlist.h"
#include <cstdlib>
#include <iostream>

// Конструктор
CircularDoubleList::CircularDoubleList() : head(nullptr), tail(nullptr) {}

// Конструктор копирования
CircularDoubleList::CircularDoubleList(const CircularDoubleList& other) : head(nullptr), tail(nullptr) {
    if (other.head) {
        DNode* cur = other.head;
        do {
            append(cur->data);
            cur = cur->next;
        } while (cur != other.head);
    }
}

// Деструктор
CircularDoubleList::~CircularDoubleList() {
    std::cout << "Начинаем очистку циклического двусвязного списка\n";

    if (isEmpty()) {
        std::cout << "Список пуст\n";
        return;
    }

    // Разрываем цикл для удаления
    tail->next = nullptr;
    head->prev = nullptr;

    DNode* cur = head;
    int count = 0;

    while (cur) {
        DNode* temp = cur;
        cur = cur->next;
        std::cout << "Удаляем узел с адресом " << temp << ", значение " << temp->data << std::endl;
        delete temp;
        count++;
    }

    head = tail = nullptr;
    std::cout << "Циклический двусвязный список очищен. Удалено " << count << " элементов\n\n";
}

// Добавление в конец циклического двусвязного списка
void CircularDoubleList::append(int val) {
    DNode* newNode = new DNode(val);

    if (isEmpty()) {
        head = tail = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
    }
    else {
        newNode->prev = tail;
        newNode->next = head;
        tail->next = newNode;
        head->prev = newNode;
        tail = newNode;
    }
}

// Проверка на пустоту
bool CircularDoubleList::isEmpty() const {
    return head == nullptr;
}

// Заполнение случайными числами
void CircularDoubleList::fillRandom(int count) {
    for (int i = 0; i < count; i++) {
        append(rand() % 100);
    }
}

// Вывод списка
void CircularDoubleList::print() const {
    if (isEmpty()) {
        std::cout << "Список пуст\n";
        return;
    }

    DNode* cur = head;
    do {
        std::cout << cur->data << " ";
        cur = cur->next;
    } while (cur != head);
}

// Поиск элемента по значению
void CircularDoubleList::find(int val) const {
    if (isEmpty()) {
        std::cout << "Список пуст. Поиск невозможен.\n";
        return;
    }

    DNode* cur = head;
    int position = 1;

    do {
        if (cur->data == val) {
            std::cout << "Элемент " << val << " найден!\n";
            std::cout << "Позиция: " << position << "\n";
            std::cout << "Адрес: " << cur << "\n";
            std::cout << "Значение: " << cur->data << "\n";
            return;
        }
        cur = cur->next;
        position++;
    } while (cur != head);

    std::cout << "Элемент " << val << " не найден\n";
}

// Метод для ListWork42
DNode* CircularDoubleList::removeIfNeighborsEqual() {
    if (isEmpty()) {
        std::cout << "Список пуст, нечего удалять\n";
        return nullptr;
    }

    if (head == tail) {
        std::cout << "В списке только один элемент, удаление невозможно\n";
        return tail;
    }

    std::cout << "\nНачинаем поиск элементов с равными соседями\n";

    bool changed;
    int passCount = 0;

    do {
        changed = false; // Если за проход было удаление то цикл идёт пока не будет ситуаций для удаления либо список  не будет пустым
        passCount++;
        std::cout << "\n=^.^= =^.^= Цикл " << passCount << " =^.^= =^.^=\n";

        DNode* current = head;
        int stepInPass = 0;

        do {
            stepInPass++;
            std::cout << "Шаг " << stepInPass << ": элемент " << current->data << " (соседи: " << current->prev->data << " и " << current->next->data << ")\n";

            if (current->prev->data == current->next->data) {
                std::cout << "Равны. Удаляем " << current->data << "\n";

                DNode* toDelete = current;
                DNode* nextCurrent = current->next;

                if (toDelete == head) {
                    head = nextCurrent;
                    std::cout << "(Новая голова: " << head->data << ")\n";
                }

                if (toDelete == tail) {
                    tail = current->prev;
                    std::cout << "(Новый хвост: " << tail->data << ")\n";
                }

                current->prev->next = current->next;
                current->next->prev = current->prev;

                delete toDelete;
                changed = true;

                std::cout << "Текущий список: ";
                print();
                std::cout << "\n";

                current = nextCurrent;
            }
            else {
                current = current->next;
            }        
        
        } while (current != head && !isEmpty());
        if (head == tail) {
            std::cout << "В списке только один элемент, удаление невозможно\n";
            return tail;
        }
    } while (changed && !isEmpty());

    if (passCount == 1 && !changed) {
        std::cout << "\nЭлементов с равными соседями не найдено\n";
    }
    else {
        std::cout << "\nУдаление завершено\n";
    }

    return tail;
}
