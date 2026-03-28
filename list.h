#pragma once

#include "nodes.h"
#include <iostream>
#include <fstream>

class CircularList {
private:
    Node* head;  // указатель на первый элемент

public:
    CircularList();// Конструктор
    CircularList(const CircularList& other); // Конструктор копирования
    ~CircularList(); // Деструктор

    // Основные операции
    void append(int val); // Добавление в конец
    bool isEmpty() const; // Проверка на пустоту
    Node* getHead() const { return head; }  // Получение указателя головы
    void find(int val) const; // Поиск элемента по значению

    // Заполнение с клавиатуры и с файла осуществлены при валидации
    void fillRandom(int count);

    // Вывод
    void print() const;

    // Метод для ListWork68
    void processWithStepToFile(int step, const std::string& filename);

    // Метод для Задачи 5
    void findLongestNegativeSequence() const;

};
