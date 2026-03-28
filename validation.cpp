#include <iostream>
#include "validation.h"
#include <string>
#include <fstream>
#include <vector>
#include <cctype>

// Очистка буфера ввода
void Validation::clearInput() {
    std::cin.clear();
    std::cin.ignore(1000, '\n');
}

// Проверка, что строка содержит только цифры (и возможно минус)
bool Validation::isNumber(const std::string& str, bool allowNegative) {
    if (str.empty()) return false;
        
    size_t start = 0;
    if (allowNegative && str[0] == '-') {
        if (str.size() == 1) return false;
        start = 1;
    }

    for (size_t i = start; i < str.size(); i++) {
        if (!std::isdigit(str[i])) return false;
    }
    return true;
}

// Ввод целого числа (только цифры)
int Validation::getInt() {
    std::string input;
    int value;

    while (true) {
        std::cin >> input;

        if (!isNumber(input)) {
            std::cout << "Ошибка! Введите целое число (только цифры).\n";
            clearInput();
            continue;
        }

        try {
            value = std::stoi(input);
            return value;
        }
        catch (...) {
            std::cout << "Ошибка! Число слишком большое или маленькое.\n";
            clearInput();
        }
    }
}

// Ввод целого числа с минимальным значением
int Validation::getIntMin(int minValue) {
    while (true) {
        int value = getInt();
        if (value >= minValue) {
            return value;
        }
        std::cout << "Ошибка! Число должно быть >= " << minValue << ".\n";
    }
}

// Ввод целого числа в диапазоне
int Validation::getIntRange(int minValue, int maxValue) {
    while (true) {
        int value = getInt();
        if (value >= minValue && value <= maxValue) {
            return value;
        }
        std::cout << "Ошибка! Число должно быть от " << minValue << " до " << maxValue << ".\n";
    }
}


// Проверка, что файл содержит только числа
bool Validation::isFileValid(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cout << "Файл не найден\n";
        return false;
    }

    std::string token;
    bool hasAnyNumber = false;  // флаг, что нашли хоть одно число

    while (file >> token) {
        hasAnyNumber = true;
        if (!isNumber(token)) {
            std::cout << "Файл содержит не число: '" << token << "'\n";
            return false;
        }

        try {
            std::stoi(token);            
        }
        catch (...) {
            std::cout << "Число слишком большое: '" << token << "'\n";
            return false;
        }
    }

    // Проверяем, нашли ли хоть одно число
    if (!hasAnyNumber) {
        std::cout << "Файл пуст или не содержит чисел\n";
        return false;
    }

    std::cout << "Файл корректен\n";
    return true;
}

// Ввод имени файла с проверкой содержимого
std::string Validation::getValidFile() {
    std::string filename;
    while (true) {
        std::cin >> filename;

        // Проверяем, что файл существует
        std::ifstream file(filename);
        if (!file) {
            std::cout << "Файл не найден\n";
            continue;
        }
        file.close();

        // Проверяем содержимое
        if (isFileValid(filename)) {
            return filename;
        }
        // если файл некорректен — пробуем снова
    }
}



