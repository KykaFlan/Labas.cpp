#pragma once

#include "node.h"
#include <iostream>
#include <fstream>

class LinkedList {
private:
    Node* head;  // Указатель на голову списка

public:
    // Конструкторы и деструктор
    LinkedList(); // Конструктор по умолчанию
    LinkedList(const LinkedList& other); // Конструктор копирования
    ~LinkedList(); // Деструктор

    // Методы для задач
    Node* getNthNode(int n) const; // Метод для ListWork3 (получение указателя на n-й элемент)
    void insertAfterEveryK(int k, int val); // Метод для ListWork24 (вставка значения val после каждого k-го элемента)
    Node* getLastNode() const; // Метод для ListWork24 (получение указателя на последний элемент)
    void insertSorted(int val); // Метод для ListWork61 (вставка элемента с сохранением упорядоченности)
    

    // Вспомогательные методы
    void append(int val);  // Добавление элемента в конец списка
    bool isEmpty() const; // Проверка списка на пустоту
    void find(int val) const; // Поиск элемента по значению
    Node* getHead() const { return head; } // Получение указателя на голову списка
    void fillFromKeyboard(); // Заполнение с клавиатуры
    void fillFromFile(const std::string& filename); // Заполнение c файла
    void fillRandom(int count); // Заполнение случайно
    void print() const; // Вывод списка
};