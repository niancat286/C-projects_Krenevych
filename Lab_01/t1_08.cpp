#include <stdio.h>

int main() {
    double a, b;

    printf("a = ");
    scanf("%lf", &a);
    printf("b = ");
    scanf("%lf", &b);

    double diff = a - b;
    double prod = a * b;

    printf("Різниця: %.2f\n", diff);
    printf("Добуток: %.2f\n", prod);

    return 0;
}