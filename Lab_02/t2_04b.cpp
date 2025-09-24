#include <stdio.h>

int main() {
    double x;
    printf("x: ");
    scanf("%lf", &x);
    double y = (((x + 1) * x + 1) * x + 1) * x + 1;
    printf("y = %.6f\n", y);
    return 0;
}