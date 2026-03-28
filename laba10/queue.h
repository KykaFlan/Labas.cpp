#pragma once

#include "node.h"
#include <iostream>
#include <fstream>

class Queue {
private:
    Node* head; // Указатель на начало очереди
    Node* tail; // Указатель на конец очереди

public:
    // Конструкторы и деструктор
    Queue(); // Конструктор по умолчанию
    Queue(const Queue& other); // Конструктор копирования
    ~Queue(); // Деструктор


    void enqueue(int val); // Добавление в хвост
    int dequeue(); // Удаление из головы
    int front() const; // Просмотр головы
    int back() const; // Просмотр хвоста
    bool isEmpty() const;
    void find(int val) const; // Поиск элемента

    // Получение головы и хваста очереди
    Node* getHead() const { return head; }
    Node* getTail() const { return tail; }

    void fillFromKeyboard(); // Заполнение с клавиатуру
    void fillFromFile(const std::string& filename); // Заполнение с файла
    void fillRandom(int count); // Заполение случайно
    void print() const; // Вывод очереди

    int moveNElementsTo(Queue& dest, int N); // Перемещение элементов
};
