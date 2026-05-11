#include <iostream>
#include <cmath>
#include <Windows.h>

using namespace std;

typedef double (*MathFunc)(double);
extern void printValues(double start, double end, double step, MathFunc f);

int global_n; 

double y_lab(double x) {
    if (x < 0) {
        double res = 0.0;
        for (int i = 1; i <= global_n; i++) {
            for (int j = 1; j <= global_n; j++) {
                res += (1.0 / (x - i - j));
            }
        }
        return res;
    } else {
        double res = 1.0;
        for (int i = 0; i <= global_n - 3; i++) {
            res = res * (-x - i);
        }
        return res;
    }
}

double y_sin(double x) {
    return sin(x);
}

int main() {

    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    double start, end, step;

    cout << "Введіть початок інтервалу: "; cin >> start;
    cout << "Введіть кінець інтервалу: "; cin >> end;
    cout << "Введіть крок: "; cin >> step;
    cout << "Введіть параметр n: "; cin >> global_n;

    cout << "\n--- Таблиця для твоєї функції (Лаб 1) ---" << endl;
    printValues(start, end, step, y_lab);

    cout << "\n--- Таблиця для функції sin(x) ---" << endl;
    printValues(start, end, step, y_sin);

    return 0;
}
