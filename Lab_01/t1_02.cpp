//
// Created by Yaroslava Krenevych on 03.09.2025.
//

#include <stdio.h>
#include <math.h>

int main() {
    float x = 10e-4;

    printf("x = %.2lf\n", x); // printf("%.6f\n", x); = 0.001000

    float y = 24.33e5;
    printf("y = %.2lf\n", y);

    double p = M_PI;
    printf("pi = %.2lf\n", p);

    double e = M_E;
    printf("e = %.2lf\n", e);

    double s = sqrt(5);
    printf("sqrt(5) = %.2lf\n", s);

    double log100 = log(100);
    printf("log(100) = %.2lf\n", log100);

    return 0;





}