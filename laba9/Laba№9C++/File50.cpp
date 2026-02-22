#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

void File50() {
    using namespace std;
    setlocale(LC_ALL, "RU");
    string S1, S2, S3;
    cout << "Введите имя первого файла (S1): ";
    cin >> S1;
    cout << "Введите имя второго файла (S2): ";
    cin >> S2;
    cout << "Введите имя результирующего файла (S3): ";
    cin >> S3;

    // Читаем первый файл
    ifstream File1(S1, ios::binary);
    if (!File1) {
        cout << "Ошибка: файл '" << S1 << "' не найден!" << endl;
        return;
    }

    double number1;
    cout << "Содержимое файла " << S1 << ": ";
    while (File1.read((char*)&number1, sizeof(double))) {
        cout << number1 << "; ";
    }
    cout << endl;
    // Возвращаемся в начало файла
    File1.clear();
    File1.seekg(0, ios::beg);

    // Читаем второй файл
    ifstream File2(S2, ios::binary);
    if (!File2) {
        cout << "Ошибка: файл '" << S2 << "' не найден!" << endl;
        return;
    }
    double number2;
    cout << "Содержимое файла " << S2 << ": ";
    while (File2.read((char*)&number2, sizeof(double))) {
        cout << number2 << "; ";
    }
    cout << endl;
    // Возвращаемся в начало файла
    File2.clear();
    File2.seekg(0, ios::beg);

    // Сортируем
    ofstream File3Out(S3, ios::binary);
    File1.read((char*)&number1, sizeof(double));
    File2.read((char*)&number2, sizeof(double));
    while (File1 && File2) {
        if (number1 <= number2) {
            File3Out.write((char*)&number1, sizeof(double));
            File1.read((char*)&number1, sizeof(double));
        }
        else {
            File3Out.write((char*)&number2, sizeof(double));
            File2.read((char*)&number2, sizeof(double));
        }
    }
    while (File1) {
        File3Out.write((char*)&number1, sizeof(double));
        File1.read((char*)&number1, sizeof(double));
    }
    while (File2) {
        File3Out.write((char*)&number2, sizeof(double));
        File2.read((char*)&number2, sizeof(double));
    }
    File1.close();
    File2.close();
    File3Out.close();

    ifstream File3C(S3, ios::binary);
    cout << "\nРезультат в файле " << S3 << ": ";
    double i;
    while (File3C.read((char*)&i, sizeof(double))) {
        cout << i << "; ";
    }
    cout << endl;

}
