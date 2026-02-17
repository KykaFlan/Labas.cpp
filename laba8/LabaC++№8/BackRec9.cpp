#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

void BackRec9() {
    using namespace std;
    setlocale(LC_ALL, "RU");
    // Вывод того что в файле
    ifstream File("BackRec9.txt");
    string line;
    while (getline(File, line)) {
        cout << line << endl;
    }
    // Возвращаемся в начало файла чтобы снова прочитать его
    File.clear();
    File.seekg(0, ios::beg);
    // запись данных в переменнные и масивы
    int N, B;
    File >> N >> B;
    vector<int> Weight(N + 1), Volume(N + 1);
    for (int i = 1; i <= N; i++) {
        File >> Weight[i];
    }
    for (int i = 1; i <= N; i++) {
        File >> Volume[i];
    }
    File.close();

    // количество артефактов для первых i артефактов с весом w
    vector<vector<int>> Dynamics(N + 1, vector<int>(B + 1, -1));
    Dynamics[0][0] = 0;
    // Массив для восстановления ответа
    vector<vector<bool>> Used(N + 1, vector<bool>(B + 1, false));

    for (int i = 1; i <= N; i++) {
        for (int w = 0; w <= B; w++) {
            // Проверяем можно ли набрать вес из предыдущих артефактов
            if (Dynamics[i - 1][w] != -1) {
                if (Dynamics[i][w] < Dynamics[i - 1][w]) {
                    Dynamics[i][w] = Dynamics[i - 1][w];
                    Used[i][w] = false;
                }
            }
            // какой вес был до добавления iтого артефакта
            int Remains = w - Weight[i];
            // Проверяем не привышает ли вес iтого артефакта и можно ли было набрать вес iтого артефакта из предыдущих артефактов 
            if (Remains >= 0 && Dynamics[i - 1][Remains] != -1) {
                Dynamics[i][w] = Dynamics[i - 1][Remains] + 1;
                Used[i][w] = true;
            }
        }
    }

    // Поиск наилучшего решения
    int MaxWeight = 0;
    int MaxQuantity = 0;
    for (int w = B; w >= 0; w--) {
        if (Dynamics[N][w] != -1) {
            MaxWeight = w;
            MaxQuantity = Dynamics[N][w];
            break;
        }
    }

    // Восстановление ответа
    vector<int> ArtifactNumber;
    int CheckWeight = MaxWeight;
    int totalVolume = 0;
    for (int i = N; i > 0; i--) {
        if (Used[i][CheckWeight]) {
            ArtifactNumber.push_back(i);
            totalVolume += Volume[i];
            CheckWeight -= Weight[i];
        }
    }

    cout << "Выбранные артефакты (номера): ";
    for (int i = ArtifactNumber.size() - 1; i >= 0; i--) {
        cout << ArtifactNumber[i] << " ";
    }
    cout << endl;
    cout << "Суммарный вес: " << MaxWeight  << endl;
    cout << "Суммарный объем: " << totalVolume  << endl;
}
