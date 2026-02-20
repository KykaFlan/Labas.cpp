#include <iostream>
#include <limits>
#include <fstream>
#include <vector>
#include <string>
#include <cctype>
#include "File8.h"
#include "File31.h"
#include "File50.h"
#include "Recur17.h"
void CreateFile() {
    using namespace std;
    string NameFile;
    cout << "Введите имя для файла и его разрешение .bin или .txt: ";
    cin >> NameFile;
    ofstream File(NameFile, ios::binary);

    if (!File) {
        cout << "Ошибка при создании файла!" << endl;
        return;
    }

    cout << "Если нужно заполнить массив числами, введите 1, иначе 0: ";
    int N;
    while (true) {
        cin >> N;
        if (cin.fail()) {
            cout << "Ошибка: необходимо ввести целое число!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Повторите ввод (1 или 0): ";
        }
        else if (N != 0 && N != 1) {
            cout << "Введите либо 1, либо 0: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
    }

    if (N == 1) {
        cout << "Выберите тип чисел:\n";
        cout << "1 - Целые (int)\n";
        cout << "2 - Вещественные (double)\n";
        cout << "Ваш выбор: ";

        int typeChoice;
        while (true) {
            cin >> typeChoice;
            if (cin.fail()) {
                cout << "Ошибка: необходимо ввести целое число!\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Повторите ввод (1 или 2): ";
            }
            else if (typeChoice != 1 && typeChoice != 2) {
                cout << "Введите либо 1, либо 2: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
        }

        cout << "Сколько чисел вы хотите вписать?: ";
        int n;
        while (true) {
            cin >> n;
            if (cin.fail()) {
                cout << "Ошибка: необходимо ввести целое число!\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Повторите ввод: ";
            }
            else if (n <= 0) {
                cout << "Введите число > 0: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
        }

        cout << "Введите число(а), которое(ые) вы хотите вписать в файл:\n";

        if (typeChoice == 1) {
            vector<int> data(n);
            for (int i = 0; i < n; i++) {
                int write;
                cout << "Число №" << i + 1 << " (целое): ";
                while (true) {
                    cin >> write;
                    if (cin.fail()) {
                        cout << "Ошибка: необходимо ввести целое число!\n";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Повторите ввод: ";
                    }
                    else {
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        break;
                    }
                }
                data[i] = write;
            }
            File.write(reinterpret_cast<char*>(data.data()), n * sizeof(int));

            cout << "Файл успешно создан! Записано " << n << " целых чисел." << endl;
            cout << "Записанные числа: ";
            for (int i = 0; i < n; i++) {
                cout << data[i];
                if (i < n - 1) cout << " => ";
            }
        }
        else {
            vector<double> data(n);
            for (int i = 0; i < n; i++) {
                double write;
                cout << "Число №" << i + 1 << " (вещественное): ";
                while (true) {
                    cin >> write;
                    if (cin.fail()) {
                        cout << "Ошибка: необходимо ввести вещественное число!\n";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Повторите ввод: ";
                    }
                    else {
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        break;
                    }
                }
                data[i] = write;
            }
            File.write(reinterpret_cast<char*>(data.data()), n * sizeof(double));

            cout << "Файл успешно создан! Записано " << n << " вещественных чисел." << endl;
            cout << "Записанные числа: ";
            for (int i = 0; i < n; i++) {
                cout << data[i];
                if (i < n - 1) cout << " => ";
            }
        }

        File.close();
        cout << endl;
    }
    else {
        cout << "Файл создан пустым." << endl;
        File.close();
        return;
    }
}

int main()
{
    using namespace std;
    setlocale(LC_ALL, "RU");
    int Task_number;    
    do {
        cout << "Введите номер задания\n";
        cout << "1 - File8; 2 - File31;  3 - File50; 4 - Recur17; 0 - для выхода или \n";
        cout << "777 - для создания файла bin и заполнения его для задачи : ";
        while (true) { 
            cin >> Task_number;
            if (cin.fail()) {
                cout << "Ошибка: необходимо ввести целое число!\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Повторите ввод: ";
            }
            else if ((Task_number < 0 || Task_number > 4) && Task_number != 777) {
                cout << "Ошибка: число должно быть от 0 до 4!\n";
                cout << "Повторите ввод: ";
            }
            else {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // очищаем буфер для последующих вводов
                break;
            }
        }
        if (Task_number == 1) File8();
        if (Task_number == 2) File31();
        if (Task_number == 3) File50();
        if (Task_number == 4) Recur17();
        if (Task_number == 777) CreateFile();
    } while (Task_number != 0);
    cout << "\nПрограмма завершена\nДо свидания!";
    return 0;
}
