#pragma once

#include "node.h"
#include <iostream>
#include <fstream>

class Stack {
private:
    Node* top; // Указатель на вершину стека

public:
    Stack(); // Конструктор по умолчанию
    Stack(const Stack& other); // Конструктор копирования
    ~Stack();// Деструктор
    
    void push(int val); // Добавление на вершину
    int pop(); // Извлечение с вершины
    int peek() const; // Просмотр вершины без удаления
    void find(int val) const; // Поиск элемента

    bool isEmpty() const; // Проверка на пустоту
    Node* getTop() const { return top; } // Получение головы

    void fillFromKeyboard(); // Заполнение с клавиатуру
    void fillFromFile(const std::string& filename); // Заполнение с файла
    void fillRandom(int count); // Заполение случайно
    void print() const; // Вывод стека
};
