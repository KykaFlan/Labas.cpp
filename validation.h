#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

namespace Validation {

    // Очистка буфера ввода
    void clearInput();

    // Проверка, что строка содержит только цифры (и возможно минус)
    bool isNumber(const std::string& str, bool allowNegative = true);

    // Ввод целого числа (только цифры)
    int getInt();

    // Ввод целого числа с минимальным значением
    int getIntMin(int minValue);

    // Ввод целого числа в диапазоне
    int getIntRange(int minValue, int maxValue);    

    // Проверка, что файл содержит только числа
    bool isFileValid(const std::string& filename);
    
    // Ввод имени файла с проверкой содержимого (только числа)
    std::string getValidFile();
}