#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "HomeDyn3.h"


void Solve(std::vector<std::vector<int>>& Board, std::vector<std::vector<int>>& Dynamics, std::string& KingsWay) {
    using namespace std;
    int n = Board.size();
    // Массив для записи направлений
    vector<vector<char>> Direction(n, vector<char>(n, ' '));

    Dynamics[n - 1][n - 1] = Board[n - 1][n - 1];
    Direction[n - 1][n - 1] = ' ';

    // Идём только влево
    for (int j = n - 2; j >= 0; j--) {
        Dynamics[n - 1][j] = Dynamics[n - 1][j + 1] + Board[n - 1][j];
        Direction[n - 1][j] = 'L';
    }
    // Идём только вверх
    for (int i = n - 2; i >= 0; i--) {
        Dynamics[i][n - 1] = Dynamics[i + 1][n - 1] + Board[i][n - 1];
        Direction[i][n - 1] = 'U';
    }
    // Алгоритм через Максимальное. как в иксэле 18 егэ
    for (int i = n - 2; i >= 0; i--) {
        for (int j = n - 2; j >= 0; j--) {
            if (Dynamics[i + 1][j] > Dynamics[i][j + 1]) {
                Dynamics[i][j] = Dynamics[i + 1][j] + Board[i][j];
                Direction[i][j] = 'U';
            }
            else {
                Dynamics[i][j] = Dynamics[i][j + 1] + Board[i][j];
                Direction[i][j] = 'L';
            }
        }
    }
    int i = 0, j = 0;

    // Путь от конца в начало нахожу. А сохраняет так как шёл король.
    while (i != n-1 ||  j != n-1) {
        if (Direction[i][j] == 'L') {
            KingsWay = 'L' + KingsWay;
            j++;
        }
        else {
            KingsWay = 'U' + KingsWay;
            i++;
        }
    }
}

void HomeDyn3() {
    using namespace std;
	setlocale(LC_ALL, "RU");
    // Открывает файл для ввода данных
	ifstream FileInt("HomeDyn3Input.txt");
	string line;
    // Вывод того что в файле
	while (getline(FileInt, line)) {
		cout << line << endl;
	}
    // Возвращаемся в начало файла
	FileInt.clear();    
	FileInt.seekg(0, ios::beg);

	int N;
	FileInt >> N;
    // создаём векторные массивы Доски и Динамики
	vector<vector<int>> Board(N, vector<int>(N));
    vector<vector<int>> Dynamics(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			FileInt >> Board[i][j];
		}
	}
	FileInt.close();

    string KingsWay = "";
    //вызываем функцию, где будем получать максимальное число и путь
    Solve(Board, Dynamics, KingsWay);

    // Открываем файл для записи ответа 
    ofstream FileOut("HomeDyn3Output.txt");
    FileOut << "Максимальная сумма: " << Dynamics[0][0] << endl;
    FileOut << "Путь: " << KingsWay;
    FileOut.close();

    cout << "Максимальная сумма: " << Dynamics[0][0] << endl;
    cout << "Путь: " << KingsWay << endl;
}