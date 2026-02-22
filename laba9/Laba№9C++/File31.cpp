#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "File31.h"

void File31() {
	using namespace std;
	setlocale(LC_ALL, "RU");
	string NameFile;
	cout << "Введите имя файла c .bin: ";
	cin >> NameFile;
	ifstream File(NameFile,ios::binary);
	if (!File) {
		cout << "Ошибка: файл '" << NameFile << "' не найден!" << endl;
		return;
	}

	cout << "\nСодержимое файла " << NameFile << ":" << endl;
	int number;
	int count = 0;
	while (File.read((char*)&number, sizeof(int))) {
		cout << number << "; ";
		count++;
	}
	cout << endl << endl;

	// Возвращаемся в начало файла
	File.clear();
	File.seekg(0, ios::beg);

	cout << "В файле содержится " << count << " элементов." << endl;
	if (count <= 50) {
		cout << "Ошибка: в файле должно быть более 50 элементов" << endl;
		File.close();
		return;
	}

	int QuantityFirstNumbers = count - 50;
	cout << "Нужно удалить " << QuantityFirstNumbers << " начальных элементов." << endl;

	vector<int> RemainingNumbers(50);
	// Пропускаем элементы, которые нужно удалить и записываем оставшиеся 50
	File.seekg(QuantityFirstNumbers * sizeof(int), ios::beg);
	File.read((char*)RemainingNumbers.data(), 50 * sizeof(int));

	// Закрываем файл и открываем уже с ios::trunc, который предварительно очищает файл для перезаписи 
	File.close();
	ofstream FileOut(NameFile, ios::binary | ios::trunc);
	if (!FileOut) {
		cout << "Ошибка: не удалось перезаписать файл!" << endl;
		return;
	}

	FileOut.write((char*)RemainingNumbers.data(), 50 * sizeof(int));
	FileOut.close();
	cout << endl;
	cout << " Было удалено: " << QuantityFirstNumbers << " начальных элементов" << endl;
	cout << " Теперь файл содержит 50 элементов:" << endl;
	cout << endl;
	FileOut.close();
	cout << " ";
	ifstream FileO(NameFile, ios::binary);
	while (FileO.read((char*)&number, sizeof(int))) {
		cout << number << "; ";

	}
}
