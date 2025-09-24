#include <stdio.h>


int main() {
    double a, b;

    printf("Введіть два дійсних числа через пробіл: ");
    scanf("%lf %lf", &a, &b);

    double avg_arith = (a + b) / 2.0;
    double avg_harm = 2.0 / (1.0/a + 1.0/b);

    printf("\n--- Середнє арифметичне ---\n");
    printf("Десяткове: %.6f\n", avg_arith);
    printf("Наукове: %.6e\n", avg_arith);

    printf("\n--- Середнє гармонічне ---\n");
    printf("Десяткове: %.6f\n", avg_harm);
    printf("Наукове: %.6e\n", avg_harm);

    return 0;
}