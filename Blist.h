#pragma once

#include "nodes.h"
#include <iostream>

class BarrierList {
private:
    DNode* Barrier; // Барьерный элемент
    DNode* Current; // Текущий элемент

public:
    BarrierList(); // Конструктор
    BarrierList(const BarrierList& other); // Конструктор копирования
    ~BarrierList(); // Деструктор

    // Основные операции
    void append(int val); // Добавление в конец
    bool isEmpty() const; // Проверка на пустоту
    int getSize() const;  // Получить количество реальных элементов
    void print() const; // Вывод (выводит все элементы кроме барьера)
    void find(int val) const; // Поиск среди всех элементов кроме барьера

   
    DNode* getBarrier() const { return Barrier; } // Получение указателя на барьер
    DNode* getCurrent() const { return Current; } // Получение указателя на текущий элемент

    // Процедуры
    void LBTofirst(); // Сделать текущим первый реальный элемент
    void LBTNext(); // Перейти к следующему
    void LBSetData(int val); // Установить значение текущему
    bool IsBarrier(); // Проверка является ли текущий барьером
    void CurrentToBarrier() { Current = Barrier; } // Ставит текущий в барьер

    void fillRandom(int count); // Случайное заполнение
};