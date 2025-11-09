#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << "++++++++++++++++++++++++++++++++++++++" << endl;

    // Перший рядок — числа від 1 до n
    for (int i = 1; i <= n; i++) {
        cout << setw(6) << i; // ширина поля 6 символів
    }
    cout << endl;

    cout << "++++++++++++++++++++++++++++++++++++++" << endl;

    // Другий рядок — їхні квадратні корені
    cout << fixed; // фіксований формат з десятковими
    for (int i = 1; i <= n; i++) {
        double root = sqrt(i);
        if (fabs(root - int(root)) < 1e-9)
            cout << setw(6) << setprecision(0) << root; // без дробової частини
        else
            cout << setw(6) << setprecision(2) << root; // 2 цифри після коми
    }
    cout << endl;

    cout << "++++++++++++++++++++++++++++++++++++++" << endl;

    return 0;
}
