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


// Проверка на вещественное число (для double)
bool Validation::isDouble(const std::string& str, bool allowNegative) {
    if (str.empty()) return false;

    size_t start = 0;
    if (allowNegative && str[0] == '-') {
        if (str.size() == 1) return false;
        start = 1;
    }

    bool pointFound = false;
    bool digitFound = false;

    for (size_t i = start; i < str.size(); i++) {
        char c = str[i];

        if (c == '.') {
            if (pointFound) return false;
            pointFound = true;
        }
        else if (isdigit(c)) {
            digitFound = true;
        }
        else {
            return false;
        }
    }

    return digitFound;
}

// Проверка файла с вещественными числами
bool Validation::isFileValidDouble(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cout << "Файл не найден\n";
        return false;
    }

    std::string token;
    bool hasAnyNumber = false;
    int position = 1;

    while (file >> token) {
        hasAnyNumber = true;

        if (!isDouble(token)) {
            std::cout << "Файл содержит не число в позиции " << position << ": '" << token << "'\n";
            return false;
        }

        try {
            std::stod(token);
        }
        catch (...) {
            std::cout << "Число слишком большое в позиции " << position << ": '" << token << "'\n";
            return false;
        }
        position++;
    }

    if (!hasAnyNumber) {
        std::cout << "Файл пуст или не содержит чисел\n";
        return false;
    }

    std::cout << "Файл корректен\n";
    return true;
}

// Ввод имени файла с проверкой для вещественных чисел
std::string Validation::getValidFileDouble() {
    std::string filename;
    while (true) {
        std::cin >> filename;

        std::ifstream file(filename);
        if (!file) {
            std::cout << "Файл не найден\n";
            continue;
        }
        file.close();

        if (isFileValidDouble(filename)) {
            return filename;
        }

    }
}

// Проверка строки с вещественными числами
bool Validation::validateNumberString(const std::string& line, std::vector<double>& numbers) {
    std::stringstream ss(line);
    std::vector<double> temp;
    std::string token;
    int position = 1;

    while (ss >> token) {
        if (!isDouble(token)) {
            std::cout << "Ошибка! '" << token << "' не является числом (позиция " << position << ").\n";
            return false;
        }

        try {
            double val = std::stod(token);
            temp.push_back(val);
        }
        catch (...) {
            std::cout << "Ошибка! Число '" << token << "' слишком большое (позиция " << position << ").\n";
            return false;
        }
        position++;
    }

    if (temp.size() < 2) {
        std::cout << "Ошибка! Введено " << temp.size() << " чисел, а нужно минимум 2.\n";
        return false;
    }

    numbers = temp;
    return true;
}
