#include <stdio.h>

int main() {
    double a;      // задане дійсне число
    double sum = 0.0;
    int n = 0;

    printf("Введіть число a: ");
    scanf("%lf", &a);

    // а) знайти перше число 1 + 1/2 + ... + 1/n, більше за a
    while (sum <= a) {
        n++;
        sum += 1.0 / n;
    }

    printf("a) Перше число, більше за %.6f, дорівнює %.6f\n", a, sum);

    // б) знайти найменше n > 0, для якого 1 + 1/2 + ... + 1/n > a
    printf("б) Найменше n, для якого сума > %.6f, це n = %d\n", a, n);

    return 0;
}