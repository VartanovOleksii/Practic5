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
        //�������� ���������� �����
        do {
            cout << "������ x -> ";
            cin >> x;

            if (x <= 0 || x >= 1) {
                cout << "����� x ���� ���������." << '\n';
            }
        } while (x <= 0 || x >= 1);

        cout << "x = " << x << '\n';


        //�������� ���������� �����
        do {
            cout << "������ n -> ";
            cin >> n;

            if (n <= 0) {
                cout << "����� n ���� ���������." << '\n';
            }
        } while (n <= 0);

        cout << "n = " << n << '\n';


        //�������� ���������� �����
        do {
            cout << "������ ������� -> ";
            cin >> eps;

            if (eps <= 0 || eps >= 1) {
                cout << "������� ���� ���������." << '\n';
            }
        } while (eps <= 0 || eps >= 1);

        cout << "������� = " << eps << '\n';


        double numerator = x;
        double denominator = 6;
        int i = 1;

        double fraction;

        fraction = numerator / denominator;
        sum_eps = 0;


        //���������� ���� ����� ������
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

        //���������� ���� ����� �������
        if (n != 1) {
            for (int i = 2; i <= n; i++) {
                fraction *= ((-1) * x * x) / (4 * i * i + 2 * i);
                sum_n += fraction;
            }
        }

        c = (x - sin(x)) / (x * x);

        cout << "���� ����� �������: " << sum_eps << '\n';
        cout << "���� ����� �������: " << sum_n << '\n';
        cout << "��������: " << c << '\n';

        cout << '\n';

        cout << "���������? (y - ���, n - �) " << '\n';
        cin >> repeat;
        cout << '\n';
    } while (repeat == 'y');

    return 0;
}
