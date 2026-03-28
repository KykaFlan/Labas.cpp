#pragma once

#include "nodes.h"
#include <iostream>

class TList {
private:
    DNode* First; // Первый элемент
    DNode* Last; // Последний элемент
    DNode* Current; // Текущий элемент

public:
    TList(); // Конструктор
    TList(const TList& other); // Конструктор копирования
    ~TList(); // Деструктор

    // Основные операции
    void append(int val); // Добавление в конец
    bool isEmpty() const; // Проверка на пустоту
    void print() const; // Вывод
    void find(int val) const; // Поиск

    // Получать указатели
    DNode* getFirst() const { return First; }
    DNode* getLast() const { return Last; }
    DNode* getCurrent() const { return Current; }

    // Процедуры
    void ToFirst(); // Сделать текущим первый
    void ToNext(); // Перейти к следующему
    void SetData(int val); // Установить значение текущему
    bool IsLast() const; // Проверка последний ли текущий   

    void fillRandom(int count); // Случайное заполнение
};