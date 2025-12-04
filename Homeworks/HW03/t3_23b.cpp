#include <stdio.h>
#include <math.h>


double ReLU(double x) {
    if (x > 0) return x;
    else return 0.0;
}


double dReLU(double x) {
    if (x > 0) return 1.0;
    else if (x < 0) return 0.0;
    else return 0.0; // похідна в 0 умовно = 0
}


int main() {
    double x;
    printf("Введіть x: ");
    scanf("%lf", &x);
    printf("ReLU(%lf) = %lf\n", x, ReLU(x));
    printf("ReLU'(%lf) = %lf\n", x, dReLU(x));

    return 0;
}
