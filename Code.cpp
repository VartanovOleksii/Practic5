#include <iostream>
#include <math.h>
#include <windows.h>

using namespace std;

int main()
{
    double x, eps;
    double sum_n;
    double sum_eps;
    double c;
    int n;
    char repeat;


    SetConsoleOutputCP(1251);

    do {
        //Перевірка коректності даних
        do {
            cout << "Введіть x -> ";
            cin >> x;

            if (x <= 0 || x >= 1) {
                cout << "Змінна x поза діапазоном." << '\n';
            }
        } while (x <= 0 || x >= 1);

        cout << "x = " << x << '\n';


        //Перевірка коректності даних
        do {
            cout << "Введіть n -> ";
            cin >> n;

            if (n <= 0) {
                cout << "Змінна n поза діапазоном." << '\n';
            }
        } while (n <= 0);

        cout << "n = " << n << '\n';


        //Перевірка коректності даних
        do {
            cout << "Введіть точність -> ";
            cin >> eps;

            if (eps <= 0 || eps >= 1) {
                cout << "Точність поза діапазоном." << '\n';
            }
        } while (eps <= 0 || eps >= 1);

        cout << "Точність = " << eps << '\n';


        double numerator = x;
        double denominator = 6;
        int i = 1;

        double fraction;

        fraction = numerator / denominator;
        sum_eps = 0;


        //Розрахунок суми через точніть
        while (abs(fraction) >= eps) {
            sum_eps += fraction;
            numerator *= (-1) * x * x;
            i++;
            denominator *= (2 * i) * (2 * i + 1);
            fraction = numerator / denominator;
        }

        sum_eps += fraction;


        fraction = x / 6;
        sum_n = fraction;

        //Розрахунок суми через кількість
        if (n != 1) {
            for (int i = 2; i <= n; i++) {
                fraction *= ((-1) * x * x) / (4 * i * i + 2 * i);
                sum_n += fraction;
            }
        }

        c = (x - sin(x)) / (x * x);

        cout << "Сума через точність: " << sum_eps << '\n';
        cout << "Сума через кількість: " << sum_n << '\n';
        cout << "Контроль: " << c << '\n';

        cout << '\n';

        cout << "Повторити? (y - так, n - ні) " << '\n';
        cin >> repeat;
        cout << '\n';
    } while (repeat == 'y');

    return 0;
}
