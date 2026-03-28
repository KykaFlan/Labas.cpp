#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>
#include "STL2Seq3.h"
#include "validation.h"

void STL2Seq3() {
    using namespace std;

    vector<int> v;
    int choice;

    cout << "Выберите способ заполнения:\n";
    cout << "1 - С клавиатуры\n";
    cout << "2 - Из файла\n";
    cout << "3 - Случайно\n";
    cout << "Ваш выбор: ";
    choice = Validation::getIntRange(1, 3);


    switch (choice) {
    case 1: {
        cout << "Введите количество элементов (четное): ";
        int n;
        while (true) {
            n = Validation::getIntMin(2);
            if (n % 2 != 0) {
                cout << "Ошибка! Количество должно быть четным. Попробуйте снова: ";
            }
            else {
                break;
            }
        }
        cout << "Введите " << n << " чисел:\n";
       
        vector<int> temp(n); //Временный вектор
        vector<int>::iterator it;
        int i = 1;
        for (it = temp.begin(); it != temp.end(); it++) {
            cout << "Элемент " << i << ": ";
            int val = Validation::getInt();
            *it = val;
            i++;
        }

        v = temp;  // делаю так, так как temp относится к case1 и после завершения значение temp очищается 
        break;
    }
    case 2: {
        while (true) {
            cout << "Введите имя файла: ";
            string filename = Validation::getValidFile();

            ifstream file(filename);
            vector<int> temp((istream_iterator<int>(file)), istream_iterator<int>());
            file.close();

            if (temp.size() % 2 != 0) {
                cout << "Ошибка! Количество элементов должно быть четным (файл содержит "
                    << temp.size() << " чисел).\n";                
            }
            else {
                v = temp;
                break;
            }
        }
        cout << "Загружено " << v.size() << " чисел.\n";
        break;
    }
    case 3: {
        cout << "Введите количество элементов (четное): ";
        int n;
        while (true) {
            n = Validation::getIntMin(2);
            if (n % 2 != 0) {
                cout << "Ошибка! Количество должно быть четным. Попробуйте снова: ";
            }
            else {
                break;
            }
        }

        vector<int> temp(n);
        vector<int>::iterator it;
        for (it = temp.begin(); it != temp.end(); it++) {
            *it = rand() % 100;
        }
        v = temp;
        break;
    }
    }

    if (v.empty()) {
        cout << "Ошибка! Вектор пуст!\n";
        return;
    }

    cout << "\nИсходный вектор: ";
    vector<int>::iterator it;
    for (it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    vector<int>::iterator mid = v.begin() + (v.size() / 2);

    cout << "Результат: ";    
    for (it = mid; it != v.end(); it++) {
        cout << *it << " ";
    }
    for (it = v.begin(); it != mid; it++) {
        cout << *it << " ";
    }
    cout << endl;

    cout << "\nНажмите Enter для продолжения...";
    cin.get();
    cin.get();

    system("cls");
}