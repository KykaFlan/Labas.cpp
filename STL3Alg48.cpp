#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include "STL3Alg48.h"
#include "validation.h"
class Garbage {
private:
    static int Order(int x) {
        if (x < 0) return 0;
        if (x == 0) return 1;
        return 2;
    }

public:
    bool operator()(int a, int b) const {
        int pa = Order(a);
        int pb = Order(b);

        if (pa != pb) {
            return pa < pb;
        }
        return false;
    }
};

// Функция для ввода и проверки трети
bool inputThird(int NumberIndex, int size, int outputPos, std::vector<int>& V) {
    using namespace std;
    cout << "\nВвод " << NumberIndex << "-й трети (элементы " << outputPos + 1 << "-" << outputPos + size << ") ---\n";

    while (true) {
        cout << "Введите " << size << " чисел, отсортированных по возрастанию:\n";
        vector<int> temp(size);

        for (int i = 0; i < size; ++i) {
            cout << "Элемент " << outputPos + i + 1 << ": ";
            temp[i] = Validation::getInt();
        }

        // Проверка на отсортированность
        bool sorted = true;
        for (int i = 0; i < size - 1; ++i) {
            if (temp[i] > temp[i + 1]) {
                sorted = false;
                break;
            }
        }

        if (sorted) {
            copy(temp.begin(), temp.end(), V.begin() + outputPos);
            return true;
        }
        else {
            cout << "Ошибка! Числа должны быть отсортированы по возрастанию. Попробуйте снова.\n";
        }
    }
}
// Функция проверки файла
bool validateFile(const std::string& filename, std::vector<int>& V, int& thirdSize) {
    using namespace std;

    ifstream file(filename);
    if (!file) {
        cout << "Не удалось открыть файл.\n";
        return false;
    }

    vector<int> temp((istream_iterator<int>(file)), istream_iterator<int>());
    file.close();

    if (temp.size() % 3 != 0) {
        cout << "Ошибка! Количество элементов должно быть кратно 3. Файл содержит "
            << temp.size() << " чисел.\n";
        return false;
    }

    thirdSize = temp.size() / 3;

    // Проверка всех трех третей
    // Проверка первой трети
    for (int i = 0; i < thirdSize - 1; ++i) {
        if (temp[i] > temp[i + 1]) {
            cout << "Ошибка! Первая треть файла не отсортирована.\n";
            return false;
        }
    }

    // Проверка второй трети
    for (int i = thirdSize; i < 2 * thirdSize - 1; ++i) {
        if (temp[i] > temp[i + 1]) {
            cout << "Ошибка! Вторая треть файла не отсортирована.\n";
            return false;
        }
    }

    // Проверка третьей трети
    for (int i = 2 * thirdSize; i < (int)temp.size() - 1; ++i) {
        if (temp[i] > temp[i + 1]) {
            cout << "Ошибка! Третья треть файла не отсортирована.\n";
            return false;
        }
    }

    V = temp;
    return true;
}

void STL3Alg48() {
    using namespace std;

    vector<int> V;
    int choice;

    cout << "Выберите способ заполнения:\n";
    cout << "1 - С клавиатуры\n";
    cout << "2 - Из файла\n";
    cout << "3 - Случайно\n";
    cout << "Ваш выбор: ";
    choice = Validation::getIntRange(1, 3);

    int thirdSize = 0;

    switch (choice) {
    case 1: {
        cout << "Введите количество элементов (кратно 3): ";
        int n;
        while (true) {
            n = Validation::getIntMin(3);
            if (n % 3 != 0) {
                cout << "Ошибка! Количество должно быть кратно 3. Попробуйте снова: ";
            }
            else {
                break;
            }
        }
        thirdSize = n / 3;
        V.resize(n);

        // Ввод трех третей через функцию
        inputThird(1, thirdSize, 0, V);
        inputThird(2, thirdSize, thirdSize, V);
        inputThird(3, thirdSize, 2 * thirdSize, V);
        break;
    }
    case 2: {
        while (true) {
            cout << "Введите имя файла: ";
            string filename = Validation::getValidFile();

            if (validateFile(filename, V, thirdSize)) {
                break;
            }
            else {
                cout << "Попробуйте другой файл.\n\n";
            }
        }
        break;
    }
    case 3: {
        cout << "Введите количество элементов (кратно 3): ";
        int n;
        while (true) {
            n = Validation::getIntMin(3);
            if (n % 3 != 0) {
                cout << "Ошибка! Количество должно быть кратно 3. Попробуйте снова: ";
            }
            else {
                break;
            }
        }
        thirdSize = n / 3;

        // Генерируем три отсортированные части
        V.resize(n);
        for (int i = 0; i < thirdSize; i++) {
            V[i] = rand() % 100;
        }
        sort(V.begin(), V.begin() + thirdSize);

        for (int i = thirdSize; i < 2 * thirdSize; i++) {
            V[i] = rand() % 100;
        }
        sort(V.begin() + thirdSize, V.begin() + 2 * thirdSize);

        for (int i = 2 * thirdSize; i < n; i++) {
            V[i] = rand() % 100;
        }
        sort(V.begin() + 2 * thirdSize, V.end());
        break;
    }
    }

    if (V.empty()) {
        cout << "Вектор пуст!\n";
        return;
    }

    // Вывод исходного вектора
    cout << "\nИсходный вектор (каждая треть отсортирована): ";
    copy(V.begin(), V.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    Garbage T;

    // Первый вызов inplace_merge: сливаем 1-ю и 2-ю треть
    inplace_merge(V.begin(), V.begin() + thirdSize, V.begin() + 2 * thirdSize, T);

    cout << "После первого inplace_merge (отрицательные + нули): ";
    copy(V.begin(), V.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    // Второй вызов inplace_merge: сливаем результат с 3-й третью
    inplace_merge(V.begin(), V.begin() + 2 * thirdSize, V.end(), T);

    cout << "После второго inplace_merge (добавили положительные): ";
    copy(V.begin(), V.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    cout << "\nНажмите Enter для продолжения...";
    cin.get();
    cin.get();
    system("cls");
}