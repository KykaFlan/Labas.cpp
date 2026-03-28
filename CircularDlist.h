#pragma once

#include <iostream>
#include "nodes.h"


class CircularDoubleList {
private:
    DNode* head; // указатель на первый элемент
    DNode* tail; // указатель на последний элемент

public:
    CircularDoubleList(); // Конструктор
    CircularDoubleList(const CircularDoubleList& other); // Конструктор копирования
    ~CircularDoubleList(); // Деструктор

    // Основные операции
    void append(int val); // Добавление в конец
    bool isEmpty() const; // Проверка на пустоту
    DNode* getHead() const { return head; } // Получение указателя на голову
    DNode* getTail() const { return tail; } // Получение указателя на хвост

    // Заполнение с клавиатуры и с файла осуществлены при валидации
    void fillRandom(int count);

    // Вывод
    void print() const;

    // Поиск элемента по значению
    void find(int val) const;

    // Метод для ListWork42
    DNode* removeIfNeighborsEqual();
};