#include <iostream>
#include <string>
#include "Recur17.h"

int Expressions(const std::string& s, int& position) {
    using namespace std;
    // Цифра
    if (s[position] >= '0' && s[position] <= '9') {
        int Number = s[position] - '0';
        position++;
        return Number;
    }
    // Выражение
    if (s[position] == '(') {
        position++;
        // Вычисляем левое выражение
        int LeftNumber = Expressions(s, position);
        // Получаем знак операции
        char Sign = s[position];
        position++;
        // Вычисляем правое выражение
        int RightNumber = Expressions(s, position);

        // Ожидаем закрывающую скобку
        if (s[position] == ')') {
            position++;
        }

        if (Sign == '+') return LeftNumber + RightNumber;
        if (Sign == '-') return LeftNumber - RightNumber;
        if (Sign == '*') return LeftNumber * RightNumber;
    }
}
void Recur17(){
	using namespace std;
    setlocale(LC_ALL, "RU");
    cout << "Введите выражение (без пробелов): ";
    string expression;
    cin >> expression;
    int position = 0;
    int result = Expressions(expression, position);
    cout << "Результат: " << result << endl;
}