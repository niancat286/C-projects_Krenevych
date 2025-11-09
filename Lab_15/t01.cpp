#include "Rational.h"
#include <iostream>
#include <cmath>
using namespace std;

void test_input() {
    Rational r;
    if (r.input_rational()) {
        cout << "You entered" << endl;
        r.output_rational();
    }
}

void test_add_rational() {
    Rational r1 = {1, 2};
    Rational r2 = {1, 3};
    Rational r3 = r1.rational_add(r2);
    Rational expected = {5, 6};

    printf("Sum of ");
    r1.output_rational();
    printf(" + ");
    r2.output_rational();
    printf(" = ");
    r3.output_rational();

    if (!r3.rational_equal(expected)) {
        cout << "Rational addition failed" << endl;
    } else {
        cout << "Rational addition correct" << endl;
    }

    cout << "test new operators" << endl;
    Rational r4 = {1, 2};
    Rational r5 = {1, 3};
    Rational r6 = r4 + r5;
    r6.output_rational();

    cout << r6 << endl;
    Rational r7;

    cin >> r7;
    cout << r7 << endl;
}

int main() {
    int n;
    cout << "Enter number of rational numbers: ";
    cin >> n;

    Rational* arr = new Rational[n];

    cout << "Enter rationals (numerator denominator):" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // ===== find minimum =====
    Rational mn = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < mn) {
            mn = arr[i];
        }
    }

    cout << "Smallest rational: " << mn << endl;

    // ===== compute series with precision 0.01 =====
    double sum = 0.0;
    double term;
    int k = 1;

    do {
        term = pow(-1, k + 1) / (double)(k * k);
        sum += term;
        k++;
    } while (fabs(term) > 0.01);

    cout << "Computed sum (precision 0.01): " << sum << endl;

    // ===== theoretical limit =====
    double limit = (M_PI * M_PI) / 12.0;
    cout << "Target value pi^2/12 = " << limit << endl;

    // ===== check convergence =====
    if (fabs(limit - sum) < 0.05) {
        cout << "Series converges to the target value" << endl;
    } else {
        cout << "Series does NOT converge accurately enough" << endl;
    }

    delete[] arr;
    return 0;
}
