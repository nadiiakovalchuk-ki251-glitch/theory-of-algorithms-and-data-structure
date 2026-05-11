#include <iostream>

using namespace std;

typedef double (*MathFunc)(double);

void printValues(double start, double end, double step, MathFunc f) {
    for (double x = start; x <= end + (step / 10); x += step) {
        cout << "x: " << x << " \t y: " << f(x) << endl;
    }
}
