#include <stdio.h>
#include <math.h>

int main() {
    double x;

    printf("Введіть дійсне число x: ");
    scanf("%lf", &x);

    double cos_x = cos(x);

    printf("cos(%.6f) = %.6f\n", x, cos_x);

    return 0;
}

//remake
