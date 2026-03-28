#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <fstream>
#include <iterator>
#include <cstdlib>
#include <ctime>
#include "STL5Assoc17.h"
#include "validation.h"

// Функция для проверки состоит ли слово только из заглавных латинских букв
bool isUpperWord(const std::string& word) {
    if (word.empty()) return false;
    for (size_t i = 0; i < word.size(); ++i) {
        if (word[i] < 'A' || word[i] > 'Z') {
            return false;
        }
    }
    return true;
}

void STL5Assoc17() {
    using namespace std;

    srand(static_cast<unsigned>(time(nullptr)));

    vector<string> V;
    int choice;

    cout << "Выберите способ заполнения:\n";
    cout << "1 - С клавиатуры\n";
    cout << "2 - Из файла\n";
    cout << "3 - Случайно\n";
    cout << "Ваш выбор: ";
    choice = Validation::getIntRange(1, 3);

    switch (choice) {
    case 1: {
        cout << "Введите количество слов: ";
        int n = Validation::getIntMin(1);
        cout << "Введите " << n << " слов заглавными латинскими буквами:\n";
        for (int i = 0; i < n; ++i) {
            cout << "Слово " << i + 1 << ": ";
            string word;
            cin >> word;

            while (!isUpperWord(word)) {
                cout << "Ошибка! Введите слово заглавными латинскими буквами (A-Z): ";
                cin >> word;
            }
            V.push_back(word);
        }
        break;
    }
    case 2: {
        while (true) {
            cout << "Введите имя файла: ";
            string filename = Validation::getValidFile();

            ifstream file(filename);
            vector<string> temp;
            string word;
            bool allUpper = true;

            while (file >> word) {
                if (!isUpperWord(word)) {
                    cout << "Ошибка! В файле есть слово, не состоящее из заглавных латинских букв: " << word << endl;
                    allUpper = false;
                    break;
                }
                temp.push_back(word);
            }
            file.close();

            if (!allUpper) {
                cout << "Попробуйте другой файл.\n";
                continue;
            }

            if (temp.empty()) {
                cout << "Ошибка! Файл пуст. Попробуйте снова.\n";
            }
            else {
                V = temp;
                break;
            }
        }
        cout << "Загружено " << V.size() << " слов.\n";
        break;
    }
    case 3: {
        cout << "Введите количество слов: ";
        int n = Validation::getIntMin(1);
        // Случайная генерация уже дает заглавные буквы
        for (int i = 0; i < n; ++i) {
            int len = rand() % 10 + 3;
            string word;
            for (int j = 0; j < len; ++j) {
                word += 'A' + rand() % 26;
            }
            V.push_back(word);
        }
        break;
    }
    }

    if (V.empty()) {
        cout << "Вектор пуст!\n";
        return;
    }

    // Вывод исходного вектора
    cout << "\nИсходные слова: ";
    copy(V.begin(), V.end(), ostream_iterator<string>(cout, " "));
    cout << endl;

    // отображение (буква-ключ, суммарная длина слов-значение)
    map<char, int> M;

    for (vector<string>::iterator it = V.begin(); it != V.end(); it++) {
        M[(*it)[0]] += (*it).size();
    }

    // Вывод результата
    cout << "\nРезультат (буква - суммарная длина):\n";
    for (map<char, int>::iterator it = M.begin(); it != M.end(); it++) {
        cout << (*it).first << " - " << (*it).second << endl;
    }

    cout << "\nНажмите Enter для продолжения...";
    cin.get();
    cin.get();
    system("cls");
}