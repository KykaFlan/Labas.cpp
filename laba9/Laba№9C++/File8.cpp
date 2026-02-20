#include <iostream>
#include <fstream>
#include <string>
#include "File8.h"


void File8() {
    setlocale(LC_ALL, "RU");
    using namespace std;
    string ExistingFile, CreateFile;
    cout << "Введите имя существующего файла: ";
    cin >> ExistingFile;
    cout << "Введите имя нового файла: ";
    cin >> CreateFile;

    // Открываем существующий файл.bin  для чтения
    ifstream File1(ExistingFile, ios::binary);
    if (!File1) {
        cout << "Файл не найден!" << endl;
        return;
    }
    cout << "\nСодержимое файла " << ExistingFile << ":" << endl;
    double number;
    while (File1.read((char*)&number, sizeof(double))) {
        cout << number << "; ";
    }
    cout << endl << endl;

    // Возвращаемся в начало файла
    File1.clear();
    File1.seekg(0, ios::beg);

    double first, last;

    // Читаем первый элемент
    File1.read((char*)&first, sizeof(double));

    // Читаем последний элемент
    File1.seekg(-8, ios::end);
    File1.read((char*)&last, sizeof(double));
    File1.close();

    // Создаем новый файл и записываем первое и последнее число
    ofstream File2(CreateFile, ios::binary);
    File2.write((char*)&first, sizeof(double));
    File2.write((char*)&last, sizeof(double));
    File2.close();

    cout << "Из файла " << ExistingFile << " прочитано:" << endl;
    cout << "первый: " << first << endl;
    cout << "последний: " << last << endl;
}