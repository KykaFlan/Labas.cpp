#include "list.h"
#include <cstdlib>
#include <iostream>
#include <vector>



// Конструктор по умолчанию
CircularList::CircularList() : head(nullptr) {}

// Конструктор копирования
CircularList::CircularList(const CircularList& other) : head(nullptr) {
    if (other.head) {
        Node* cur = other.head;
        do {
            append(cur->data);
            cur = cur->next;
        } while (cur != other.head);
    }
}

// Деструктор
CircularList::~CircularList() {
    std::cout << "Начинаем очистку циклического списка\n";

    if (isEmpty()) {
        std::cout << "Список пуст\n";
        return;
    }

    // Разрываем цикл, чтобы избежать бесконечного цикла удаления
    Node* last = head;
    while (last->next != head) {
        last = last->next;
    }
    last->next = nullptr;  // разрываем цикл

    // Удаляем как обычный список с выводом каждого удаляемого узла
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
    std::cout << "Циклический список очищен. Удалено " << count << " элементов\n\n";
}


// Добавление в конец циклического списка
void CircularList::append(int val) {
    Node* newNode = new Node(val);

    if (isEmpty()) {
        head = newNode;
        newNode->next = head;  // указывает сам на себя (цикл)
    }
    else {
        // Находим последний элемент
        Node* last = head;
        while (last->next != head) {
            last = last->next;
        }
        // Вставляем новый узел
        last->next = newNode;
        newNode->next = head;  // замыкаем цикл
    }
}

// Проверка на пустоту
bool CircularList::isEmpty() const {
    return head == nullptr;
}

// Поиск элемента по значению (для циклического списка)
void CircularList::find(int val) const {
    if (isEmpty()) {
        std::cout << "Список пуст. Поиск невозможен." << std::endl;
        return;
    }

    Node* current = head;
    int position = 1;

    // Проходим ровно один круг
    do {
        if (current->data == val) {
            std::cout << "Элемент " << val << " найден в списке!" << std::endl;
            std::cout << "Позиция: " << position << std::endl;
            std::cout << "Адрес ячейки: " << current << std::endl;
            std::cout << "Значение: " << current->data << std::endl;
            return;
        }
        current = current->next;
        position++;
    } while (current != head);  // Останавливаемся, когда вернулись к началу

    std::cout << "Элемент " << val << " не найден в списке" << std::endl;
}


// Заполнение случайными числами
void CircularList::fillRandom(int count) {
    for (int i = 0; i < count; i++) {
        append(rand() % 100);  // числа от 0 до 99
    }
}

// Вывод списка
void CircularList::print() const {
    if (isEmpty()) {
        std::cout << "Список пуст\n";
        return;
    }

    Node* cur = head;
    do {
        std::cout << cur->data << " ";
        cur = cur->next;
    } while (cur != head);
    std::cout << std::endl;
}

// Метод для решения задачи ListWork68
void CircularList::processWithStepToFile(int step, const std::string& filename) {
    std::ofstream out(filename);
    if (!out) {
        std::cerr << "Не удалось открыть файл для записи!\n";
        return;
    }

    if (isEmpty()) {
        out << "Список пуст\n";
        out.close();
        return;
    }

    // Записываем исходный список в файл
    out << "Результат обработки циклического списка с шагом " << step << "\n\n";
    out << "Исходный список: ";
    Node* temp = head;
    do {
        out << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    out << "\n";
    out << "Последовательность удаления: ";

    std::cout << "\nИсходный список: ";
    print();

    int stepCount = 1; // Номер текущего шага
    Node* current = head; // Указатель на текущий элемент
    std::vector<int> results; // Вектор для сохранения ответа

    while (!isEmpty()) {
        std::cout << "\n=^.^= =^.^=  Шаг " << stepCount << "  =^.^= =^.^=\n";

        // Находим элемент для удаления
        if (stepCount == 1) {
            current = head;
            std::cout << "Начинаем с первого элемента: " << current->data << "\n";
        }
        else {
            std::cout << "Смещаемся на " << step << " позиций от текущего (" << current->data << "):\nПуть: ";
            for (int i = 1; i < step; i++) {
                current = current->next;
                std::cout << current->data << " ";
            }
            std::cout << "\n";
        }

        int value = current->data;
        results.push_back(value);

        std::cout << "Будет удален элемент: " << value << "\n";
        std::cout << "Состояние до удаления: ";
        print();

        // Удаление элемента
        if (head->next == head) {
            // Единственный элемент
            std::cout << "Это последний элемент!\n";
            delete head;
            head = nullptr;
            std::cout << "Состояние после удаления: список пуст\n";
            break;
        }

        // Находим предыдущий элемент
        Node* prevNode = head;
        while (prevNode->next != current) {
            prevNode = prevNode->next;
        }
        
        if (current == head) {
            head = head->next;
            std::cout << "(Удаляется голова списка)\n";
        }

        Node* nextCurrent = current->next;
        prevNode->next = current->next;
        delete current;

        std::cout << "Элемент " << value << " удален\n";
        std::cout << "Состояние после удаления: ";
        print();

        if (head == nullptr) {
            std::cout << "Список стал пустым\n";
            break;
        }

        current = nextCurrent;
        std::cout << "Новый текущий элемент: " << current->data << "\n";

        stepCount++;
    }

    // Записываем результаты в файл
    for (size_t i = 0; i < results.size(); i++) {
        out << results[i];
        if (i < results.size() - 1) out << " ";
    }
    out << "\n\nВсего удалено элементов: " << results.size() << "\n";
    out.close();

    // Финальный результат
    std::cout << "\n=^.^=   =^.^=   =^.^=   =^.^=   =^.^=   =^.^=   =^.^=\n";
    std::cout << "Результат: ";
    for (int i = 0;  i < results.size(); i++) {
        std::cout << results[i] << " ";
    }
    std::cout << "\nРезультат записан в файл: " << filename << "\n\n";
}

// Метод для Задачи 5
void CircularList::findLongestNegativeSequence() const {
    if (isEmpty()) {
        std::cout << "Список пуст\n";
        return;
    }

    std::cout << "Поиск последовательности отрицательных элементов\n";

    Node* current = head;
    int maxLength = 0; // Длина самой длинной найденной последовательности
    int currentLength = 0; // Сколько отрицательных чисел идет подряд в текущей проверке
    Node* startOfMax = nullptr; // Указатель на первый узел самой длинной найденной цепочки
    Node* temp = head; // Вспомогательный указатель для предварительного прохода по списку
    int totalElements = 0; // Общее количество узлов в списке

    // Подсчет количества элементов
    do {
        totalElements++;
        temp = temp->next;
    } while (temp != head);

    // Поиск максимальной последовательности
    for (int startPos = 0; startPos < totalElements; startPos++) {
        Node* start = head;
        // До ходим до нужной позиции от головы
        for (int i = 0; i < startPos; i++) {
            start = start->next;
        }

        currentLength = 0;
        Node* scan = start;

        for (int i = 0; i < totalElements; i++) {
            if (scan->data < 0) {
                currentLength++;
                scan = scan->next;
            }
            else {
                break;
            }
        }

        if (currentLength > maxLength) {
            maxLength = currentLength;
            startOfMax = start;
        }
    }

    // Вывод результата
    if (maxLength == 0) {
        std::cout << "В списке нет отрицательных элементов\n";
        return;
    }

    std::cout << "Найдена последовательность длины " << maxLength << ":\n   ";
    Node* print = startOfMax;
    for (int i = 0; i < maxLength; i++) {
        std::cout << print->data << " ";
        print = print->next;
    }
    std::cout << "\n";
}