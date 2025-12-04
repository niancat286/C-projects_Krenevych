//
// Created by Yaroslava Krenevych on 12.09.2025.
//


#include <stdio.h>
#include <math.h>


int main() {
    double x, y;
    unsigned n;
    printf("Enter number x: ");
    scanf("%lf", &x);
    printf("Enter number n: ");
    scanf("%u", &n);

    y = x;

    for (unsigned i = 0; i < n; i++) {
        y = sin(y);
    }

    printf("y = %lf\n", y);
}















