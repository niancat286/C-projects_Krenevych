#include <stdio.h>
#include <math.h>


int main() {
    double t;
    printf("Введіть дійсне число t: ");
    scanf("%lf", &t);

    // 1. Ціла частина без функцій
    int int_part_manual = (int)t;  // автоматично відкидає дробову частину
    if (t < 0 && t != int_part_manual) int_part_manual--; // для від'ємних коректно з математичного боку

    // 2. Дробова частина без функцій
    double frac_part_manual = t - (double)int_part_manual;

    // 3. Ціла частина за допомогою функцій
    double int_part_func = trunc(t);       // відкидає дробову частину
    double frac_part_func = t - int_part_func;

    // 4. Найменше ціле, що більше t
    double ceil_t = ceil(t);

    // 5. Найбільше ціле, що менше t
    double floor_t = floor(t);

    // 6. Округлене значення
    double round_t = round(t);

    // Вивід
    printf("\n--- Результати ---\n");
    printf("Ціла частина (без функцій): %d\n", int_part_manual);
    printf("Дробова частина (без функцій): %f\n", frac_part_manual);
    printf("Ціла частина (trunc): %.0f\n", int_part_func);
    printf("Дробова частина (trunc): %f\n", frac_part_func);
    printf("Найменше ціле > t (ceil): %.0f\n", ceil_t);
    printf("Найбільше ціле < t (floor): %.0f\n", floor_t);
    printf("Округлене значення (round): %.0f\n", round_t);

    return 0;
}
