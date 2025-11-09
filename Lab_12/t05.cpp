#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;

const string inpfile = "input.txt";

int main() {
    ifstream infile(inpfile);

    if (!infile) {
        cerr << "Error: cannot open input file.\n";
        return -1;
    }

    // приблизно 16000 чисел у 128 КБ -> беремо запас
    const int MAXN = 20000;
    unsigned long long* a = new unsigned long long[MAXN];
    int n = 0;

    // читаємо поки можемо
    while (infile >> a[n]) {
        n++;
        if (n >= MAXN) break;
    }

    infile.close();

    cout << fixed << setprecision(3);

    // виводимо назад
    for (int i = n - 1; i >= 0; i--) {
        cout << sqrt((double)a[i]) << "\n";
    }

    delete[] a;
    return 0;
}