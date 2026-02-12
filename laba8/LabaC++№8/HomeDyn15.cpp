#include <iostream>
#include <iomanip> // Использование fixed и setprecision
#include "HomeDyn15.h"

void HomeDyn15() {
    using namespace std;
    int K, N;

    cout << "Введите основание системы счисления K (2-10): ";
    cin >> K;
    while (K < 2 || K > 10) {
        cout << "ОШИБКА! K должно быть от 2 до 10. Повторите ввод: ";
        cin >> K;
    }

    cout << "Введите количество разрядов N (2-19, N+K < 26): ";
    cin >> N;
    while (N <= 1 || N >= 20 || N + K >= 26) {
        if (N <= 1 || N >= 20) {
            cout << "Ошибка! N должно быть от 2 до 19. Повторите ввод: ";
        }
        else {
            cout << "Ошибка! N + K должно быть < 26. Повторите ввод: ";
        }
        cin >> N;
    }

    double Number_End0 = K - 1;
    double Number_End1 = 0;
    double Number_End2 = 0;
    double Number_End3 = 0;

    // основное решение
    for (int len = 2; len <= N; len++) {
        double New_Number_End0 = (Number_End0 + Number_End1 + Number_End2 + Number_End3) * (K - 1);
        double New_Number_End1 = Number_End0;
        double New_Number_End2 = Number_End1;
        double New_Number_End3 = Number_End2;

        Number_End0 = New_Number_End0;
        Number_End1 = New_Number_End1;
        Number_End2 = New_Number_End2;
        Number_End3 = New_Number_End3;
    }
    
    double result = Number_End0 + Number_End1 + Number_End2 + Number_End3;

    cout << "Результат:" << endl;
    cout << "Количество " << N << "-значных " << K << "-ичных чисел" << endl;
    cout << "без более чем трёх нулей подряд: ";
    cout << fixed << setprecision(0) << result << endl;
}
