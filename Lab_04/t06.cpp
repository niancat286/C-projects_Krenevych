#include <stdio.h>
#include <math.h>


//
// Created by Yaroslava Krenevych on 12.09.2025.
//


#include <cstdio>
#include <cmath>

double multy_sqrt(unsigned n) {
    double y = sqrt(2.0);
    for (unsigned i = n; i > 0; i--) {
        y = sqrt(2.0 + y);
    }
    return y;
}


double multy_sqrt_b(unsigned n) {
    double y = sqrt(3.0 * n);
    for (unsigned i = n; i > 0; i--) {
        y = sqrt(3.0 * (i) + y);
    }
    return y;
}



int main() {
    unsigned n;
    printf("Enter number n: \n");
    scanf("%u", &n);
    double x = multy_sqrt(n);
    printf("res = %.10f\n", x); // виводимо з точністю до 10 знаків
    double y = multy_sqrt_b(n);
    printf("res = %.10f\n", y);
    return 0;
}

